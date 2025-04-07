#include "abb_v27_simple_compound_interest.h"
//2. /*  从终端输入数据，直到输入0值为止，计算其中偶数的个数和平均值；计算其中奇数的个数和平均值  */
void quiz_two()
{    
    int num, ch, ret_scanf, sum_even = 0, sum_odd = 0, count_even = 0, count_odd = 0;
    do
    {
        printf("        ***********请每次输入一个数，输入这个数字后，按回车确认输入。***********        \n");
        printf("结束输入，请输入0，再按回车：");   
        
        ret_scanf = scanf("%d", &num);
        if(ret_scanf != 1)
        {
            printf("你输入的不是数字，请重新输入：\n");
            while((ch = getchar()) != '\n' && ch != EOF);  // 清空输入缓冲区
            continue;
        }

        while((ch = getchar()) != '\n' && ch != EOF);  // 清空输入缓冲区
        
        if(num == 0)
        {
            printf("您输入的是0，输入结束。\n");
        }else{
            printf("你输入的数字是: %d\n", num); 
        }

        if(num%2 == 0 && num != 0)
        {
            printf("num is 偶数：ch=%d, num=%d\n", ch, num);
            sum_even += num;
            count_even++;
        }
        else if( num%2 !=0)
        {
            printf("num is 奇数：ch=%d, num=%d\n", ch, num);
            sum_odd += num;
            count_odd++;
        }
    }while(num != 0);

    printf("totally input %d numbers, even number count=%d, odd number count=%d\n", count_even+count_odd, count_even, count_odd);
    exit(0);
}
int main(void)
{
    //quiz_one();    
    quiz_two();
    exit(0);
}
void quiz_one()
{
    double init_invest = 100.0; // 初始投资额
    double simple_interest_rate = 0.10, compound_interest_rate = 0.05;
    double simple_interest_return = 0.0, compound_interest_return = 0.0;
    int years= 0; double base = 1+compound_interest_rate, coefficient = 0.0;
    for(; simple_interest_return >= compound_interest_return; years++)
    {
        coefficient = simple_interest_rate*years;
        simple_interest_return = init_invest*(1.0+coefficient);
        compound_interest_return = init_invest*pow(base, years);
        printf("years=%2d, simple_interest_return=%.3f, compound_interest_return=%.3f\n", years, simple_interest_return, compound_interest_return);
    }
    printf("After %d years, B's investment total is %f, A's investment total is %f\n", years, compound_interest_return, simple_interest_return);
}
//1.
/*
  A以每年10%的单利息投资了100美元，B以每年5%的复合利息投资了100美元。
  编写程序，计算多少年后B的投资总额大于A的投资总额。并显示2人的资产总额
*/
//3.
/*
  从终端上输入若干字符，对其中的元音字母进行统计，
*/




//4.
/*
  写出Fibonacci函数的前40项：1,1,2,3,5,8,13,21...(不能用数组实现)
*/
//5.
/*
  输出99乘法表
*/
//6.
/*
  百钱买百鸡：鸡翁一，值钱五，鸡母一，值钱三，三鸡雏，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
*/
//7.
/*
  水仙花数：个位数值的立方+十位数值的立方+百位数值的立方 之和 = 数本身，eg 153。求出1000以内的所有的水仙花数
*/
//8.
/*
  质数：除了1和这个数本身以外，没有别的因数，只有1和这个数本身可以整除, 不包括1，prime number, prime是“质的、主要的”意思
  求出1000以内所有的质数：eg: 2,3,5,7,11,13,
  17,19
*/
//9.
/*
  在终端上实现如下输出： 
  ABCDEF
  BCDEF
  CDEF
  DEF
  EF
  F
*/
//10.
/*
  输出砖石形，eg：
           *
          * *
         * * *
        * * * *
         * * *
          * *
           *
*/
//11.
/*
  从终端输入n个数（已字母Q/q作为终止），求和
*/
//12.
/*
  从半径为1开始，输出圆的面积，直到面积大于100为止
*/