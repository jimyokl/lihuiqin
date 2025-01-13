#include <stdio.h>
int main() 
{
    // calculate size of int
    printf("Size of int: %lu bytes\n", sizeof(int));

    // calculate size of char *
    printf("Size of char *: %lu bytes\n", sizeof(char *));

    // calculate size of float
    printf("Size of float: %lu bytes\n", sizeof(float));

    // calculate size of double
    printf("Size of double: %lu bytes\n", sizeof(double));

    // calculate size of long
    printf("Size of long: %lu bytes\n", sizeof(long));

    // calculate size of long long
    printf("Size of long long: %lu bytes\n", sizeof(long long));
    
    // store octal value in variable
    int octal = 020;
    printf("Octal value: %d\n", octal);

    // store hex value in variable
    int hex = 0x20;
    printf("Hex value: %d\n", hex);

    // store binary value in variable
    int binary = 0b100000;
    printf("Binary value: %d\n", binary);

    // get complement of a number
    int num = 5;
    printf("Complement of %d: %d\n", num, ~num);

    // print first 20 ascii code
    for (int i = 32; i < 41; i++) {
        printf("ASCII code of %c: %d\n", i, i);
    }    
/*
    !: 33,  ": 34,  #: 35,  $: 36,  %:37,  &:38,   ':39,   (:40
*/

    return 0;
}


