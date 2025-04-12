#include "abb_v27_simple_compound_interest.h"
//12. /* 从半径为1开始，输出圆的面积，直到面积大于100为止 */
static void twelve_quiz()
{
    int radius_n=0; double area=0.0;
    //for(radius_n=1; area<=100; radius_n++)
    for(radius_n=1; ; radius_n++)
    {
        area = PI*radius_n*radius_n;
        printf("area of radius %d is %7.3f\n", radius_n, area);
        if(area>100.0) break;
    }
    return;
}
int main(void)
{
    twelve_quiz();
    //elven_quiz();
    //quiz_ten();
    exit(0);
}
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
    buff_str[strcspn(buff_str,"\n")]='\0';
    ret_sscanf=sscanf(buff_str, "%d", &side_n);
    if(ret_sscanf !=1)
    {
        fprintf(stderr, "input error, please input a number\n"); exit(1);
    }
    if(side_n<1)
    {
        fprintf(stderr, "input error, please input a number > 0\n"); exit(1);
    }
    printf("number you input:%d\n", side_n);
    //for(int i=0; i< (2*side_n-1)/2; i++){ printf(" "); }
    for(int i =0; i<side_n; i++)
    {
        for(int j=0;j<side_n-i-1;j++)
        {
            printf(" ");
        }
        for(int k=0; k<i+1;k++)
        {
            printf("* ");
        }
    	printf("\n");
    }
    for(int i =0; i<side_n-1; i++)
    {
        for(int j=0;j<i+1;j++)
        {
            printf(" ");
        }
        for(int k=0; k<side_n-i-1;k++)
        {
            printf("* ");
        }
    	printf("\n");
    }
    return;
}
//11. 从终端输入n个数（已字母Q/q作为终止），求和 */
static void elven_quiz()
{
    char input[100]; int num=0,sum=0,count_n=0;char ch=0;
    while(1)
    {
        printf("***********请每次输入一个数，输入这个数字后，按回车确认输入。***********\n");
        printf("若想结束本次输入，请输入q或者Q，再按回车：");
        if (fgets(input, sizeof(input), stdin) == NULL)
        { fprintf(stderr, "读取输入失败，程序终止。\n"); break; }
        input[strcspn(input, "\n")] = '\0';                 // 去掉末尾换行
        if (sscanf(input, "%d", &num) != 1)                 // 尝试解析整数
        {
            if (sscanf(input, "%c", &ch) != 1)
            {
                printf("你输入的不是有效的数字，请重新输入。\n\n"); continue;
            }else if (ch == 'q' || ch=='Q')
            {
                printf("您输入的是q或者Q，退出程序。\n"); break;
            }else{
                printf("你输入的不是有效的数字，也不是q或者Q，请重新输入。\n\n"); continue;
            }
        }else
        {
            printf("你输入的数字是: %d\n", num);
            sum=sum+num;
            count_n++;
        }
        
        // printf("\n");
    }
    printf("共输入%d个数字，和为%d.\n", count_n, sum);
    return;
}