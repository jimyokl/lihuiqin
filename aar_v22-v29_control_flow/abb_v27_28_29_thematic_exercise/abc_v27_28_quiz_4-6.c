#include "abb_v27_simple_compound_interest.h"
//6./* 百钱买百鸡：鸡翁一，值钱五，鸡母一，值钱三，三鸡雏，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？*/
//#define MIN 2
static void six_quiz()
{
    //double chick_price=(float)1/3; 
    int hen_price=3,rooster_price=5,rooster_num=1,hen_num=1,chick_num=1;
    for(rooster_num=0;rooster_num<20;rooster_num++)                         //rooster可以==0
    {
        for(hen_num=0;hen_num<33;hen_num++)   //这里hen_num=0需要写，第一次hen_num自加到33后，需要再初始化
        {
            chick_num=100-rooster_num-hen_num;
            if( (rooster_num*rooster_price+hen_num*hen_price+chick_num/3==100) && (chick_num%3==0) )
            {
                printf("rooster:%d,hen:%d,chick:%d,total num:%d\n",rooster_num,hen_num,chick_num,rooster_num+hen_num+chick_num);
            }
//不用再使用for，利用已知条件可求得鸡雏只数            
            /*for(chick_num=1; (rooster_num*rooster_price+hen_num*hen_price+chick_num*chick_price<=100.0) && (chick_num<=300);chick_num++) {
                if( (rooster_num+hen_num+chick_num==100) && (chick_num%3==0) ){
                    double diff_ =(rooster_num*rooster_price+hen_num*hen_price+chick_num*chick_price)-100.0;
                    if( abs(diff_) < MIN ){
                        printf("rooster:%d,hen:%d,chick:%d,total num:%d\n",rooster_num,hen_num,chick_num,rooster_num+hen_num+chick_num);
                        printf("diff=%.2f\n", diff_); } } } */
        }
    }
    return;
}
int main(void)
{
    six_quiz();
    //five_quiz(); //four_quiz(); 
    exit(0); 
}
//5. /*  输出99乘法表 */
void five_quiz()
{
    int i=0,j=0;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%2d; ",j,i,i*j);
        }
        printf("\n");
    }
    return;
}
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