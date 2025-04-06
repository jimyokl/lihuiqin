#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 999;
    if (x > 10)
        printf("x 大于 10\n");
        printf("这条语句总是会执行！\n");  // 这条语句本应只在条件为假时执行
    else
        printf("x 小于或等于 10\n");

    exit(0);
}