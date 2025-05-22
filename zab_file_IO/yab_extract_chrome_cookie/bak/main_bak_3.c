#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>
#include <shlobj.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/err.h>
#include <unistd.h>   // for getcwd

unsigned char *base64_decode(const char *input, int length, int *out_len); // Base64 解码
int decrypt_aes_key(const unsigned char *enc_key, int enc_key_len, unsigned char *out_key, DWORD *out_key_len); //解密 Local State 中的 AES key 
int aes_gcm_decrypt(const unsigned char *key, int key_len,
                    const unsigned char *iv, int iv_len,
                    const unsigned char *ciphertext, int ciphertext_len,
                    const unsigned char *tag, int tag_len,
                    unsigned char *plaintext, int *plaintext_len); // ===== AES-GCM 解密
int get_chrome_aes_key(unsigned char *out_key, DWORD *out_key_len); // ===== 读取 Local State 文件，提取和解密 AES key
int copy_file(const char *src, const char *dest); // ===== 复制文件 =====

// ===== 读取 Local State 文件，提取和解密 AES key =====
int get_chrome_aes_key(unsigned char *out_key, DWORD *out_key_len) 
{
    char local_app_data[MAX_PATH];
    char local_state_path[MAX_PATH];
    FILE *fp;
    long file_size;
    char *json_buf;
    char *p_start, *p_end;
    char base64_key[512] = {0};
    int base64_len;

    if (!GetEnvironmentVariableA("LOCALAPPDATA", local_app_data, MAX_PATH)) {
        fprintf(stderr, "无法获取 LOCALAPPDATA 环境变量\n");
        return 0;
    }

    snprintf(local_state_path, MAX_PATH,
             "%s\\Google\\Chrome\\User Data\\Local State", local_app_data);

    fp = fopen(local_state_path, "rb");
    if (!fp) {
        fprintf(stderr, "无法打开 Local State 文件: %s\n", local_state_path);
        return 0;
    }

    printf("Local State path: %s\n", local_state_path); //C:\Users\yan\AppData\Local\Google\Chrome\User Data\Local State

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    json_buf = (char *)malloc(file_size + 1);
	printf("get_chrome_aes_key(): 'Local State' filesiez: %d\n", file_size);  //////////////////////////////////////////////////////
    if (!json_buf) {
        fclose(fp);
        fprintf(stderr, "内存分配失败\n");
        return 0;
    }

    fread(json_buf, 1, file_size, fp);
    fclose(fp);
    json_buf[file_size] = '\0';

    // 简单字符串查找 "encrypted_key":"base64=="
	printf("run strstr to find the string:%s\n", "\"encrypted_key\":\"");
    p_start = strstr(json_buf, "\"encrypted_key\":\"");
    if (!p_start) {
        fprintf(stderr, "Local State 文件中找不到 encrypted_key 字段\n");
        free(json_buf);
        return 0;
    }
    p_start += strlen("\"encrypted_key\":\"");
    p_end = strchr(p_start, '"');
    if (!p_end) {
        fprintf(stderr, "Local State 文件中 encrypted_key 字段格式错误\n");
        free(json_buf);
        return 0;
    }
    int len = (int)(p_end - p_start);
    if (len >= sizeof(base64_key)) len = sizeof(base64_key) - 1;
    strncpy(base64_key, p_start, len);
    base64_key[len] = '\0';
	printf("base64_key[%d] =%s\n", len, base64_key);//////////////////////////////////////////////
	
	printf("base64_key length:%d\n", strlen(base64_key));

	// 示例：移除字符串中的 \n 和 \r
	char *src = base64_key, *dst = base64_key; int newline_n=0;
	while (*src) {
		if (*src != '\n' && *src != '\r') {
				*dst++ = *src; newline_n++;
			}
			src++;
		}
	*dst = '\0';
	printf("base64_key length:%d, newline_n=%d.\n", strlen(base64_key), newline_n);
		
    free(json_buf);

    // base64 解码
    unsigned char *decoded_key = base64_decode(base64_key, strlen(base64_key), &base64_len);
    if (!decoded_key) {
        fprintf(stderr, "base64 解码失败\n");
        return 0;
    }
	
	printf("%d bit binary decoded_key:", base64_len);
	for (size_t i = 0; i < base64_len; i++)
		printf("%02X ", decoded_key[i]);
	printf("\n");
	
    // 解密 DPAPI 前缀的密钥
    int ret = decrypt_aes_key(decoded_key, base64_len, out_key, out_key_len);
    free(decoded_key);
    if (!ret) {
        fprintf(stderr, "DPAPI 解密 Chrome AES key 失败\n");
        return 0;
    }
	
	printf("Decrypted AES key (%zu bytes):\n", *out_key_len); /////////////////////////////////////////////////////////////////////////////////
	for (size_t i = 0; i < *out_key_len; i++) {
		printf("%02X ", out_key[i]);
	}
	printf("\n");
	
    return 1;
}

