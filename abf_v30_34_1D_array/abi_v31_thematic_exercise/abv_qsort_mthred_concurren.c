// 下面是一个使用多线程封装 qsort 的并发版本程序示例，使用 C 语言和 POSIX 线程（pthreads）。这个示例将大数组分成多个子数组，分别在不同线程中进行快速排序，最后合并结果。
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// 线程参数结构体
typedef struct {
    int *arr; // 待排序数组
    int left; // 左边界
    int right; // 右边界
} ThreadArg;

// 比较函数，用于 qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 线程执行的排序函数
void *thread_sort(void *arg) {
    ThreadArg *targ = (ThreadArg *)arg;
    qsort(targ->arr + targ->left, targ->right - targ->left + 1, sizeof(int), compare);
    return NULL;
}

// 合并两个已排序的子数组
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// 并行快速排序封装
void parallel_qsort(int *arr, int size, int num_threads) {
    if (size <= 0 || num_threads <= 0) return;
    
    // 限制线程数不超过数组大小
    num_threads = num_threads > size ? size : num_threads;
    
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    ThreadArg *args = malloc(num_threads * sizeof(ThreadArg));
    
    // 计算每个线程的子数组大小
    int chunk_size = size / num_threads;
    int remaining = size % num_threads;
    
    // 创建线程
    for (int i = 0; i < num_threads; i++) {
        args[i].arr = arr;
        args[i].left = i * chunk_size + (i < remaining ? i : remaining);
        args[i].right = args[i].left + chunk_size - 1 + (i < remaining ? 1 : 0);
        if (i == num_threads - 1) args[i].right = size - 1; // 最后一个线程处理剩余部分
        
        pthread_create(&threads[i], NULL, thread_sort, &args[i]);
    }
    
    // 等待所有线程完成
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // 合并已排序的子数组
    for (int step = 1; step < num_threads; step *= 2) {
        for (int i = 0; i < num_threads; i += 2 * step) {
            if (i + step < num_threads) {
                int left = args[i].left;
                int mid = args[i + step - 1].right;
                int right = args[i + step].right;
                merge(arr, left, mid, right);
            }
        }
    }
    
    free(threads);
    free(args);
}

// 测试程序
int main() {
    int size = 1000000;
    int num_threads = 4;
    
    // 生成随机数组
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }
    
    // 打印部分原始数组
    printf("Original array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 执行并行排序
    parallel_qsort(arr, size, num_threads);
    
    // 打印部分排序结果
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 验证排序是否正确
    int sorted = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = 0;
            break;
        }
    }
    printf("Array is %s\n", sorted ? "sorted" : "not sorted");
    
    free(arr);
    return 0;
}
/*
多线程划分：
数组被分成 num_threads 个子数组，每个子数组分配给一个线程。
使用 chunk_size 和 remaining 确保数组均匀分配，最后一个线程处理剩余部分。

线程执行：
每个线程调用标准库的 qsort 对子数组进行排序。
ThreadArg 结构体传递线程所需的参数（数组、左右边界）。

合并阶段：
线程排序完成后，使用归并排序的合并逻辑将已排序的子数组合并为一个完整排序数组。
合并是逐步进行的，类似于归并排序的合并阶段。

特点：
使用 POSIX 线程（pthreads），适用于 Linux/Unix 系统。
动态分配线程数，最多不超过数组大小。
包含验证逻辑，确保排序结果正确。

编译与运行：
编译：gcc -o parallel_qsort parallel_qsort.c -pthread
运行：./parallel_qsort
需要 POSIX 线程支持，Windows 用户需使用其他线程库（如 Win32 线程）或 C11 线程。

注意事项：
性能：多线程排序的性能依赖于线程数、数组大小和硬件核心数。过多的线程可能导致上下文切换开销。
内存：合并阶段需要额外的内存，适合大数组但需注意内存使用。
改进方向：可以引入任务队列或线程池来动态管理任务，减少线程创建/销毁的开销。
*/