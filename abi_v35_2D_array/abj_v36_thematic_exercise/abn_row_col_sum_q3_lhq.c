// 3,求各行和各列的和
#include <stdio.h>
#include <stdlib.h>
static void printArr();
static void sum(int **arr, int extra_row, int extra_col)
{
    int i,j;
    printf("\nnow in function: %s\n", __func__);
    printArr(arr, extra_row, extra_col); printf("\n");
    for(i=0;i<extra_row-1;i++)
    {
        for(j=0;j<extra_col-1;j++)
        {
            arr[extra_row-1][extra_col-1]= arr[extra_row-1][extra_col-1] + arr[i][j];
            arr[extra_row-1][j]= arr[extra_row-1][j] + arr[i][j];
            arr[i][extra_col-1]= arr[i][extra_col-1]+ arr[i][j];
        }
    }
    printArr(arr, extra_row, extra_col);
    printf("\nleave function: %s\n", __func__);
    return;
}
int main()
{
    int i,j, row_n=3, col_n=4, extra_row=4, extra_col=5;
    int **arr=(int **)malloc(sizeof(int *) *extra_row);
    for(i=0;i<extra_row;i++)
    {
        arr[i]=(int *)malloc(sizeof(int) *extra_col);
    }
    // row_n=sizeof(arr)/sizeof(arr[0]); col_n=sizeof(arr[0])/sizeof(arr[0][0]);
    // 这种方式只适用于静态数组
    printArr(arr, extra_row, extra_col);
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
        {
            arr[i][j]=i*i+j*j+60;
        }
    }
    printArr(arr, extra_row, extra_col);

    sum(arr, extra_row, extra_col);
    for(i=0;i<extra_row;i++)
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
static void printArr(int **arr, int row, int col)
{
    int i, j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%4d  ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}