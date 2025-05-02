#include <stdio.h>
#include <stdlib.h>

int* transpose(int* matrix, int rows, int cols) {
    int* result = (int*)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) {
            result[j * rows + i] = matrix[i * cols + j];
        }
    }
    
    return result;
}
void printMatrix(int* matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
            printf("%d ", matrix[i * cols + j]);
        printf("\n");
    }
}
int main() 
{
    int rows = 2, cols = 3;
    int* matrix = (int*)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows * cols; i++) // 初始化
        matrix[i] = i + 1;
    
    printf("Original matrix (%dx%d):\n", rows, cols);
    printMatrix(matrix, rows, cols);
    
    int* transposed = transpose(matrix, rows, cols);
    
    printf("\nTransposed matrix (%dx%d):\n", cols, rows);
    printMatrix(transposed, cols, rows);
    
    free(matrix);
    free(transposed);
    
    return 0;
}