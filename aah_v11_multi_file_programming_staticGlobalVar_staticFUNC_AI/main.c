#include <stdio.h>
#include "func.h" // 包含头文件
#include <stdlib.h>
//main.c 通过包含 func.h，能够访问 func.c 中的全局变量和函数。
//通过使用头文件和 extern 关键字，我们可以在不同源文件之间共享全局变量和函数。
//每个源文件中的定义和声明都起着重要的作用，确保链接器能够正确识别符号。
//模块化的编程方式有助于组织大型项目，提高代码的可读性和可维护性。

//头文件的作用：声明函数和全局变量，避免重复定义。
// -使用 #ifndef、#define 和 #endif 防止头文件重复包含。

//extern 关键字：在头文件中使用 extern 声明全局变量，表示该变量在其他文件中定义。
// -在源文件中定义全局变量（分配内存）。

//函数声明：在头文件中声明函数，在源文件中实现函数。

//编译多个文件：使用 gcc 编译多个源文件时，需要将所有文件一起编译。

static int i = 11;

int globalVar_2 = 22;

int main() {
    // 访问全局变量
    printf("now in function: [%s]\n", __func__);
    printf("        Initial globalVar: %d, static global var in main i=%d.\n", globalVar, i);

    // 调用函数
    incrementGlobalVar();
    printGlobalVar();

    printf("now begin to increment globalVar for 2nd time\n");
    incrementGlobalVar();
    printGlobalVar();

    // static_func();
    call_static_func();

    print_extern_globalVar_2_in_main();

    exit(0);
}