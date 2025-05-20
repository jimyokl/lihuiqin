// $$$$$$$$$$$$$$$$#################~~~~~~~~~~~~一~~~~~~~~~~~~~~~***********************$$$$$$$$$$$$$$$$
#include <stdio.h>
int main() {
    FILE *fp;
    long f_pos;

    // 打开文件用于读取（确保 test.txt 文件已存在）
    fp = fopen("xaa_ten_byte.txt", "r");
    if (fp == NULL) {
        perror("无法打开文件");
        return 1;
    }

    // 将文件位置指针移动到文件末尾
    fseek(fp, 0, SEEK_END);

    // 获取当前位置（即文件末尾的偏移量）
    f_pos = ftell(fp);
    if (f_pos == -1L) {
        perror("ftell 失败");
        fclose(fp);
        return 1;
    }

    printf("文件大小为：%ld 字节\n", f_pos);

    // 关闭文件
    fclose(fp);

    return 0;
}
