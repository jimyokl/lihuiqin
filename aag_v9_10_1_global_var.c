#include <stdio.h>
#include <stdlib.h>
// 每次调用func()时，x的地址都不一样
void func(void)
{
    int x;
    x = 0;
    x = x + 1;
    printf("in func(); int x=0,x+1; print x: x = %d, addr of x: %p\n", x, &x);
}
//static变量,自动初始化为0值或空值，并且其变量的值有继承性
void func_static(void)
{
    static int y = 0; //只初始化一次，下次调用时不再初始化,存放在全局数据区,内存地址不变,作用域是不是仍在函数内?
    //y = 0; //这里不能再次初始化，否则会覆盖上一次的值, 会导致y一直为0
    y = y + 1;
    printf("in func_static(); int y=0,y+1; print y: y = %d, addr of y: %p\n", y, &y);
    static int z; //未初始化的static变量会被自动初始化为0
    printf("in func_static(); static int z; print z: z = %d, addr of z: %p\n", z, &z);
}

void func_local_variable(int i)
{
    printf("global_variable 值传递 func(int i) i = %d\n", i); //形参i,值传递
}
int global_variable = 0;
int main() {
    int global_variable = 1;
    printf("global_variable in main = 1, globally==0; global variable: %d\n", global_variable);
    func_local_variable(global_variable);
    {
        int global_variable = 2;
        printf("global_variable in block = 2, globally==0; global variable: %d\n", global_variable);
    }

    auto int a;
    auto int b;
    
    printf("auto int a; auto variable a: %d\n", a); //auto variable a: 32764
    printf("auto int b; auto variable b: %d\n", b); //auto variable b: -538343264

    // static variable
    static int c;
    printf("static int c; static variable c: %d\n", c);

    int d = 3.14159;
    printf("int d = 3.14159; variable d: %d\n", d);

    func(); //局部变量地址会变化
    func();
    func();

    printf("\n");

    func_static();
    func_static();
    func_static();

    exit(0);
}