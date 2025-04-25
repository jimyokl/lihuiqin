#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 2
int main()
{
    int i=0,j=0, arr[M][N]=
    {  {1,2},
       {3,4},
       {5,6}   
    };
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("arr[%d][%d]=%d                 ", j,i,arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    int arr_two_three[2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };  // 如果定义为{ {1,3}, {4} }, 则其他未初始化的元素为0
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("arr_two_three[%d][%d]=%d        ", i,j,arr_two_three[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int arr_three_three[][3] = 
    {
        {11, 22, 33},44
    };
    printf("size of arr_three_three = %ld\n", sizeof(arr_three_three));
    int rows = sizeof(arr_three_three) / sizeof(arr_three_three[0]);  // 总字节数/每行的字节数
    int cols=sizeof(arr_three_three[0]) / sizeof(arr_three_three[0][0]);  //列数=每行字节数/每个元素的字节数

    printf("arr_three_three[][3] = {  {11, 22, 33},44  }，行数: %d\n", rows);
    printf("arr_three_three[][3] = {  {11, 22, 33},44  }，列数: %d\n", cols);

    printf("\n");

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("arr_three_three[%d][%d]=%d,--->%p        ", i,j,arr_three_three[i][j],&arr_three_three[i][j]);
        }
        printf("\n");
    }
/*
arr_three_three[0][0]=11,--->0x7ffdc71edb90  arr_three_three[0][1]=22,--->0x7ffdc71edb94  arr_three_three[0][2]=33,--->0x7ffdc71edb98
arr_three_three[1][0]=44,--->0x7ffdc71edb9c  arr_three_three[1][1]=0, --->0x7ffdc71edba0  arr_three_three[1][2]=0,--->0x7ffdc71edba4
0x9c + 0x4 = 0xa0
*/
    printf("arrName add:arr_three_three->%p\n", arr_three_three);

    printf("\n out of col range:\n");
    for(i=0;i<cols;i++)
    {
        for(j=0;j<rows;j++)
        {
            printf("arr_three_three[%d][%d]=%d           ", i,j,arr_three_three[i][j]);
        }
        printf("\n");
    }

    exit(0);
}