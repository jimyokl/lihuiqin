// "进制转换" in English is "base conversion" or "number base conversion". 
// It refers to converting a number from one base (e.g., decimal, binary, hexadecimal) to another.
#include <stdio.h>
#include <stdlib.h>
#define MAX 64
static void base_convert()
{
    int num=0, base=0, digit_n[MAX], i=0;

    printf("Please input a number and a base (2-16): ");
    scanf("%d %d", &num, &base);
    if(num<0 || base<2 || base>16)
        printf("Invalid input! Please try again.\n");

    do{
        digit_n[i]=num%base;
        num=num/base;
        i++;
    //}while(num!=0);
    }while(num>0);
    for(i--;i>=0;i--)
    {
        if(digit_n[i]<10)
            printf("%d ", digit_n[i]);
        else
            printf("%c", digit_n[i]-10+'A');
    }
    printf("\n");
    return;
}
int main()
{
    base_convert();
    exit(0);
}
