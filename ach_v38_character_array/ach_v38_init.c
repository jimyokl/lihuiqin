#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 10

int main()
{
    // 单个字符初始化：
    char str[M] = {'p', 'r', 'o', 't', 'o', 'n'}; int i;  //if M==3, for loop i<6, output: pro�C
    for(i=0; i<M; i++)                                    //if M==6, for loop i<9, output: proton:�
        printf("%c", str[i]);       
    printf("\n");

    // 字符串常量初始化：
    char string_literal[N] = "p";
    printf("%s\n", string_literal);  //输出：p
    printf("\noutput with for loop:\n");
    for(i=0;i<N;i++)
        printf("%c",string_literal[i]);

    exit(0);
}