// 快速排序 (Quick Sort) 
// 可以封装为 多线程/多进程 并发版本，
// 可以练习递归和非递归之间的转换，

/*
3. 快速排序 (Quick Sort)
原理: 选择一个基准值（pivot），将数组分为小于和大于基准的两部分，递归排序子数组。
时间复杂度: 平均 O(n log n)，最坏 O(n²)，最好 O(n log n)。
空间复杂度: O(log n)（递归栈）。 特点: 高效，不稳定排序，常用于实际应用。
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // 小于基准的区域边界
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // 将基准放到正确位置
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取基准位置
        quickSort(arr, low, pi - 1); // 排序左半部分
        quickSort(arr, pi + 1, high); // 排序右半部分
    }
}
使用示例 以下是一个完整的程序，展示如何调用这三种排序方法：
#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 冒泡排序
    printf("冒泡排序前: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("冒泡排序后: ");
    printArray(arr, n);

    // 重置数组
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\n选择排序前: ");
    printArray(arr2, n);
    selectionSort(arr2, n);
    printf("选择排序后: ");
    printArray(arr2, n);

    // 重置数组
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\n快速排序前: ");
    printArray(arr3, n);
    quickSort(arr3, 0, n - 1);
    printf("快速排序后: ");
    printArray(arr3, n);
    return 0;
}
比较总结  排序方法  平均时间复杂度  空间复杂度  稳定性  适用场景  冒泡排序
O(n²)
O(1)
稳定
小规模数据，简单实现
选择排序
O(n²)
O(1)
不稳定
小规模数据，交换次数少
快速排序
O(n log n)
O(log n)
不稳定
大规模数据，高效
选择建议:
小数组或教学用途：冒泡排序、选择排序（简单易懂）。
大数组或性能要求高：快速排序（效率高，C标准库的qsort也是基于快速排序）。
*/