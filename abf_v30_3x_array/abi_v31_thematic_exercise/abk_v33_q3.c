// 选择排序 (Selection Sort) 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
static void selection()
{
    
    {
        int ran_arr[SIZE], i, j, max_temp, temp;
        srand((unsigned int)time(NULL)); // srand(time(NULL));
        for(i=0; i<SIZE;i++)
        {
            ran_arr[i]=rand()%100;
            printf("%d ", ran_arr[i]);
        }
        printf("\nnow begin to sort,");
        for(i=0;i<SIZE-1;i++)
        {
            for(j=0, temp=j; j<SIZE-i-1;j++)
            {
                if(ran_arr[temp]<ran_arr[j+1])
                {
                    temp = j+1;
                }
            }
            max_temp=ran_arr[temp];
            ran_arr[i]=max_temp;
            ran_arr[temp] = ran_arr[i];


        }
        printf("after bubble sort:\n");
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

// 快速排序 (Quick Sort)








// 1.进制转换













// 3.删除法求质数