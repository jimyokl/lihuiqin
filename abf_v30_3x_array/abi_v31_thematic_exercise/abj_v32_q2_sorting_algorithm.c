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