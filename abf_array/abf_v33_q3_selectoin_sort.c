#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
    int arr[10] = {4,3,9,8,1,0,7,5,2,6}, i, j, temp, temp_min;
    for(i=0;i<SIZE;i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");

    for(i=0;i<SIZE-1;i++)
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

    for(i=0;i<SIZE;i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");

    exit(0);
}
