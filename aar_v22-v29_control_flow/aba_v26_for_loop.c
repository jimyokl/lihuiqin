#include <stdio.h>
#include <stdlib.h>

#define RIGHT 100
#define LEFT  1

int main(void)
{
    int i = 0, sum =0;

/*    for(i=LEFT; i<=RIGHT; i++)    //     for(  逗号运算符  ; 逻辑表达式  ;   )
    {
        sum = sum + i;
    }
*/
    i=LEFT;                         // for循环()的3个语句,都可以放到括号外面
    for(; ;)
    {
        sum = sum + i;
        i++;
        if(i>RIGHT)
            break;
    }

    printf("sum = %d\n", sum);

    exit(0);
}