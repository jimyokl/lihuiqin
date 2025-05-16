#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char len_str[18] = "hello";
    printf("length of \"hello\" is %zu, with strlen.\n", strlen(len_str));  // 5
    printf("size of \"hello\" is %zu, with sizeof.\n", sizeof(len_str));    // 18

    char sizeof_str[]="hello\0abc";
    printf("size of \"hello\\0abc\" is %zu, with sizeof.\n", sizeof(sizeof_str)); // 10

    printf("\nstrcpy function:\n");
    strcpy(sizeof_str, "zz");   // 会把\0也拷贝到sizeof_str中
    puts(sizeof_str);

    printf("\nstrncpy function: len_str[18]=\"hello\"; strncpy(len_str, \"__\", sizeof(len_str)-strlen(len_str)-1 );\n");
    strncpy(len_str, "__", sizeof(len_str)-1 );
    len_str[sizeof(len_str)-1] = '\0';              //手动添加\0
    puts(len_str); 


    printf("\nsnprintf function:\n");
    char snprintf_str[18]="\0";
    snprintf(snprintf_str, sizeof(snprintf_str) , "yy");  // 自动添加\0在末尾
    puts(snprintf_str);

    exit(0);
}

/*
    strlen, sizeof, strcpy, strncpy, strcat, strncat, strcmp, strncmp
*/