#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char *fgets(char s[restrict .size], int size, FILE *restrict stream);

// 使用终端，从stdin读取输入时，按下回车键会结束当前行的输入，fgets停止读取
// 遇到换行符、EOF（文件结束/Ctrl+D/Ctrl+Z）或 读满时, fgets停止读取。
// 保留换行符：如果输入的字符串长度小于 size-1，fgets会将换行符存储在字符串中，并在末尾添加空字符（\0）
// 设计为专门读取文本数据，按行读取文本（以`\n`为终止标志之一）


// advantage:

// 1. 读取最多 n-1 个字符, 不会越过s的边界，
// 2. 可以读取空格

// drawback:

// 1: 如果输入的字符串比size-1长，fgets只读取一部分，剩下的字符仍留在输入缓冲区（stdin）

// 2: fgets主要用于文本输入，遇到二进制数据（如\0）会导致提前终止，而 fread 更适合二进制数据读取。
//   无法直接处理二进制数据：fgets 是为读取文本而设计的，不适用于二进制数据读取

//   数字 "1234" 以文本存储需要至少4字节（每个字符1字节或更多），而二进制存储只需 2 字节（int16）。
//   二进制数据是以0 和 1 组成的比特流存储的, 通常用于存储非文本数据（如结构体、数组等）

//   fgets读取bin文件，读到`\0`后，虽然它会继续读入剩余字符，但程序在处理这些数据时会被误导，以为字符串到此为止


// 3: fgets() returns NULL if it encounters an error or the end-of-file.
//   fgets在遇到错误(eg 磁盘错误)或文件结束EOF时返回 NULL，可使用feof() 和ferror() 来判断具体原因。
//   if(fgets(buf, size, fp)==NULL){  if(feof(fp)) {//EOF} else if (ferror(fp)) {//是读取错误}  }

// 4. 不会清除输入缓冲区中多余的字符

//建议
// 对于更复杂的输入处理，可以考虑使用 getline()（POSIX）或自己实现带缓冲的读取函数；
// 在读取结构化数据时，可结合 sscanf 解析。

int main() 
{
    char str[100];
    printf("Enter a string, then press Enter:\n");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s\n", str);
    int str_len = strlen(str);
    printf("The length of the string is: %d\n", str_len); //可能会多打印一个回车符

    for (int i = 0; str[i] != '\0'; i++)//当fgets参数2很大时，得到的参数1一个一个字符地输出时，会看到最后有一个'\n'     
    {   
        printf("str[%d] = %c, its ASCII value is: %d\n", i, str[i], str[i]);
    }
    //例如输入abcde，字符串长度是6，str[0] = 97 [1] = 98 [2] = 99 [3] = 100 [4] = 101 [5] = 10
    // str[strcspn(str, "\n")] = '\0';  // 去除换行符

    printf("check the terminating null byte of fgets, if input characters are more than its para size:\n");
    char chk_terminating_null_byte[3] = "";
    fgets(chk_terminating_null_byte, sizeof(chk_terminating_null_byte), stdin);
    printf("chk_terminating_null_byte[0] = %c, its ASCII value is: %d\n", chk_terminating_null_byte[0], chk_terminating_null_byte[0]);
    printf("chk_terminating_null_byte[1] = %c, its ASCII value is: %d\n", chk_terminating_null_byte[1], chk_terminating_null_byte[1]);
    printf("chk_terminating_null_byte[2] = %c, its ASCII value is: %d\n", chk_terminating_null_byte[2], chk_terminating_null_byte[2]);

    // FILE *fp; char str[60]; 
    // fp = fopen("file.txt" , "r");  // opening file for reading
    // if(fp == NULL) { perror("Error opening file"); return(-1);}
    // if(fgets(str, 60, fp) != NULL) { printf("%s", str); }
    // fclose(fp);
    exit(0);
}