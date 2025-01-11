#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = NULL;
    p = malloc(sizeof(int));
    if(p == NULL){
        //printf("malloc failed\n");
        exit(1); //比 return -1 更好，
                 //因为exit会终止整个程序，而return只会终止当前函数?
    }
    // man malloc(), 函数返回值是void *，p是int *, 
    // 如果没加stdlib.h, 把这个程序 gcc dont_forget_head_file.c -Wall, 会报warning( malloc和exit函数 隐式声明)，
    //其实这个warning是一个error, 如果没有头文件,直接用,这样隐式声明则会让编译器认为是返回值是int，而不是void *，
    // 编译器认为是把int赋值给int *，所以会报warning, (且这样会导致程序运行错误)，
    // 改为(int *)malloc也不对,相当于把int强转为int*, 不是在解决问题, 而是在隐藏问题，
    // 加上stdlib头文件后，里面已经声明了这两个函数的返回值是void *，是万金油类型, 
    // 把void *赋值给任何类型都可以(除了标准c中有一个未定义行为,和函数指针相关), 包含后,没有强转类型,也不会报warning了
    // 如果使用强转会掩盖没有包含头文件的错误！
    // 包含头文件的好处是，编译器能看到原型，能检查参数类型是否匹配，返回值是否匹配，如果不匹配，会报warning
    //如果有变量声明了但没有使用, 加上-Wall选项，gcc也会报warning，
    printf("Hello, World!\n");
    exit(0); //return 0;
}