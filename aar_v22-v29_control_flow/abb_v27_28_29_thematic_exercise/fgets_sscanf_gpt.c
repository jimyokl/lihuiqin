#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quiz_two()
{
    char input[100]; int num, sum_even = 0, sum_odd = 0, count_even = 0, count_odd = 0;
    while (1)
    {
        printf("***********请每次输入一个数，输入这个数字后，按回车确认输入。***********\n");
        printf("若想结束本次输入，请输入0，再按回车：");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            fprintf(stderr, "读取输入失败，程序终止。\n");
            break;
        }
        input[strcspn(input, "\n")] = '\0';                 // 去掉末尾换行
        if (sscanf(input, "%d", &num) != 1)                 // 尝试解析整数
        {
            printf("你输入的不是有效的数字，请重新输入, now num=%d。\n\n", num);
            continue;
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
    printf("总共输入了 %d 个数字，其中偶数 %d 个，奇数 %d 个\n", count_even + count_odd, count_even, count_odd);
}

int main(void)
{
    quiz_two();
    return 0;
}
/*
加入判断是否多余字符（比如用户输入 "123abc"），进一步增强健壮性。

支持浮点数输入也可以很方便地扩展。
*/