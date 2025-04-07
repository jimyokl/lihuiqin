#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float grade; int ret_scanf;
    printf("input your grade:");
    ret_scanf = scanf("%f", &grade);
    printf("your input is: %f\n", grade);
    if (ret_scanf !=1)
    {
        fprintf(stderr, "your input is not a number.\n");
        exit(1);
    }else if (grade >100 || grade<0)
    {
        fprintf(stderr, "number you input is gt 100 or lt 0\n");
        exit(1);
    }    
    if (grade >= 90 && grade <=100)
    {
        printf("Your grade is A.\n");
    }else if (grade >= 80 && grade <90)
    {
        printf("Your grade is B.\n");
    }else if (grade >= 70 && grade <80)
    {
        printf("Your grade is C.\n");
    }else if (grade >= 60 && grade <70)
    {
        printf("Your grade is D.\n");
    }else if (grade >=0 && grade <60)
    {
        printf("Your grade is E.\n");
    }

    exit(0);
}