#include <stdio.h>
#define PI 3.1415926
#define ADD 2+3
//#define MAX(a,b) ((a)>(b)?(a):(b))  // 用括号括起来,防止出现问题
#define MAX(a,b)  a>b?a:b             // (a>b?a:b) is better

/* ------------------------------part 1 constant------------------------------ */
int main() 
{
    // define π to calculate the square of a circle
    //标识常量经常用到,一改全改
    //const double PI = 3.1415926; 用 #define 宏定义
    int a,b,c =0;
    a*PI; b + PI; c/PI;  //gcc -E 预处理后, 宏体直接替换为宏名:a*3.1415926; b+3.1415926; c/3.1415926;
                         // 此时不做语法检查
    printf(" define ADD 2+3, ADD*ADD = %d\n", ADD*ADD);  // ADD*ADD = a+b*a+b,直接替换,其他不做任何事

    int i = 5, j = 3;
    printf("MAX(i,j) = %d\n", MAX(i,j));  // i>j?i:j

    // to del 三目条件运算符（conditional ternary operator）
    int toDel = 0;
    toDel = i>j?i:j;
    printf("toDel =  %d (i>j?i:j, i5 j3)\n", toDel);

    return 0;  // exit(0);更好
}

/* ------------------------------part 2 ------------------------------ */