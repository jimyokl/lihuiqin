#include <stdio.h>
void printArray(int *arr, int rows, int cols) 
{
    printf("arr in %s\t-->%p\n", __func__, arr);//-->0x7ffebf9be5c0
    printf("*arr in %s\t-->%d\n", __func__, *arr); //4
    // printf("*arr in %s\t--->%p\n", __func__, *arr);
    printf("*(arr+sizeof(int*)) in %s\t--->%d\n", __func__, *( (arr+ 1*2 ) + 1 ));//只偏移3,即a[0+3],连续内存第4个元素
}
int main() 
{
    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}  };
    printf("sizeof(int*)=%ld\n\n", sizeof(int*));             //8
    printf("arr in %s\t-->%p\n", __func__, arr); //-->0x7ffebf9be5c0

    printf("*( *(arr+sizeof(int*) ) +sizeof(int*) ) in %s\t--->%d\n", __func__, *( *(arr+1)  +1 )  );//5
    printArray(arr, 3, 3);
    return 0;
}