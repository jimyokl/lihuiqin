#include <stdio.h>
#include <stdlib.h>

int main()
{
    // reads the next character from stream and returns it as an unsigned char cast to an int
    // char cast to an int
    int ch; //所以这里用int，用char也可以，int更保险一点

    printf("Please input a character:\n");


    ch = getchar();
    printf("The character you input is: ");
    putchar('\n');

    putchar(ch);
    putchar('\n');
    printf("The ASCII code of the character is: %d\n", ch);

    exit(0);
}