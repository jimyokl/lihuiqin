#include <stdio.h>
#include <stdlib.h>

typedef struct { int** arr; int rows; int cols; } Matrix;

Matrix createMatrix(int rows, int cols) 
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) 
        matrix.arr[i] = (int*)malloc(cols * sizeof(int));
    return matrix;
}

void freeMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) 
        free(matrix->arr[i]);
    free(matrix->arr);
}

int main() 
{
    int rows = 2, cols = 3;
    Matrix m = createMatrix(rows, cols);

    for (int i = 0; i < m.rows; i++) 
        for (int j = 0; j < m.cols; j++) 
            m.arr[i][j] = i * m.cols + j;

    int **temp=m.arr; 
    printf("temp=%p, *temp=%p, **temp=%d\n",temp,*temp, **temp);
    printf("*m.arr+1=%p, *(*m.arr+1)=%d\n",*m.arr+1, *(*m.arr+1));

    for (int i = 0; i < m.rows; i++) 
    {
        for (int j = 0; j < m.cols; j++) 
            printf("%d ", m.arr[i][j]);
        printf("\n");
    }
    freeMatrix(&m); // 释放内存
}