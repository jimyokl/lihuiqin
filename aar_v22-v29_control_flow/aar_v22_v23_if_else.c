#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int d=9, e=10;
    if(e++ <d)
    {
        printf("e++ <d.\n");
    }
    else
    {
        printf("e++ is eq to or gt e, e++ >d.\n");
    }
    printf("d is %d, e is %d\n", d, e);

    printf("\nvalue of comma expression (e++<d, d++, ++e): %d\n", (e++<d, d++, ++e)); // comma operator
    printf("now, d is %d, e is %d\n", d, e); // 10, 13

    int f=66;
    if(d=e) printf("\nafter if(d=e), d is %d, e is %d\n\n", d, e); //warning: suggest parentheses around assignment used as truth value
    
    printf("\nif-else pair/matching, nearest-match principle（最近匹配原则), now d=%d, e=%d, f=%d\n", d, e, f); 
    if(d==e)
        if(e==f)
            printf("d==e==f, d is %d, e is %d, f is %d\n", d, e, f);
    else                                                                 // ! 注意这里的else是和哪个if配对的
        printf("d!=e, d is %d, e is %d\n", d, e);

    printf("\nGet the smallest number among the three, pls input 3 integers:\n");
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c) {
        printf("The largest number is: %d\n", a);
    } else if (b > a && b > c) {
        printf("The largest number is: %d\n", b);
    } else {
        printf("The largest number is: %d\n", c);
    }

    exit(0);
}