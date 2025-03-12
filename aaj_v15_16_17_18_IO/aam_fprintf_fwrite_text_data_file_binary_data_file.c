#include <stdio.h>
#include <stdlib.h>

// 文本文件写入：使用fprintf函数将格式化的数据写入文件。文件以文本模式打开（"w"模式）。
// 文本文件适合存储人类可读的数据，如文本、数字和简单数据结构。

//二进制文件写入：使用fwrite函数将数据以二进制形式写入文件。文件以二进制模式打开（"wb"模式）。
//在写入二进制文件时，数据是以原始二进制形式存储的，因此在读取时需要使用相同的结构体或数据类型来解析数据。
//二进制文件适合存储大量数据或复杂数据结构

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

struct Data {
    int num1;
    float num2;
    char str[20];
};

int main() {
    FILE *file_text = fopen("text_file.txt", "a"); // 以写入模式打开文件
    if (file_text == NULL) {
        perror("无法打开文件");
        return 1;
    }
    fputc('\n', file_text);
    // fprintf(file_text, "mar11 vscode offline code completion\n");
    // fprintf(file_text, "intellicode failed, not working.\n");

    char str_fgets[100];
    printf("Enter a string, then press <Enter>:\n");
    fgets(str_fgets, sizeof(str_fgets), stdin);
    fprintf(file_text, "%s", str_fgets);

    int num1 = 123;     float num2 = 45.67;     char str[] = "Hello, World!";
    fprintf(file_text, "%d\n", num1);  // 写入整数
    fprintf(file_text, "%.2f\n", num2);  // 写入浮点数
    fprintf(file_text, "%s\n", str);  // 写入字符串

    fclose(file_text);
    printf("文本文件写入完成。\n");


    FILE *file_bin = fopen("binary_file.dat", "wb"); // 以二进制写入模式打开文件
    if (file_bin == NULL) {
        perror("无法打开文件");
        return 1;
    }

    Student student = {1, "Alice", 95.5};
    struct Data data = {123, 45.67, "Hello, World!"};

    fwrite(&student, sizeof(Student), 1, file_bin);
    fwrite(&data, sizeof(struct Data), 1, file_bin);

    fclose(file_bin);
    printf("二进制文件写入完成。\n");

//vim二进制: ^A^@^@^@Alice^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@¿B{^@^@^@^T®6BHello, World!^@^@^@^@^@^@^@
//vim文本: Hello, C programming!
        // Writing to a text file.
        // 123
        // 45.67
        // Hello, World!

    exit(0);
}

