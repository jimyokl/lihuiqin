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
}

int main()
{
    //for (int i = 0; i < 5; i++)
    for ( i = 0; i < 5; i++)
    {
        print_star();//第一次调用后,i会变为5
    }
    exit(0);
}