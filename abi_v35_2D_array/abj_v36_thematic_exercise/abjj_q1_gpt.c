//# 非方阵的转置（C语言实现）

//非方阵的转置是指将矩阵的行和列互换，对于一个m×n的矩阵，转置后会得到一个n×m的矩阵。

// ### 1. 动态分配内存实现

#include <stdio.h>
#include <stdlib.h>

// 转置函数
int** transpose(int** matrix, int rows, int cols) {
    // 分配转置后的矩阵内存 (cols行×rows列)
    int** result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    
    // 执行转置
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}

// 打印矩阵
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2, cols = 3;
    
    int** matrix = (int**)malloc(rows * sizeof(int*));    // 创建原始矩阵
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    int value = 1;                                          // 初始化矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    printf("Original matrix (%dx%d):\n", rows, cols);
    printMatrix(matrix, rows, cols);
    
    // 转置矩阵
    int** transposed = transpose(matrix, rows, cols);
    
    printf("\nTransposed matrix (%dx%d):\n", cols, rows);
    printMatrix(transposed, cols, rows);
    
    // 释放内存
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    
    for (int i = 0; i < cols; i++) free(transposed[i]);
    free(transposed);
    
    return 0;
}