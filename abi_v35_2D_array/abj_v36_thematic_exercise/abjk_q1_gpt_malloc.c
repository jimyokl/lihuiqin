
//### 2. 使用一维数组模拟二维数组实现

#include <stdio.h>
#include <stdlib.h>

int* transpose(int* matrix, int rows, int cols) {
    int* result = (int*)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j * rows + i] = matrix[i * cols + j];
        }
    }
    
    return result;
}

void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2, cols = 3;
    int* matrix = (int*)malloc(rows * cols * sizeof(int));
    
    // 初始化
    for (int i = 0; i < rows * cols; i++) {
        matrix[i] = i + 1;
    }
    
    printf("Original matrix (%dx%d):\n", rows, cols);
    printMatrix(matrix, rows, cols);
    
    int* transposed = transpose(matrix, rows, cols);
    
    printf("\nTransposed matrix (%dx%d):\n", cols, rows);
    printMatrix(transposed, cols, rows);
    
    free(matrix);
    free(transposed);
    
    return 0;
}
/*
## 关键点说明

1. **维度变化**：转置后矩阵的行数变为原矩阵的列数，列数变为原矩阵的行数
2. **元素位置**：原矩阵中matrix[i][j]变为转置矩阵中result[j][i]
3. **内存管理**：
   - 必须为转置后的矩阵分配新的内存空间
   - 转置完成后要记得释放所有分配的内存

## 示例输出

对于2×3矩阵：
```
1 2 3
4 5 6
```

转置后得到3×2矩阵：
```
1 4
2 5
3 6
*/