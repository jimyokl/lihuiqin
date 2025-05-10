#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
static void quiz_ten()
{
    char str[100]=""; int num=0;
    printf("pls input how many stars each side of rhombus:");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &num); 
    for(int i =0; i<num; i++)
    {
	for(int j=0;j<num-i-1;j++)
	{
	    printf(" ");
	}
	for(int k=0; k<i+1;k++)
	{
	    printf("* ");
	}
    	printf("\n");
    }
    for(int i =0; i<num-1; i++)
    {
	for(int j=0;j<i+1;j++)
	{
	    printf(" ");
	}
	for(int k=0; k<num-i-1;k++)
	{
	    printf("* ");
	}
    	printf("\n");
    }
    return;
}
int main()
{
    quiz_ten();
    exit(0);

}
