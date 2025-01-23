#include <stdio.h>
#define PI 3.1415926
#define ADD 2+3
//#define MAX(a,b) ((a)>(b)?(a):(b))  // 用括号括起来,防止出现问题
#define MAX(a,b)  (a)>(b)?(a):(b)             // (a>b?a:b) is better, 带参的宏定义
#define MAX2(a,b)  \
            ( {int A=(a),B=(b); ((A) > (B) ? (A) : (B));} )
            //{int A=(a),B=(b); ((A) > (B) ? (A) : (B));} // error: expected expression before ‘{’ token             

/* ------------------------------part 1 define------------------------------ */

#if 0
int max(int a, int b) // 用函数代替宏定义,更安全,速度慢一点点
{
    return a>b?a:b;
}
#endif

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

    printf("before running MAX(i++,j++), i = %d\tj = %d\n",i,j);
    printf("MAX(i++,j++) = %d\n", MAX(i++,j++));  // i>j?i:j
    //预编译,gcc -E后变为: printf("MAX(i++,j++) = %d\n", (i++)>(j++)?(i++):(j++));
    //需要谨慎使用 define, 这里就出现了 i++ 两次,导致结果不是预期的
    printf("after running MAX(i++,j++), i = %d\tj = %d\n",i,j);

    // 带参的宏
    int k = 5, l = 3;
    printf("before running MAX2(k++,l++), k = %d\tl = %d\n",k,l);
    printf("MAX2(k,l) = %d\n", MAX2(k++,l++));  // k>l?k:l
    //预编译后变为: printf("MAX2(k,l) = %d\n", ( {int A=(k++),B=(l++); ((A) > (B) ? (A) : (B));} ));
    //这里A接收了k的值,所以没有++自增

    // to del 三目条件运算符（conditional ternary operator）
    int toDel = 0;
    toDel = i>j?i:j;
    printf("toDel =  %d (i>j?i:j, i5 j3)\n", toDel);

    return 0;  // exit(0);更好
}

/* ------------------------------part 2 ------------------------------ */