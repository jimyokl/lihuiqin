
#include <stdio.h>
#include <stdlib.h>
#include "func.h" // 包含头文件

// 定义全局变量
int globalVar = 0;
// extern int globalVar_2; //globalVar_2在main.c中定义
//extern int globalVar_2 = 88; //报错:multiple definition of `globalVar_2'
extern float globalVar_2; // 会改变main.c中的globalVar_2的值,可能会改为0值(此时globalVar_2=0.000000.)
//extern关键字不能改变所说明变量的类型和值

static int i = 99;

// 实现函数
void printGlobalVar() 
{
    printf("now in function: [%s]\n", __func__);
    printf("        globalVar = %d, static global var in func func i=%d.\n", globalVar, i);
    //exit(0);
    //exit() 会刷新所有缓冲区（如 printf 的输出缓冲区）,关闭所有打开的文件。
    //exit() 是一个标准库函数，它的作用是终止整个进程,无论是在主函数（main()）还是子函数中调用
    //如果只想退出当前函数,并返回到调用者，应该使用 return
}

void incrementGlobalVar() {
    globalVar++;
}

static void static_func() {
    printf("now in static function: [%s]\n", __func__);
}

//调用函数必须在定义函数之后，否则会报错，如果call_static_func()在static_func()之前，会报错
//注意，调用静态函数的函数必须在同一个文件中，否则会报错
//静态函数的作用域仅限于当前文件
//不同文件中的同名静态函数不会冲突
void call_static_func() {
    static_func();
}

void print_extern_globalVar_2_in_main() {
    printf("\nextern keyword:\n");
    printf("now in function: [%s]\n", __func__);
    printf("        globalVar_2 = %f.\n", globalVar_2);
}