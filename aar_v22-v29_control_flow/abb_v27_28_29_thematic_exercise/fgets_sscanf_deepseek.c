#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quiz_two() {
    char input[100]; // 用于存储用户输入的缓冲区
    int num, sum_even = 0, sum_odd = 0, count_even = 0, count_odd = 0;

    do {
        printf("***********请每次输入一个数，输入这个数字后，按回车确认输入。***********\n");
        printf("若想结束本次输入，请输入0，再按回车：");

        // 使用 fgets 读取整行输入
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("读取输入失败！\n");
            break;
        }

        // 使用 sscanf 解析输入
        if (sscanf(input, "%d", &num) != 1) {
            printf("你输入的不是数字，请重新输入：\n");
            continue;
        }

        if (num == 0) {
            printf("您输入的是0，输入结束。\n");
        } else {
            printf("你输入的数字是: %d\n", num);
        }

        if (num % 2 == 0 && num != 0) {
            printf("num 是偶数：num=%d\n", num);
            sum_even += num;
            count_even++;
        } else if (num % 2 != 0) {
            printf("num 是奇数：num=%d\n", num);
            sum_odd += num;
            count_odd++;
        }
    } while (num != 0);

    printf("总共输入了 %d 个数，其中偶数 %d 个，奇数 %d 个\n", 
           count_even + count_odd, count_even, count_odd);
}

int main(void) {
    quiz_two();
    return 0;
}

/*
使用 fgets 读取整行输入：

避免 scanf 可能导致的缓冲区问题。

确保输入完整读取，不会残留未处理的换行符。

使用 sscanf 解析输入：

从 fgets 读取的字符串中安全提取数字。

如果解析失败（如输入字母），直接提示错误并继续循环。

移除不必要的 ch 和 ret_scanf：

不再需要手动清空缓冲区，因为 fgets 会读取整行。

更清晰的错误提示：

如果输入的不是数字，直接提示并要求重新输入。
*/