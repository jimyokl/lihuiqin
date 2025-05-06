#include <stdio.h>                                          //4,求矩阵乘积
#include <stdlib.h>
static void print_matrix(int **matrix, int row, int column);
static void init_matrix(int **matrix, int row, int col);
static void free_mem(int **matrix, int row);

static int ** matrix_product(int **three_two, int **two_three, int row, int col)
{
    int i,j,k;
    int **result=(int **)malloc( row*sizeof(int*) );
    for(i=0;i<row;i++)
        result[i]=(int*)malloc( col*sizeof(int) );

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            result[i][j]=0;
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            for(k=0;k<2;k++)
               result[i][j] = result[i][j] + three_two[i][k]*two_three[k][j];
        }
    }
    return result;
}
int main()
{
    int i, row_n_3_2=3, col_n_3_2=2, row_n_2_3=2, col_n_2_3=3;
    int **three_two=(int**)malloc( sizeof(int*)*row_n_3_2 );
    for(i=0;i<row_n_3_2;i++)
        three_two[i]= (int*)malloc( sizeof(int)*col_n_3_2 );
    
    int **two_three=(int**)malloc( sizeof(int*)*row_n_2_3 );
    for(i=0;i<row_n_2_3;i++)
        two_three[i]= (int*)malloc( sizeof(int)*col_n_2_3 );

    init_matrix(three_two, row_n_3_2, col_n_3_2);
    init_matrix(two_three, row_n_2_3, col_n_2_3);

    int **product=matrix_product(three_two, two_three, row_n_3_2, col_n_2_3);
    printf("product of two matrix:\n");
    print_matrix(product, row_n_3_2, col_n_2_3);

    free_mem(three_two, row_n_3_2);
    free_mem(two_three, row_n_2_3);
    free_mem(product, row_n_3_2);

    exit(0);
}
static void init_matrix(int **matrix, int row, int col)
{
    printf("into %s:\n", __func__);
    int i,j;
    for(i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            matrix[i][j] = i*i + j*2;
    }
    print_matrix(matrix, row, col);
    printf("\n");
}
static void free_mem(int **matrix, int row)
{
    int i;
    for(i=0;i<row;i++)
    {
        if(matrix[i])
        {
            free(matrix[i]); matrix[i]= NULL;
        }
    }
    if(matrix)
    {
        free(matrix); matrix=NULL;
    }
}
static void print_matrix(int **matrix, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}
