
#include <stdio.h>
#include <stdlib.h>
#include "func.h" // 包含头文件

// 定义全局变量
int globalVar = 0;
static int i = 99;

// 实现函数
void printGlobalVar() 
{
    printf("now in function: [%s], ", __func__);
    printf("globalVar = %d, static global var in func func i=%d.\n", globalVar, i);
    //exit(0);
    //exit() 会刷新所有缓冲区（如 printf 的输出缓冲区）,关闭所有打开的文件。
    //exit() 是一个标准库函数，它的作用是终止整个进程,无论是在主函数（main()）还是子函数中调用
    //如果只想退出当前函数,并返回到调用者，应该使用 return
}

void incrementGlobalVar() {
    globalVar++;
}