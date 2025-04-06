#include <stdio.h>
#include <stdlib.h>

#define RIGHT 100
#define LEFT  1

int main() 
{
    int sum = 0, i = LEFT;
/*    do
    {
        sum += i;
        i++;
    } while (i <=RIGHT);
*/
    while(i <= RIGHT)
    {
        sum = sum+i;
        i++;
    }

    printf("1-100 Sum: %d\n", sum);
    exit(0);
}
// The program calculates the sum of numbers from 1 to 100 using a do-while loop.