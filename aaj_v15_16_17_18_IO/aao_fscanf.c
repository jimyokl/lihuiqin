#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char name[50] = "";
    int age;
    float height;

    name[0] = '\0';  // 清空字符串

    // 打开文件
    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    // fscanf(file, "%s %d %f", name, &age, &height)：从文件中读取字符串、整数和浮点数。
    // while (fscanf(...) != EOF)：循环读取直到文件结束 (EOF 表示文件结束符)。
    while (fscanf(file, "%s %d %f", name, &age, &height) != EOF) {
        printf("姓名: %s, 年龄: %d, 身高: %.2f\n", name, age, height);
    }

    // 关闭文件
    fclose(file);
    return 0;
}