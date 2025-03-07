#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char str[100];
    printf("Enter a string, then press Enter:\n");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s\n", str);
    // str[strcspn(str, "\n")] = '\0';  // 去除换行符


    // FILE *fp;
    // char str[60];

    // /* opening file for reading */
    // fp = fopen("file.txt" , "r");
    // if(fp == NULL) {
    //     perror("Error opening file");
    //     return(-1);
    // }
    // if(fgets(str, 60, fp) != NULL) {
    //     printf("%s", str);
    // }
    // fclose(fp);
    
    exit(0);
}   