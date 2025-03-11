#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// drawback:
// 1. reads the newline character from the input stream and stores it in the string.
// 如果第二个参数（长度）小于输入的字符串长度，fgets()会在字符串末尾添加换行符，然后在字符串末尾添加空字符。

// 2: fgets() reads at most one less than the number of characters specified by the size argument.
// 只会读取 最多 n-1 个字符，并在最后添加 \0 终止符。如果输入的字符串比 n-1 长，fgets 只会读取一部分，
// 而剩下的字符仍留在输入缓冲区（stdin），导致下一次读取可能会得到残留数据。需要手动清除输入缓冲区

// 3: fgets() stops reading the input stream when it encounters a newline character or the end-of-file.
// fgets 主要用于文本输入，遇到二进制数据（如 \0）会导致提前终止，而 fread 更适合二进制数据读取。
// 数字 "1234" 以文本存储需要至少4字节（每个字符1字节或更多），而二进制存储只需 2 字节（int16）。
// 二进制数据是以0 和 1 组成的比特流存储的, 通常用于存储非文本数据（如结构体、数组等）

// 4: fgets() returns NULL if it encounters an error or the end-of-file.
// fgets() 会在遇到错误或文件结束时返回 NULL，此时可以使用 feof() 和 ferror() 来判断具体原因。
// 读取文件时，如果遇到 文件结束符（EOF），则返回 NULL，但不能直接区分是因为 读取失败 还是 读到文件末尾。

int main() 
{
    char str[100];
    printf("Enter a string, then press Enter:\n");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s\n", str);
    int str_len = strlen(str);
    printf("The length of the string is: %d\n", str_len); //可能会多打印一个回车符

    for (int i = 0; str[i] != '\0'; i++) {   //当fgets参数2很大时，得到的参数1一个一个字符地输出时，会看到最后有一个'\n'
        printf("str[%d] = %d\n", i, str[i]);
    }
    // Enter a string, then press Enter:  abcde
    // You entered: abcde
    // The length of the string is: 6
    // str[0] = 97
    // str[1] = 98
    // str[2] = 99
    // str[3] = 100
    // str[4] = 101
    // str[5] = 10

    // str[strcspn(str, "\n")] = '\0';  // 去除换行符


    // FILE *fp;
    // char str[60];

    // /* opening file for reading */
    // fp = fopen("file.txt" , "r");
    // if(fp == NULL) {
    //     perror("Error opening file");
    //     return(-1);
    // }
    // if(fgets(str, 60, fp) != NULL) {
    //     printf("%s", str);
    // }
    // fclose(fp);
    
    exit(0);
}   