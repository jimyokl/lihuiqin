// 冒泡排序 (Bubble Sort) 
// average time complexity O(n^2)平均和最坏 O(n²)，最好O(n); space complexity O(1)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
static void bubble_sort()
{
    int ran_arr[SIZE], i, j, temp;
    srand((unsigned int)time(NULL)); // srand(time(NULL));
    for(i=0; i<SIZE;i++)
    {
        ran_arr[i]=rand()%100;
        printf("%d ", ran_arr[i]);
    }
    printf("\nnow begin to sort,");
    for(i=0;i<SIZE-1;i++)
    {
        for(j=0; j<SIZE-i-1;j++)
        {
            temp=ran_arr[j];
            if(ran_arr[j]>ran_arr[j+1])
            {
                ran_arr[j]=ran_arr[j+1];
                ran_arr[j+1]=temp;
            }
        }
    }
    printf("after bubble sort:\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ", ran_arr[i]);
    }
    printf("\n");
}
int main(void)
{
    bubble_sort();
    exit(0);
}

/*
1. 冒泡排序 (Bubble Sort) by grok
原理: 相邻元素两两比较，大的往后冒泡，每轮确定一个最大值放在数组末尾。
时间复杂度: 平均和最坏 O(n²)，最好 O(n)。空间复杂度: O(1)。 特点: 简单，稳定排序。
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // 优化：记录是否发生交换
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // 若无交换，数组已有序
    }
}
*/