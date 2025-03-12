#include <stdio.h>
#include <stdlib.h>
#define STRSIZE 32
#define STRSIZE_overrun 2

//gets的字符数组可能很小，但是stdin输入了很多字符，gets会把stdin的字符全部读取到字符数组中，这样就会造成缓冲区溢出。
//已经越界，如果内存空间受保护，程序会崩溃，如果没有受保护，会覆盖其他内存空间，造成程序错误。

//会将所有 input 从 STDIN 复制到缓冲区，而不检查大小。这允许用户提供大于缓冲区大小的字符串，从而导致溢出情况。

// gets()
// DESCRIPTION
// Never use this function.
// it is impossible to tell without knowing the data in advance how many characters gets() will read, and because gets() will continue to store characters past the end of the buffer, 
// it is extremely dangerous to use. 
// It has been used to break computer security. Use fgets() instead.

// gets()  reads  a line from stdin into the buffer pointed to by s until either a terminating newline 
// or EOF, which it replaces with a null byte ('\0').  
// No check for buffer overrun is performed (see BUGS below).

int main()
{
    
    // puts() writes the string s and a trailing newline to stdout.
    // "newline", when printed, but makes anything printed subsequently thereafter print on the next line. 
    // It adds a newline to the end ("trailing newline") of everything it prints by default
    // “换行符”,默认情况下，它会在打印的所有内容的末尾添加一个换行符（“尾随换行符”）。
    char str[STRSIZE];
    puts("Enter a string，then press <Enter>:"); //字符间可以有空格
    gets(str);
    puts("You entered: ");
    puts(str);

    char str_overrun[STRSIZE_overrun]; 
    printf("\ngets(str), str length is only 3, buffer overrun will happen\n");
    puts("Enter a string, then press <Enter>:"); //字符间可以有空格
    gets(str_overrun);
    puts("You entered: ");
    puts(str_overrun);


    char str_flie[100];
    FILE *fptr;

    printf("\n\n打开文件t，写入字符串\n");

    fptr = fopen("t", "a");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter a string, then press <Enter>:\n");
    gets(str_flie);

    fprintf(fptr,"%s", str_flie);
    fputc('\n', fptr);

    fclose(fptr);

    exit(0);
}   