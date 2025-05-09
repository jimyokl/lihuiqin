#include <stdio.h>
#include <stdlib.h>

int i=0;

void print_star(void)
{
    // static int count = 0;
    // count++;
    // printf("count = %d\n", count);
 
    //for (int i = 0; i < 5; i++)
    for ( i = 0; i < 5; i++)
    {
        printf("*");
    }
    printf("\n");
    //printf("[func name: %s], i = %d\n", __func__, i);
    printf("[func name: %s], i = %d\n", __FUNCTION__, i);
}

int main()
{
    //for (int i = 0; i < 5; i++), 这样的可以打印5行星号
    for ( i = 0; i < 5; i++)
    {
        print_star();//第一次调用后,i会变为5
        printf("[func name: %s], i = %d\n", __func__, i);
    }
    printf("out of main for loop, [func name: %s], i = %d\n", __func__, i);
    exit(0);
}