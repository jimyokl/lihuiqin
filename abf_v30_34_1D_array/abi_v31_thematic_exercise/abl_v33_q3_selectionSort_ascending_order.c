// 选择排序 (Selection Sort), 平均时间复杂度O(n²) 空间复杂度O(1) 不稳定,小规模数据，交换次数少
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
int main()
{
    int arr[10] = {0}, i, j, temp, temp_min;
    srand((unsigned int)time(NULL));
    for(i=0;i<SIZE;i++)
    {
        arr[i]=rand()%100;
	    printf("%d ", arr[i]);
    }

    printf("\nnow begin to sort, ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0])-1;i++)
    {
        for(j=i,temp=j;j<SIZE-1;j++)
        {
      	    //temp=j;
	    if(arr[temp]>arr[j+1])
	    {
	        temp=j+1;
	    }
        }
	    temp_min = arr[i];
   	    arr[i]= arr[temp];
	    arr[temp]=temp_min;
    }

    printf("after selection sort:\n");
    for(i=0;i<SIZE;i++)
    {
	    printf("%d ", arr[i]);
    }
    printf("\n");

    exit(0);
}

/*
2. 选择排序 (Selection Sort)        by grok
原理: 每次从未排序部分选出最小值，放到已排序部分的末尾。
时间复杂度: 平均、最好、最坏均为 O(n²)。
空间复杂度: O(1)。 特点: 简单，不稳定排序，交换次数少。
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // 假设当前为最小
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // 更新最小值索引
            }
        }
        // 交换最小值到正确位置
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
*/