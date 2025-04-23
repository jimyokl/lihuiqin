#include "v31_thematic_exercise.h"
// 1.fibonacci 数列前40项，并逆序存放
static void one_quiz()
{
    int int_arr[40]= {0}, i=0; // j=0, k=1;
    *int_arr=0; *(int_arr+1)=1; *(int_arr+2)=1;
    //for(i=2; i<40; i++)
    for(i=2; i<sizeof(int_arr)/sizeof(int_arr[0]); i++)
    {
        int_arr[i]= int_arr[i-1]+int_arr[i-2]; // general term, general formula
    }
    for(i=0; i<40; i++)
    {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    int temp, arr_size = sizeof(int_arr)/sizeof(int_arr[0]);
    for(i=0; i<arr_size/2; i++)
    {
        temp=int_arr[i];
        int_arr[i]=int_arr[39-i];
        int_arr[39-i]=temp;
    }

    printf("after reverse:\n");
    for(i=0;i<arr_size;i++)
    {
        printf("%d ", int_arr[i]);
    }
    printf("\n");
    return;
}
int main(void)
{

    one_quiz();
    exit(0);
}
//当使用 sizeof(arr) 时，C 语言并不会把 arr 当作一个指针来处理，
//而是当作一个“数组类型”来处理，计算出数组所占的总内存大小。

// int *p = arr; printf("sizeof(p) = %zu\n", sizeof(p));  // 这里 p 是一个指针, 通常是 4 或 8 字节





