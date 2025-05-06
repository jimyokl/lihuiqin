// 2,求最大值及其所在位置
// 3,求各行和各列的和
#include <stdio.h>
#include <stdlib.h>
static void printArr();
static void max();
static void sum(int **arr, int row_n, int col_n)
{
    int i,j,sum_row=0, sum_col=0;
    printf("\nnow in function: %s\n", __func__);
    printArr(arr, row_n, col_n); printf("\n");
    for(i=0;i<row_n;i++)
    {
        for(j=0, sum_row=0;j<col_n;j++)
        {
            sum_row= sum_row + arr[i][j];
        }
        printf("sum of row %d is: %d\n", i+1, sum_row);
    }
    printf("\n");
    for(i=0;i<col_n;i++)
    {
        for(j=0, sum_col=0;j<row_n;j++)
        {
            sum_col= sum_col + arr[j][i];
        }
        printf("sum of column %d is: %d\n", i+1, sum_col);
    }
    printf("\nleave function: %s\n", __func__);
    return;
}
int main()
{
    int i,j, row_n=3, col_n=4;
    int **arr=(int **)malloc(sizeof(int *) *row_n);
    for(i=0;i<3;i++)
    {
        arr[i]=(int *)malloc(sizeof(int) *col_n);
    }
    // row_n=sizeof(arr)/sizeof(arr[0]); col_n=sizeof(arr[0])/sizeof(arr[0][0]);
    // 这种方式只适用于静态数组
    printArr(arr, row_n, col_n);
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
        {
            arr[i][j]=i*i+j*j+60;
        }
    }
    printArr(arr, row_n, col_n);

    //max();
    sum(arr, row_n, col_n);
    for(i=0;i<3;i++)
    {
        if(arr[i])
        {
            free(arr[i]); arr[i]= NULL;
        }
    }
    if(arr)
    {
        free(arr); arr=NULL;
    }
    exit(0);
}
static void max()
{
    int arr[][3]={ {11,22,33} , {44,55} }, i, j, max, max_row, max_col;
    int row_n = sizeof(arr)/sizeof(arr[0]);
    max=arr[0][0], max_row=0, max_col=0;
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]>max)
            {
                max=arr[i][j];
                max_row=i, max_col=j;
            }
        }
    }
    printf("max=%d, max_row=%d, max_col=%d, arr[%d][%d].\n", max, max_row, max_col, max_row, max_col);

    for(i=0;i<row_n;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}
static void printArr(int **arr, int row, int col)
{
    int i, j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}