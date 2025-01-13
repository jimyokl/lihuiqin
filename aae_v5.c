#include <stdio.h>
#include <stdbool.h>
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

    // print ascii code of number 0 and 9
    printf("ASCII code of 0 and 9: %d and %d.\n", '0', '9');


    // print ascii code 048
    printf("ASCII code of 048 and 057: %c, %c\n", 48, 57);
    printf("ASCII code of 065 and 091: %c, %c\n", 65, 90); // 26 letters A-Z
    printf("ASCII code of 097 and 122: %c, %c\n", 97, 122); // 26 letters a-z

   float i_f = 3.4;
   int i_i = 0;
   i_i = (int)i_f;
   printf("3.4 after convert to integer: %d\n", i_i);

   bool a = false;
   printf("bool data a: %d\n", a);
   
   int test_f = 3.14;
   float minus_f = i_f - test_f;
   if(minus_f < 0.000001)
   {
   	printf("minus_f is around 0\n");
   }
   else 
   	printf("minus_f is not around 0\n");
	   
    return 0;
}


