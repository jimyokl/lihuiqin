#define MAX_PATH 260
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_chrome_aes_key(unsigned char *out_key, int *out_key_len); //读取 Local State 文件，提取和解密 AES key    
int copy_file(const char *src, const char *dest); //复制文件 =====                                              
int main() {
    char local_app_data[MAX_PATH] = {0}; 
    char cookies_path[MAX_PATH] = {0}; 
    char temp_cookies_path[MAX_PATH] = {0};
    char temp_dir[MAX_PATH];
    snprintf(local_app_data, MAX_PATH, "/home/yan/lihuiqin/lihuiqin/zab_file_IO");
    snprintf(cookies_path, MAX_PATH-strlen(cookies_path)-1, "%s/yab_extract_chrome_cookie/bak/cookies.db", local_app_data);
    snprintf(temp_dir, MAX_PATH, "/home/yan/lihuiqin/lihuiqin/zab_file_IO");
    snprintf(temp_cookies_path, MAX_PATH-strlen(temp_cookies_path)-1, "%s/cookies_.db", temp_dir);
    printf("Cookies db path:%s\n", temp_cookies_path); //
    if (!copy_file(cookies_path, temp_cookies_path)) {
        fprintf(stderr, "unable copy Cookies db. pls ensure Chrome closed.\n"); return 1;
    }
    unsigned char aes_key[256];  
    int aes_key_len = 0; 
    if (!get_chrome_aes_key(aes_key, &aes_key_len)) {                       //读取并解密 AES key
        fprintf(stderr, "Failed to retrieve and decrypt Chrome AES key\n");
        return 1;
    }
    printf("Successfully exported cookies.txt.\n");
    return 0;
}
int get_chrome_aes_key(unsigned char *out_key, int *out_key_len)  // 读取 Local State 文件，提取和解密 AES key
{
    char local_app_data[MAX_PATH] = {0};
    char local_state_path[MAX_PATH];
    FILE *fp;
    long file_size;
    char *json_buf;
    char *p_start, *p_end;
    char base64_key[512] = {0};       // int base64_len;
    snprintf(local_app_data, MAX_PATH, "/home/yan/lihuiqin/lihuiqin/zab_file_IO");
    char* local_state_str = "/yab_extract_chrome_cookie/bak/local_State";
    size_t local_state_path_len = strlen(local_app_data) + strlen(local_state_str) + 1;
    snprintf(local_state_path, local_state_path_len, "%s%s", local_app_data, local_state_str);
    fp = fopen(local_state_path, "rb");
    if (!fp) {
        fprintf(stderr, "无法打开 Local State 文件: %s\n", local_state_path);
        return 0;
    }
    printf("\nin %s(), Local State path: %s\n", __func__, local_state_path); 

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    json_buf = (char *)malloc(file_size + 1);
	printf("\nget_chrome_aes_key(): 'Local State' filesiez: %ld\n", file_size);  
    if (!json_buf) {
        fclose(fp); fprintf(stderr, "mem allocation failed\n"); return 0; }

    fread(json_buf, 1, file_size, fp);
    fclose(fp);
    json_buf[file_size] = '\0';

	printf("run strstr to find the string:%s\n", "\"encrypted_key\":\"");
    p_start = strstr(json_buf, "\"encrypted_key\":\"");                  //简单字符串查找 "encrypted_key":"base64=="
    if (!p_start) {
        fprintf(stderr, "Local State 文件中找不到 encrypted_key 字段\n"); free(json_buf); return 0; }

    int len_encrypted_key = strlen("\"encrypted_key\":\"");
    char ptr_arithmetic[MAX_PATH] = {0};

    // snprintf(ptr_arithmetic, MAX_PATH, p_start);
    // 潜在的安全隐患，因为如果 p_start 中包含格式控制符（如 %s、%x 等），snprintf 会尝试解释它们，
    // 从而导致格式字符串漏洞（Format String Vulnerability),eg:假设p_start = "%x %x %x"，这条语句就会试图打印出栈上的内容，
    // 造成信息泄露或程序崩溃。
    snprintf(ptr_arithmetic, MAX_PATH, "%s", p_start);

    printf("\nptr_arithmetic:\n%s\n", ptr_arithmetic);
    printf("p_start + strlen(\"encrypted_key\":\")--%d:\n%s\n", len_encrypted_key, ptr_arithmetic + strlen("\"encrypted_key\":\""));
    
    p_start += len_encrypted_key;
    p_end = strchr(p_start, '"');
    if (!p_end) {
        fprintf(stderr, "Local State 文件中 encrypted_key 字段格式错误\n");
        free(json_buf);  return 0;  }
    int len = (int)(p_end - p_start);
    printf("p_end - p_start-->len=%d\n", len);
    if (len >= (int)sizeof(base64_key)  )  { len = sizeof(base64_key) - 1; }
    //len >= sizeof(base64_key): comparison of integer expressions of different signedness: ‘int’ and ‘long unsigned int’ [-Wsign-compare]

    strncpy(base64_key, p_start, len);
    base64_key[len] = '\0';
	printf("\nbase64_key[%d]=%s\n", len, base64_key);//////////////////////////////////////////////
	printf("base64_key length:%ld\n", strlen(base64_key));

	char *src = base64_key, *dst = base64_key; int newline_n=0; //示例：移除字符串中的 \n 和 \r
	while (*src) {
		if (*src != '\n' && *src != '\r') {
				*dst++ = *src; newline_n++;
			}
			src++;
		}
	*dst = '\0';
	printf("\ntry remove newline: base64_key length:%ld, newline_n=%d.\n", strlen(base64_key), newline_n);
		
    free(json_buf);
    *out_key_len = strlen(base64_key);
    memcpy(out_key, base64_key, *out_key_len);
	printf("\nDecrypted AES key (%d bytes):\n", *out_key_len); /////////////////////////////////////////////////////////////////////////////////
	//for (int i = 0; i < *out_key_len; i++) {
	//	printf("%02X ", out_key[i]);	}
	printf("\n");
    return 1;
}
int copy_file(const char *src, const char *dest) // ===== 复制文件 =====
{
    printf("\ninto %s()\n", __func__);
    printf("src:%s\n", src);
    printf("dest:%s\n", dest);
    FILE *in = fopen(src, "rb");
    FILE *out = fopen(dest, "wb");
    if(!in || !out){
        if (in) fclose(in);
        if (out) fclose(out); //DWORD err=GetLastError(); printf("Copy failed. Error code: %lu\n",err);
        return 0;
    }
    char buffer[8192];
    size_t bytes; int count_n=0;
    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        //for(int i=0;i<3;i++){
        //    printf("%02x ", buffer[i]);  }
        count_n++;
        fwrite(buffer, 1, bytes, out);
    }
    printf("\n%d\n",count_n);
    fclose(in);
    fclose(out);
    return 1;
}