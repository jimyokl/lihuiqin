//  1,行列互换
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr_two_three[][3]={  {11,22,33}, {44,55,} }, row_n, col_n, i,j,temp;
    
    row_n = sizeof(arr_two_three)/sizeof(arr_two_three[0]);
    col_n = sizeof(arr_two_three[0])/sizeof(arr_two_three[0][0]);
    printf("arr_two_three: row_n=%d, col_n=%d\n", row_n, col_n);
    
    int **arr_three_two = (int **)malloc(col_n * sizeof(int *));  // 为行分配内存

    for (i = 0; i < col_n; i++)
      arr_three_two[i] = (int *)malloc(row_n * sizeof(int));  // 为每一行分配内存

    printf("\narr_two_three:\n");
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
          printf("arr_two_three[%d][%d]=%d    ",i,j,arr_two_three[i][j]);
        printf("\n");
    }
    printf("\narr_three_two\n");
    for(i=0;i<col_n;i++)
    {
        for(j=0;j<row_n;j++)
          printf("arr_three_two[%d][%d]=%d    ",i,j,arr_three_two[i][j]);
        printf("\n");
    }

    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
        {
            temp=arr_two_three[i][j];
            arr_two_three[i][j]=arr_three_two[j][i];
            arr_three_two[j][i]=temp;
        }
    }
    // row_n = sizeof(arr_three_two)/sizeof(arr_three_two[0]);
    // col_n = sizeof(arr_three_two[0])/sizeof(arr_three_two[0][0]);
    // printf("arr_three_two row_n=%d, col_n=%d\n", row_n, col_n);
    printf("\nafter exchange, arr_three_two:\n");
    for(i=0;i<col_n;i++)
    {
        for(j=0;j<row_n;j++)
          printf("arr_three_two[%d][%d]=%d    ",i,j,arr_three_two[i][j]);
        printf("\n");
    }

    printf("\nafter exchange, arr_two_three:\n");
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
          printf("arr_two_three[%d][%d]=%d    ",i,j,arr_two_three[i][j]);
        printf("\n");
    }

    for(i=0;i<col_n;i++)
    {
        if(arr_three_two[i] != NULL)
        {
            free(arr_three_two[i]);  // 释放每一行的内存
            arr_three_two[i] = NULL; // 避免悬空指针
        }
    }
    if(arr_three_two != NULL)
        {
            free(arr_three_two);  // 释放行指针数组的内存
            arr_three_two = NULL; // 避免悬空指针
        }
    printf("\nmem freed.\n");

    exit(0);
}
