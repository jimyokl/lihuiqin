#include "abb_v27_simple_compound_interest.h"
//3. /*  从终端上输入若干字符，对其中的元音字母进行统计，*/
void quiz_three()
{
    char str[500]=""; int a_num=0, e_num=0, i_num=0, o_num=0, u_num=0, counter=0, other_num=0, vowel_num=0;
    printf("请输入若干字符，按回车结束输入：\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // 去掉换行符
    printf("你输入的字符串是：%s, strlen=%ld.\n", str, strlen(str));
    for(; counter<strlen(str); counter++)
    {
        switch (str[counter])
        {
            case 'a':
            case 'A': a_num++; break;
            case 'e':
            case 'E': e_num++; break;
            case 'i':
            case 'I': i_num++; break;
            case 'o':
            case 'O': o_num++; break;
            case 'u':
            case 'U': u_num++; break;
            default:  other_num++; break;
        }
    }
    vowel_num= a_num + e_num + i_num + o_num + u_num;
    printf("a_num:%d,e_num:%d,i_num:%d,o_num:%d,u_num:%d,vowel_num:%d,other_num:%d\n", a_num, e_num, i_num, o_num, u_num, vowel_num, other_num);
    return;
}
int main(void)
{
    //quiz_one(); quiz_two();
    quiz_three(); exit(0);
}
//2. /*  从终端输入数据，直到输入0值为止，计算其中偶数的个数和平均值；计算其中奇数的个数和平均值  */
void quiz_two()
{    
    int num=0,ch,ret_scanf,sum_even=0,sum_odd=0,count_even=0,count_odd=0;double avg_even=0.0,avg_odd=0.0;
    do
    {
        printf("        ***********请每次输入一个数，输入这个数字后，按回车确认输入。***********        \n");
        printf("若想结束本次输入，请输入0，再按回车, now num = %d\n", num);
        
        ret_scanf = scanf("%d", &num);
        if(ret_scanf != 1)
        {
            printf("你输入的不是数字，请重新输入：\n");
            while( (ch = getchar()) != '\n' && ch != EOF);  // 清空输入缓冲区
            continue;
        }
        while((ch = getchar()) != '\n' && ch != EOF);  // 清空输入缓冲区
        
        if(num == 0)
        {
            printf("您输入的是0，输入结束。\n"); break;
            // printf("您输入的是0，输入结束。\n"); 之前没有break,判断是否跳出循环的条件在while()的()里面
        }else{
            printf("你输入的数字是: %d\n", num); 
        }

        if(num%2 == 0)
        {
            printf("num is 偶数：字符ch的ASCII码=%d, num=%d\n", ch, num);
            sum_even += num;
            count_even++;
        }
        else if( num%2 !=0)
        {
            printf("num is 奇数：字符ch的ASCII码ch=%d, num=%d\n", ch, num);
            sum_odd += num;
            count_odd++;
        }
    }while(1);
    //}while(num != 0);
    avg_even= (count_even==0)?0:(float)sum_even/count_even;
    avg_odd= (count_odd==0)?0:(float)sum_odd/count_odd;
    printf("共%d numbers,count_even=%d,count_odd=%d,sum_even=%d,sum_odd=%d,avg_even=%.2f,avg_odd=%.2f\n", count_even+count_odd, count_even, count_odd, sum_even, sum_odd, avg_even, avg_odd);
    return;
    // exit(0);
    // 之前这里不是return，是exit(0), 这个exit()在 main() 和 quiz_two() 中都存在，之前运行如果第一次输入字母，程序会退出
    // gpt解释说：当你运行 quiz_two() 后，一旦它结束（包括非正常退出），整个程序就结束了. 之前这是一个非正常退出吗？
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