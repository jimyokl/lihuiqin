#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("binary_file.dat", "rb");  // 以二进制方式打开文件
    if (!file) {
        perror("文件打开失败");
        return 1;
    }

    // 读取文件内容
    unsigned char buffer[1024];  // 缓冲区
    size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
    
    if (bytesRead > 0) {
        printf("成功读取 %zu 字节的数据\n", bytesRead);
    } else {
        printf("文件读取失败或文件为空\n");
    }
    printf("文件内容：\n");
    for (size_t i = 0; i < bytesRead; i++) {
        printf("%02X\n", buffer[i]);
    }

    fclose(file);
    exit(0);
}
