// 选择排序 (Selection Sort), 平均时间复杂度O(n²) 空间复杂度O(1) 不稳定,小规模数据，交换次数少
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
static void selection_sort()
{
        int ran_arr[SIZE], i, j, max_temp, temp;
        srand((unsigned int)time(NULL));            //srand(time(NULL));
        for(i=0; i<SIZE;i++)
        {
            ran_arr[i]=rand()%100;
            printf("%d ", ran_arr[i]);
        }
        printf("\nnow begin to sort,");
        for(i=0;i<sizeof(ran_arr)/sizeof(ran_arr[0])-1;i++)
        {
            for(j=i, temp=j; j<SIZE-1;j++)
            {
                if(ran_arr[temp]<ran_arr[j+1])
                {
                    temp = j+1;
                }
            }
            max_temp=ran_arr[temp];
            ran_arr[temp] = ran_arr[i];
            ran_arr[i]=max_temp;
        }
        printf("after selection sort:\n");
        for(i=0;i<SIZE;i++)
        {
            printf("%d ", ran_arr[i]);
        }
        printf("\n");
}
int main()
{
    selection_sort();
    exit(0);
}

