#include <stdio.h>
#include <stdlib.h>

//在循环中使用scanf很危险，因为scanf会一直等待输入，如果输入的不是整数，那么会一直输出上一个缓冲区里面的内容
int main() {
    int a = 0;
    int ret = 0;
    while (1) 
    {   
        //如果输入的是非整数，会一直不间断输出上一个缓冲区里面的内容
        //例如上一次你输入一个整数，下一次你输入一个字符，那么会一直输出上一次输入的整数
        printf("请输入一个整数：\n");
        ret = scanf("%d", &a);
        printf("number of input items: ret = %d\n", ret);
        if (ret != 1) {
            printf("what you entered is not a integer, program will abort.\n");
            break;
            //清空缓冲区
            //while (getchar() != '\n');
            //continue;
        }
        printf("\n你输入的是：%d\n\n", a);
    }
    exit(0);
}