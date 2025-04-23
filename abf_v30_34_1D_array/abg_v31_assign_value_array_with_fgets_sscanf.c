#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int array[3] = {0}; char str[100] = {0};
    for(int i = 0; i < 3; i++)
    {
        printf("Enter a number to assign to array[%d]: ", i);
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0; // Remove newline character
        if (sscanf(str, "%d", &array[i]) != 1)
        {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            exit(1);
        }
        printf("now array[%d] = %d\n", i, array[i]);
    }
    printf("The final array now is:\n");
    for(int i = 0; i < 3; i++)
        printf("array[%d] = %d\n", i, array[i]);
    exit(0);
}