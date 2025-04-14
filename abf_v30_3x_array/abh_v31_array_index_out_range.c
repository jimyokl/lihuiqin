#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[3] = {1,2,3};
    str[6]='1'; // This will cause a segmentation fault
    printf("index out of range-->str[6] = %c\n", str[6]);
    printf("ASCII code: index out of range-->str[6] = %d\n", str[6]);

    printf("\n**********************************adress a memory location: str[3] = {1,2,3}, index means pointer offset in memory**********************************\n");
    //Pointer arithmetic: process of performing arithmetic operations on pointers, 
    //eg, adding an offset to the pointer to access different elements of an array.
    //Pointer offset addressing: refers to accessing different memory locations by applying an offset 
    //to a pointer.
    printf("*(str+0) to adress str[0] = %d\n", *(str));
    printf("*(str+1) to adress str[1] = %d\n", *(str+1));
    exit(0);
}