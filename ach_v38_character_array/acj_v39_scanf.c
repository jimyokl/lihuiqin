#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
    char scanf_str[N] = {'a', 'a', 'a'};
    
    printf("please input one string:\n");
    scanf("%s", scanf_str);
    printf("%s\n", scanf_str);


    char one_str[N], two_str[N], three_str[N];
    printf("\nplease input three strings:\n");
    scanf("%s%s%s", one_str, two_str, three_str);

    printf("\nthree strings you input are:\n");
    printf("%s\n%s\n%s\n", one_str, two_str, three_str);

    exit(0);
}