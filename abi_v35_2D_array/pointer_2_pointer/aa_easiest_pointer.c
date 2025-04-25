#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int arr[][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("arr\t\t-->%p\n", arr);
    printf("*arr\t\t-->%p\n", *arr);
    printf("arr[0]\t\t-->%p\n", arr[0]);
    printf("&arr[0]\t\t-->%p\n", &arr[0]);
    printf("&arr[0][0]\t-->%p\n", &arr[0][0]);
    printf("&arr\t\t-->%p\n", &arr);
    // &arr 是整个数组 arr 的地址，它的类型是 int (*)[2][3]，也就是说它是指向整个二维数组的指针。
    // 这是一个指向二维数组的指针，和 arr 的地址相同，因为 arr 代表了整个二维数组。

/*
arr             -->0x7ffea8c0eb10
*arr            -->0x7ffea8c0eb10
arr[0]          -->0x7ffea8c0eb10
&arr[0]         -->0x7ffea8c0eb10
&arr[0][0]      -->0x7ffea8c0eb10
&arr            -->0x7ffea8c0eb10
arr 和 *arr 都指向二维数组的第一行，arr[0]。
arr[0] 和 *arr 的地址相同，都是指向数组第一行的地址。
&arr[0] 和 arr 也相同，因为它们都是指向数组第一行的指针。
&arr[0][0] 是二维数组的第一个元素的地址。

arr 代表的是整个二维数组，它的类型是 int[2][3]，指向整个数组的起始位置。它的地址是数组的起始位置，也就是 arr[0] 的地址。对于二维数组，arr 其实是一个指向二维数组首行的指针。

*arr 实际上是 arr[0]，即数组的第一行。它是一个指向 arr[0][0] 的指针，类型是 int[3]。因此，*arr 会指向数组的第一个元素 {1, 2, 3}。因为二维数组是连续存储的，arr 和 *arr 都指向内存中的同一位置。

arr[0] 是二维数组的第一行，它是一个 int[3] 数组，指向第一个元素 arr[0][0]。这个地址和 *arr 是相同的，因为 arr[0] 是 *arr 的值。

&arr[0] 是数组的第一行 arr[0] 的地址。它与 arr 和 *arr 相同，因为 arr[0] 和 *arr 本质上指向同一内存位置。

&arr[0][0] 是数组的第一个元素的地址，这个地址位于内存的第一个位置，是二维数组的起始位置。这个地址是最小的内存单元的地址。
*/

        int a = 42;
        int *p = &a;      // 一级指针，p指向a
        int **pp = &p;    // 二级指针，pp指向p
    
        // 输出每个变量的值
        printf("a \t= %d\n", a);         // 42
        printf("*p \t= %d\n", *p);       // 42
        printf("**pp \t= %d\n", **pp);   // 42
    
        // 输出地址
        printf("(void*)&a \t= %p\n", (void*)&a);
        printf("(void*)p \t= %p\n", (void*)p);
        printf("p \t\t= %p\n", p);

        printf("\n");
        printf("&p \t\t= %p\n", &p);
        printf("(void*)*pp \t= %p\n", (void*)*pp);
        printf("(void*)pp \t= %p\n", (void*)pp);

    exit(0);
}