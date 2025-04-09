#include "abb_v27_simple_compound_interest.h"
//4. 写出Fibonacci函数的前40项：1,1,2,3,5,8,13,21...(不能用数组实现) 
void four_quiz()
{
    int i=1,j=1,counter=0,k=0;
    for(;counter<40; counter++)
    {
        k = i + j;
        i =j; j=k;
        printf("%d, ", k);
        //printf("%d: %d ",counter+1, k);
    }
    printf("\n");
    return;
}
int main(void)
{
    four_quiz();
    exit(0);
}
//5.
/*
  输出99乘法表
*/
//6.
/*
  百钱买百鸡：鸡翁一，值钱五，鸡母一，值钱三，三鸡雏，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
*/