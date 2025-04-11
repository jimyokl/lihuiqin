#include "abb_v27_simple_compound_interest.h"
/* 9. 在终端上实现如下输出： 
  ABCDEF
  BCDEF
  CDEF
  DEF
  EF
  F                        */
static void nine_quiz()
{
    printf("%d\n",'A'); //65
    int i=0,j=0;
    for(j=0;j<6;j++)
    {
        for(i=65+j; i<71; i++)
        {
            printf("%c", i);
        }
        printf("\n");
    }
    return;
}
int main()
{ 
    nine_quiz();
    //eight_quiz(); seven_quiz();
    exit(0);
}
//7.水仙花数：个位数值的立方+十位数值的立方+百位数值的立方 之和 = 数本身，eg 153。求出1000以内的所有的水仙花数*/
static void seven_quiz()
{
    int narcissistic_n = 0, digit_n = narcissistic_n%10, ten_digit= narcissistic_n/100;
    ten_digit = ten_digit%10;
    int hundreds_digit = narcissistic_n%1000; hundreds_digit=hundreds_digit/100;
    for(narcissistic_n=100; narcissistic_n<1000; narcissistic_n++)
    {
        digit_n = narcissistic_n%10, 
        ten_digit= narcissistic_n%100; ten_digit = ten_digit/10;
        hundreds_digit = narcissistic_n%1000; hundreds_digit=hundreds_digit/100;
        int temp= pow(digit_n, 3) + pow(ten_digit, 3) + pow(hundreds_digit, 3);   //编译时加 -lm
        // printf("narcissistic_n = %d, digit_n = %d, ten_digit = %d, hundreds_digit = %d\n", narcissistic_n, digit_n, ten_digit, hundreds_digit);
        if(temp == narcissistic_n)
        {
            printf("%d\n", narcissistic_n);
        }
    } 
    return;
}
//8. 质数：除了1和这个数本身以外，没有别的因数，只有1和这个数本身可以整除, 不包括1，prime number, prime是“质的、主要的”意思
//  求出1000以内所有的质数：eg: 2,3,5,7,11,13,17,19 
void eight_quiz()
{
    int i=0, counter_n=0;
    for(i=2;i<1000;i++)
    { 
        if(i%2!=0&&i%3!=0&&i%5!=0&&i%7!=0&&i%11!=0&&i%13!=0&&i%17!=0&&i%19!=0&&i%23!=0&&i%29!=0&&i%31!=0)
        {
            printf("%d, ", i); counter_n++;
        }
    }
    printf("totally %d prime num\n", counter_n); //157
    return;//最小质数：2, 最大质数：在1000以内是997。总数：共168个质数（由数学家验证的经典结果）。
}