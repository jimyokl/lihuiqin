#include <stdio.h>
void printArray(int *arr, int rows, int cols) 
{

    printf("arr in %s\t-->%p\n", __func__, arr);
    // printf("*arr in %s\t--->%p\n", __func__, *arr);
    // printf("*(arr+sizeof(int*)) in %s\t--->%d\n", __func__, **(arr+sizeof(int*)));
    printf("*(arr+sizeof(int*)) in %s\t--->%d\n", __func__, *( (arr+ 1*2 ) + 1 ));//只偏移3,即a[0+3],连续内存的第4个元素
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
            // printf("%d ", arr[i][j]);
            // printf("%d ", *(  (*arr + i*rows) + j)   );
        printf("\n");
    }
}
int main() 
{
    int arr[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("arr[2] in arr[3][3]=%d\n\n", arr[2]); // arr[2] in arr[3][3]=-950937352

    printf("arr in %s\t-->%p\n", __func__, arr);
    printf("*arr in %s\t--->%p\n", __func__, *arr);
    printf("sizeof(int*)=%ld\n\n", sizeof(int*));

    // printf("*(arr+sizeof(int*)) in %s\t--->%d\n", __func__, **(arr+sizeof(int*)));
    printf("*( *(arr+sizeof(int*) ) +sizeof(int*) ) in %s\t--->%d\n", __func__, *( *(arr+1)  +1 )  );
    printArray(arr, 3, 3);
    return 0;
}

/*
arr is of type ‘int (*)[3]’

*/