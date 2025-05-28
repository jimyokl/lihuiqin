
typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix create_matrix(int rows, int cols) 
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
    {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}