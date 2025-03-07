#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int a;

    printf("如果先输入一个数字，回车/空格/tab键/换行符，再输入一个字符，则getchar会接收到 回车/空格/tab键/换行符\n");
    printf("空格/tab键/换行符对应的ASCII码分别是32/9/10\n");
    printf("Please input a number and a character:\n");
    scanf("%d", &a);

    // printf("please input a character:\n");
    c = getchar();
    //scanf("%c", &c); //scanf会接收到回车/空格/tab键/换行符

    printf("The number is %d\n", a);
    printf("The character is %d\n", c); // 用%d打印字符的ASCII码

    

    // printf("The character is %c\n", c);

    // while (c != EOF)
    // {
    //     putchar(c);
    //     c = getchar();
    // }
    exit(0);
}