#include <stdio.h>
#include <stdlib.h>
// 4年一闰，100年不闰，400年再闰
int main(void)
{
    int year, ret_scanf;
    printf("Enter a year: ");
    ret_scanf = scanf("%d", &year);
    printf("what year you entered: %d\n", year);
    if (ret_scanf != 1) {
        fprintf(stderr, "Invalid input. Please enter a valid year.\n");
        exit(1);
    }
    if (year < 0) {
        printf("Year cannot be negative.\n");
        exit(1);
    }
#if 0    
    if(year % 4 == 0)
    {
        if(year % 100 != 0)
        {
            printf("year %d divisible by 4 but not by 100, it is a leap year.\n", year);
        }else if(year % 400 == 0)
        {
            printf("year %d is divisible by 4, 100 and 400, it is a leap year.\n", year);
        }else
        {
            printf("year %d is divisible by 4 and 100 but not by 400, it is not a leap year.\n", year);
        }
    }else
    {
        printf("year %d is not divisible by 4, it is not a leap year.\n", year);
    }
#endif
    if( ( (year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0) )  // 2nd 写法
    {
        printf("year %d is a leap year.\n", year);
    }else
    {
        printf("year %d is not a leap year.\n", year);
    }
    exit(0);
}