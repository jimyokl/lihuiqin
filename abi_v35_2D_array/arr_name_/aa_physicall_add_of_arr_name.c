#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int arr[][3] = {  {1, 2, 3},  {4, 5, 6} };
    printf("arr\t\t-->%p\n", arr);
    printf("*arr\t\t-->%p\n", *arr);
    printf("arr[0]\t\t-->%p\n", arr[0]);
    printf("&arr[0]\t\t-->%p\n", &arr[0]);
    printf("&arr[0][0]\t-->%p\n", &arr[0][0]);
    printf("&arr\t\t-->%p\n", &arr);
    // &arr 是整个数组的地址，类型是 int (*)[2][3]，是指向整个二维数组的指针。
    // 是一个指向二维数组的指针，和arr的地址相同，因为arr代表了整个二维数组。
/*
arr             -->0x7ffd1ee12a80
*arr            -->0x7ffd1ee12a80
arr[0]          -->0x7ffd1ee12a80
&arr[0]         -->0x7ffd1ee12a80
&arr[0][0]      -->0x7ffd1ee12a80
&arr            -->0x7ffd1ee12a80

arr 和 *arr 都指向二维数组的第一行，指向数组的第一个元素 {1, 2, 3}。二维数组是连续存储的，都指向内存中的同一位置。

arr[0]和*arr即数组的第一行，是指向数组第一行的地址,是一个指向arr[0][0]的指针，地址相同，（指向地址的? yan）类型是int[3]
arr[0] 是二维数组的第一行，是一个 int[3] 数组，指向第一个元素 arr[0][0]，这个地址和*arr是相同的，arr[0]是*arr 的值。

&arr[0] 和 arr 也相同，都是指向数组第一行的指针。
&arr[0] 是数组的第一行 arr[0] 的地址。它与 arr 和 *arr 相同，因为 arr[0] 和 *arr 本质上指向同一内存位置。

&arr[0][0] 是二维数组的第一个元素的地址。
这个地址位于内存的第一个位置，是二维数组的起始位置。这个地址是最小的内存单元的地址。
*/
    printf("\nAccessing elements via pointer offset/arithmetic:\n");
    printf(" (*(arr+1)+1)\t=%p\n", *(arr+1)+1 );    // 0x7ffd1ee12a90
    printf(" *(*(arr+1)+1)\t=%d\n", *(*(arr+1)+1)); // 5
    printf(" *(*(arr+0)+0)\t=%d\n", **arr);         // 1
    printf(" *(*(arr+0)+1)\t=%d\n", *(*arr+1));     // 2
    printf("\n");

    printf("\nconvert array name to pointer2pointer:\n");
    int **p2p=(int **)arr;
    printf("p2p\t\t-->%p\n", p2p);                // 0x7ffd1ee12a80
    printf("*p2p\t\t-->%p\n", *p2p);              // 0x200000001


    printf("\naddress of int a, p2p of int a\n");
    int a = 42;   int *p = &a;  // 一级指针，p指向a
    int **pp = &p;              // 二级指针，pp指向p

    printf("a \t= %d\n", a);         // 42        //输出每个变量的值
    printf("*p \t= %d\n", *p);       // 42
    printf("**pp \t= %d\n", **pp);   // 42

    printf("(void*)&a \t= %p\n", (void*)&a);    //0x7ffc6186519c
    printf("(void*)p \t= %p\n", (void*)p);      //0x7ffc6186519c
    printf("p \t\t= %p\n", p);                  //0x7ffc6186519c

    printf("\n");
    printf("&p \t\t= %p\n", &p);                //0x7ffc618651a0
    printf("(void*)*pp \t= %p\n", (void*)*pp);  //0x7ffc6186519c，是p的值==&a
    printf("(void*)pp \t= %p\n", (void*)pp);    //0x7ffc618651a0

    exit(0);
}