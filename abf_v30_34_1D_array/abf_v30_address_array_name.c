#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
//数组名（如arr）在C中本质上是对这块连续内存的起始地址的引用，但它不仅仅是一个指针，而是一个数组类型的符号。
//在定义int arr[5]时，编译器为arr分配了5个int的内存，并将arr记录为一个数组类型（int[5]），
//这个类型包含了数组的元素类型和长度信息。

//编译时，C编译器为每个变量维护一个符号表，记录变量的类型和大小。对于数组arr，符号表中存储的信息是“类型为int[5]

void func(int arr[]) 
{
    printf("int arr_name[5], now arr_name as a function parameter, size: %zu\n", sizeof(arr)); // 输出: 8（指针大小，假设64位系统）
}
int main(void)
{    
    static int arr[SIZE];        // int arr[SIZE], 如果不初始化，是随机值, 加上static后自动初始化为0
    char ch_arr[SIZE]={0};  
    int *p_arr = malloc(SIZE * sizeof(int));
    if (p_arr == NULL)
    {
        printf("Memory allocation failed\n"); exit(1);
    }
    // 初始化
    //questions/201101/how-can-i-initialize-all-members-of-an-array-to-the-same-value, int Array[10]={0};
    //questions/2589749/how-to-initialize-array-to-0-in-c#, char ARRAY[1024]={0};memset(ARRAY,0,1024)
    // int i=3;  int var_arr[i]={0};
    // VLA(Variable Length Array，变长数组)不允许= {1, 2, 3}这样的方式初始化，因为编译器在编译时不知道n的值
    // for (int i = 0; i < n; i++) { arr[i] = i + 1;  // 使用循环赋值 ok }
    printf("\n****************************************array initialization****************************************\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("arr[%d]=%d, ", i, arr[i]);
        printf("ch_arr[%d]=%c.\n", i, ch_arr[i]);
    }
    printf("\n****************************************数组的size****************************************\n");
    printf("int arr[SIZE], size=3, %lu\n", sizeof(arr));
    printf("*p_arr = malloc(SIZE * sizeof(int)): %lu\n", sizeof(p_arr));
    char str[] = "hello";
    printf("str[] = ""hello"", size:%zd\n",sizeof(str));
    printf("\n****************************************array address pointer****************************************\n");
    for(int i=0;i<3;i++)
        printf("arr[SIZE], %p-->%d\n", &arr[i], arr[i]);
    for(int i=0;i<3;i++)
    printf("p->malloc size*int; %p-->%d\n", &p_arr[i], p_arr[i]);
    printf("\n****************************************array name address pointer****************************************\n");
    printf("name arr: %p, &arr[0]:%p\n", arr, &arr[0]);
    printf("*p_arr = malloc(SIZE * sizeof(int: %p\n", p_arr);    

    printf("\n****************************************array name decays to a pointer****************************************\n");    
    int arr_name[5] = {1, 2, 3, 4, 5};
    printf("int arr_name[5], size:%zu\n", sizeof(arr_name)); // 输出: 20（整个数组大小）
    func(arr_name);
 

    exit(0);
}