int main() 
{
    char local_app_data[MAX_PATH];
    char cookies_path[MAX_PATH];
    char temp_cookies_path[MAX_PATH];
    char temp_dir[MAX_PATH];
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT host_key, name, path, encrypted_value, is_secure FROM cookies WHERE host_key LIKE '%youtube.com%'";
    unsigned char aes_key[256];
    DWORD aes_key_len = 0;

    if (!GetEnvironmentVariableA("LOCALAPPDATA", local_app_data, MAX_PATH)) {
        fprintf(stderr, "无法获取 LOCALAPPDATA 环境变量\n");
        return 1;
    }

    snprintf(cookies_path, MAX_PATH, "%s\\Google\\Chrome\\User Data\\Default\\Network\\Cookies", local_app_data);

    if(!GetEnvironmentVariableA("TEMP",temp_dir,MAX_PATH)){fprintf(stderr,"can't get mingw TEMP\n");return 1;}
    snprintf(temp_cookies_path, MAX_PATH, "%s\\chrome_cookies_copy.db", temp_dir);
	
    printf("MAX_PATH=" "%d\n", MAX_PATH);
    printf("Cookies db path: %s\n", temp_cookies_path); //D:\apps\msys64\tmp\chrome_cookies_copy.db

    if (!copy_file(cookies_path, temp_cookies_path)) {
        fprintf(stderr, "unable copy Cookies db. pls ensure Chrome closed.\n");
        return 1;
    }

    // 读取并解密 AES key
    if (!get_chrome_aes_key(aes_key, &aes_key_len)) {
        fprintf(stderr, "Failed to retrieve and decrypt Chrome AES key\n");
        return 1;
    }

    // 打开复制后的数据库
    if (sqlite3_open(temp_cookies_path, &db)) {
        fprintf(stderr, "无法打开 Cookies 数据库: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "SQL 错误: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    FILE *out = fopen("cookies.txt", "w");
    if (!out) {
        perror("无法创建 cookies.txt");
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *host_key = (const char *)sqlite3_column_text(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *path = (const char *)sqlite3_column_text(stmt, 2);
        const unsigned char *enc_val = (const unsigned char *)sqlite3_column_blob(stmt, 3);
        int enc_len = sqlite3_column_bytes(stmt, 3);
        int is_secure = sqlite3_column_int(stmt, 4);

        if (enc_len < 15) continue;  // 太短的无效

        // 解密 encrypted_value （v20 格式）
        if (enc_val[0] == 'v' && enc_val[1] == '2' && enc_val[2] == '0') {
            unsigned char *iv = (unsigned char *)(enc_val + 3);
            unsigned char *ciphertext = (unsigned char *)(enc_val + 3 + 12);
            int ciphertext_len = enc_len - 3 - 12 - 16;
			
			if (ciphertext_len <= 0) {
				fprintf(stderr, "Invalid ciphertext length for cookie %s\n", name);
			}

            unsigned char *tag = (unsigned char *)(enc_val + enc_len - 16);

            unsigned char decrypted[4096];
            int decrypted_len = 0;

            if (aes_gcm_decrypt(aes_key, aes_key_len, iv, 12, ciphertext, ciphertext_len, tag, 16, decrypted, &decrypted_len)) {
                decrypted[decrypted_len] = 0;  // NUL 结尾字符串

                fprintf(out, "%s\tTRUE\t%s\t%s\t0\t%s\t%s\n",
                        host_key,
                        path,
                        is_secure ? "TRUE" : "FALSE",
                        name,
                        decrypted);
                printf("cookie: %s = %s\n", name, decrypted);
            } else {
                fprintf(stderr, "decrypt failed: cookie %s\n", name);
            }
        } else {
            // 旧版本使用 DPAPI 加密的，尝试用 CryptUnprotectData 解密
            DATA_BLOB in, out_blob;
            in.pbData = (BYTE *)enc_val;
            in.cbData = enc_len;
            if (CryptUnprotectData(&in, NULL, NULL, NULL, NULL, 0, &out_blob)) {
                fwrite(out_blob.pbData, 1, out_blob.cbData, out);
                LocalFree(out_blob.pbData);
            }
        }
    }

    fclose(out);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    printf("Successfully exported cookies.txt.\n");
    return 0;
}


// ===== Base64 解码 =====
unsigned char *base64_decode(const char *input, int length, int *out_len) 
{
    BIO *b64 = BIO_new(BIO_f_base64());
    BIO *bio = BIO_new_mem_buf(input, length);
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // 不使用换行符（默认换行符会影响解码） chatgpt

    unsigned char *buffer = (unsigned char *)malloc(length);
    if (!buffer) {
        BIO_free_all(bio);
        return NULL;
    }

    *out_len = BIO_read(bio, buffer, length);
    BIO_free_all(bio);
    return buffer;
}

// ===== 解密 Local State 中的 AES key =====
int decrypt_aes_key(const unsigned char *enc_key, int enc_key_len, unsigned char *out_key, DWORD *out_key_len) 
{
    // Windows DPAPI 解密 Local State 的 encrypted_key (去掉前面 "DPAPI" 5字节前缀)
    DATA_BLOB in, out;
    if (enc_key_len <= 5) return 0;
    in.pbData = (BYTE *)(enc_key + 5);
    in.cbData = enc_key_len - 5;
    if (!CryptUnprotectData(&in, NULL, NULL, NULL, NULL, 0, &out)) {
        return 0;
    }
    memcpy(out_key, out.pbData, out.cbData);
    *out_key_len = out.cbData;
    LocalFree(out.pbData);
    return 1;
}

// ===== AES-GCM 解密 =====
int aes_gcm_decrypt(const unsigned char *key, int key_len,
                    const unsigned char *iv, int iv_len,
                    const unsigned char *ciphertext, int ciphertext_len,
                    const unsigned char *tag, int tag_len,
                    unsigned char *plaintext, int *plaintext_len) 
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return 0;

    int len;
    int ret = 0;

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        goto end;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, iv_len, NULL))
        goto end;

    if (1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv))
        goto end;

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        goto end;

    *plaintext_len = len;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, tag_len, (void *)tag))
        goto end;

    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    if (ret > 0) {
        *plaintext_len += len;
        ret = 1;
    } else {
        ret = 0;
    }

end:
    EVP_CIPHER_CTX_free(ctx);
    return ret;
}

// ===== 复制文件 =====
int copy_file(const char *src, const char *dest) 
{
    FILE *in = fopen(src, "rb");
    FILE *out = fopen(dest, "wb");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
		DWORD err = GetLastError();
		printf("Copy failed. Error code: %lu\n", err);
        return 0;
    }
    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        fwrite(buffer, 1, bytes, out);
    }
    fclose(in);
    fclose(out);
    return 1;
}
