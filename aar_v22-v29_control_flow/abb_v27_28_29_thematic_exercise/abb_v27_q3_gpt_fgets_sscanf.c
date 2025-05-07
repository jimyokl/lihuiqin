#include <stdio.h>     // 输入%d个数字，偶数%d个，奇数%d个
#include <stdlib.h>
#include <string.h>
void quiz_two()
{
    char input[100]; int num=0,sum_even=0, sum_odd=0,count_even=0,count_odd=0;
    double avg_even=0.0,avg_odd=0.0;
    while(1)
    {
        printf("***********请每次输入一个数，输入这个数字后，按回车确认输入。***********\n");
        printf("若想结束本次输入，请输入0，再按回车：");
        if (fgets(input, sizeof(input), stdin) == NULL)
        { fprintf(stderr, "读取输入失败，程序终止。\n"); break; }
        input[strcspn(input, "\n")] = '\0';                 // 去掉末尾换行
        if (sscanf(input, "%d", &num) != 1)                 // 尝试解析整数
        {
            printf("你输入的不是有效的数字，请重新输入, now num=%d。\n\n", num); continue;
        }
        if (num == 0)
        {
            printf("您输入的是0，输入结束。\n"); break;
        }
        else
        {
            printf("你输入的数字是: %d\n", num);
        }
        if (num % 2 == 0)
        {
            printf("num 是偶数: %d\n", num); sum_even += num; count_even++;
        }
        else
        {
            printf("num 是奇数: %d\n", num); sum_odd += num; count_odd++;
        }
        printf("\n");
    }
    avg_even = (count_even == 0) ? 0 : (double)sum_even / count_even;
    avg_odd = (count_odd == 0) ? 0 : (double)sum_odd / count_odd;
    printf("共输入%d个数字，偶数%d个，奇数%d个, avg_even=%.2f, avg_odd=%.2f\n", count_even+count_odd, count_even, count_odd, avg_even, avg_odd);
}
int main(void) { quiz_two(); return 0; }
/*
  使用 fgets 读取整行输入，避免 scanf 可能导致的缓冲区问题。 确保输入完整读取，不会残留未处理的换行符。
  使用 sscanf 解析输入：从 fgets 读取的字符串中安全提取数字。
*/
/*
  加入判断是否多余字符（比如用户输入 "123abc"），进一步增强健壮性。
  支持浮点数输入也可以很方便地扩展。
*/