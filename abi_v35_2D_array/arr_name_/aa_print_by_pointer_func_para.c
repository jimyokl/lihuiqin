#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

static void print2DArray(int arr[M][N], int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
            printf("%d ", *(   *(arr + i) + j    )     );
        printf("\n");
    }
}
//static void print_array(int arr[M][N])  //没问题

//static void print_array(int* arr)
//error: j of arr[i][j], subscripted value is neither array nor pointer nor vector

// static void print_array(int **arr)
// {   
//     printf("into function %s\n", __func__);
//     printf("arr[0][0]=%d\n", arr[0][0]);
//     int i=0,j=0;
//     for(i=0;i<M;i++)
//     {
//         for(j=0;j<N;j++)
//         {
//             printf("arr[%d][%d]=%d                 ", i,j,arr[i][j]);
//         }
//         printf("\n");
//     }
// }

int main()
{
    int arr_two_three[][3] = 
    {
        {11, 22, 33},44,55
    };

    int rows = sizeof(arr_two_three) / sizeof(arr_two_three[0]);  // 总字节数/每行的字节数
    int cols=sizeof(arr_two_three[0]) / sizeof(arr_two_three[0][0]);  //列数=每行字节数/每个元素的字节数

    printf("arr_three_three[][3] = {  {11, 22, 33},44  }，行数: %d\n", rows);
    printf("arr_three_three[][3] = {  {11, 22, 33},44  }，列数: %d\n", cols);

    printf("\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("arr_three_three[%d][%d]=%d-->%p  ", i,j,arr_two_three[i][j],&arr_two_three[i][j]);
        }
        printf("\n");
    }
    printf("\nprint by print_array(int arr[M][N]):\n");
    // print_array(arr_two_three);  // 传递二维数组的首地址

    printf("\nprint by print2DArray(int *arr, int rows, int cols):\n");
    //print2DArray(arr_two_three, rows, cols);  // 传递二维数组的首地址和行列数
    //warn: passing argument 1 of ‘print2DArray’ from incompatible pointer type [Wincompatible-pointer-types]
    // expected ‘int *’ but argument is of type ‘int (*)[3]’
    print2DArray(&arr_two_three[0][0], rows, cols);

    exit(0);  // 退出程序
}