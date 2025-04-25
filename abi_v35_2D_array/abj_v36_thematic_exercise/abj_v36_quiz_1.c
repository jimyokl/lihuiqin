//  1,行列互换
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr_two_three[][3]={  {11,22,33}, {44,55,} }, row_n, col_n, i,j,temp;
    
    row_n = sizeof(arr_two_three)/sizeof(arr_two_three[0]);
    col_n = sizeof(arr_two_three[0])/sizeof(arr_two_three[0][0]);
    printf("arr_two_three row_n=%d, col_n=%d\n", row_n, col_n);
    
    int **arr_three_two = (int **)malloc(col_n * sizeof(int *));  // 为行分配内存

    for (int i = 0; i < col_n; i++)
      arr_three_two[i] = (int *)malloc(row_n * sizeof(int));  // 为每一行分配内存

    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
          printf("arr_two_three[%d][%d]=%d    ",i,j,arr_two_three[i][j]);
        printf("\n");
    }
    printf("\n");

    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
        {
            arr_three_two[j][i]=arr_two_three[i][j];
            temp=arr_two_three[i][j];
            arr_two_three[i][j]=arr_two_three[j][i];
            arr_two_three[j][i]=temp;
        }
    }

    // row_n = sizeof(arr_three_two)/sizeof(arr_three_two[0]);
    // col_n = sizeof(arr_three_two[0])/sizeof(arr_three_two[0][0]);
    // printf("arr_three_two row_n=%d, col_n=%d\n", row_n, col_n);

    for(i=0;i<col_n;i++)
    {
        for(j=0;j<row_n;j++)
          printf("arr_three_two[%d][%d]=%d    ",i,j,arr_three_two[i][j]);
        printf("\n");
    }

        printf("\n");
    for(i=0;i<row_n;i++)
    {
        for(j=0;j<col_n;j++)
          printf("arr_two_three[%d][%d]=%d    ",i,j,arr_two_three[i][j]);
        printf("\n");
    }

    exit(0);
}
