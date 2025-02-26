
#ifndef FUNC_H // 防止头文件重复包含
#define FUNC_H

// 声明全局变量
extern int globalVar; //在别的文件去找到globalVar的定义

// 声明函数
void printGlobalVar();
void incrementGlobalVar();

// static void static_func();
void call_static_func();

void print_extern_globalVar_2_in_main();
#endif