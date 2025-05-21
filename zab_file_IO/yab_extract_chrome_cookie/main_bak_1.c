// main.c - Chrome Cookie 导出工具（适用于 MinGW）

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>
#include <shlobj.h>
#include "sqlite3.h"

// 使用 Windows 的 DPAPI 解密 cookie
int decrypt_cookie(const unsigned char *enc_data, int enc_len, char *output, DWORD *output_len) {
    DATA_BLOB in, out;
    in.pbData = (BYTE *)enc_data;
    in.cbData = enc_len;

    if (CryptUnprotectData(&in, NULL, NULL, NULL, NULL, 0, &out)) {
        memcpy(output, out.pbData, out.cbData);
        *output_len = out.cbData;
        LocalFree(out.pbData);
        return 1;
    }

    return 0;
}

int main() {
    char db_path[MAX_PATH];
    const char *local_app_data = getenv("LOCALAPPDATA");    

    if (!local_app_data) {
        printf("无法获取 LOCALAPPDATA 环境变量\n");
        return 1;
    }else {
        printf("LOCALAPPDATA: %s\n", local_app_data);
    }

    snprintf(db_path, sizeof(db_path),
             "%s\\Google\\Chrome\\User Data\\Default\\Network\\Cookies", local_app_data);

    printf("sqlite3 database path: %s\n", db_path);

    sqlite3 *db;
    if (sqlite3_open(db_path, &db)) {
        fprintf(stderr, "yan app can't open db: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    const char *sql =
        "SELECT host_key, name, path, encrypted_value, is_secure "
        "FROM cookies WHERE host_key LIKE '%%youtube.com'";

    sqlite3_stmt *stmt;
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
        const char *domain = (const char *)sqlite3_column_text(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *path = (const char *)sqlite3_column_text(stmt, 2);
        const unsigned char *enc_val = sqlite3_column_blob(stmt, 3);
        int enc_len = sqlite3_column_bytes(stmt, 3);
        int is_secure = sqlite3_column_int(stmt, 4);

        char value[4096] = {0};
        DWORD val_len = 0;

        if (decrypt_cookie(enc_val, enc_len, value, &val_len)) {
            fprintf(out, "%s\tTRUE\t%s\t%s\t0\t%s\t%s\n",
                    domain,
                    path,
                    is_secure ? "TRUE" : "FALSE",
                    name,
                    value);
        }
    }

    fclose(out);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    printf("success! cookies.txt 已生成\n");
    return 0;
}
