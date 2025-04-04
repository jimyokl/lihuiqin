#include <stdio.h>
#include <stdlib.h>

#define END_VALUE 10

int main(void)
{
    int sum = 0, start_value, ret_scanf;
    printf("Please enter the start value:");
    ret_scanf = scanf("%d", &start_value);
    if (ret_scanf != 1) {
        fprintf(stderr, "Invalid input, please enter a valid integer.\n");
        exit(1);
    }
#if 0    
    while (start_value <= END_VALUE)
    {
        sum = sum + start_value;
        start_value++;
    }
#endif
    do                                              //至少执行1次 循环体内容
    {
        sum = sum + start_value;
        start_value++;
    }while (start_value <= END_VALUE);

    printf("start_value = %d\n", start_value);
    printf("The sum from the start value to %d is: %d\n", END_VALUE, sum);
    
    exit(0);
}