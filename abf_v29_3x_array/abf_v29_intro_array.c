#include <stdio.h>
#include <stdlib.h>
#define SIZE 333
int main(void)
{
    int arr[SIZE]={0};
    char ch_arr[SIZE]="";
    // int i=3;  int var_arr[i]={0};
    // VLA 不允许用像 = {1, 2, 3} 这样的方式初始化，因为编译器在编译时不知道 n 的值，
    // for (int i = 0; i < n; i++) { arr[i] = i + 1;  // 使用循环赋值 ok }
    for(int i = 0; i < SIZE; i++)
    {
        printf("arr[%d]=%d, ", i, arr[i]);
        printf("ch_arr[%d]=%c.\n", i, ch_arr[i]);
    }
    // questions/201101/how-can-i-initialize-all-members-of-an-array-to-the-same-value    
    // questions/2589749/how-to-initialize-array-to-0-in-c#
    

    exit(0);
}