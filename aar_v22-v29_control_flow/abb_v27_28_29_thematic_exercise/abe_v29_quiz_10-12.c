#include "abb_v27_simple_compound_interest.h"
/* 10. 输出砖石形，eg：
           *
          * *
         * * *
        * * * *
         * * *
          * *
           *
                                      */
static void quiz_ten()
{
    char buff_str[100]=""; int side_n=0, ret_sscanf=0;
    printf("input how many stars that each side rhombus there are:");
    fgets(buff_str, sizeof(buff_str), stdin);
    buff_str[strcsnp(buff_str,"\n")]='\0';
    ret_sscanf=sscanf(buff_str, "%d", &side_n);
    if(ret_sscanf !=1)
    {
        fprintf(stderr, "input error, please input a number\n"); exit(1);
    }
    if(side_n<1)
    {
        fprintf(stderr, "input error, please input a number > 0\n"); exit(1);
    }
    for(int i=0; i< (2*side_n-1)/2; i++)
    {
        printf(" ");
    }
    printf("*\n");



    return;
}
int main(void)
{
    quiz_ten();
    exit(0);
}
//11.
/*
  从终端输入n个数（已字母Q/q作为终止），求和
*/
//12.
/*
  从半径为1开始，输出圆的面积，直到面积大于100为止
*/