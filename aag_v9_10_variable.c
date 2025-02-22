#include <stdio.h>
#include <stdlib.h>

void func(void)
{
    int x;
    x = 0;
    x = x + 1;
    printf("in func(); int x=0,x+1; print x: x = %d, addr of x: %p\n", x, &x);
}

void func_static(void)
{
    static int y = 0; //只初始化一次，下次调用时不再初始化,存放在全局数据区,内存地址不变,作用域是不是仍在函数内?
    //y = 0; //这里不能再次初始化，否则会覆盖上一次的值, 会导致y一直为0
    y = y + 1;
    printf("in func_static(); int y=0,y+1; print y: y = %d, addr of y: %p\n", y, &y);

}

// define auto variable
int main() {

    auto int a;
    auto int b;
    
    printf("auto int a; auto variable a: %d\n", a);
    printf("auto int b; auto variable b: %d\n", b);

    // static variable
    static int c;
    printf("static int c; static variable c: %d\n", c);

    int d = 3.14159;
    printf("int d = 3.14159; variable d: %d\n", d);

    func();
    func();
    func();

    printf("\n");

    func_static();
    func_static();
    func_static();

    exit(0);
}