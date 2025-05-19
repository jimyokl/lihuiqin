#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char hello[]= "hello";
    char world[]= "world";
    printf("size of \"hello\" is %zu, with sizeof.\n", sizeof(hello));    // 6
    printf("strcat function:\n");
    // strcat(hello, ",,");
    // strncat(hello, ",,", sizeof(hello)-strlen(hello)-1 ); // 只拷贝到\0为止
    strncpy(hello, ",world", sizeof(hello) ); // 只拷贝到\0为止
    puts(hello);


    char catena_str[7]="catena";
    char overrun_str[8]="overrun";
    char ccpp[4]={'c','c', 'p', 'p'};
    strncat(catena_str,ccpp, 1);
    puts(catena_str);

    printf("\nsize of \"hello\" is %zu, with sizeof.\n", sizeof(hello));    // 6

    exit(0);
}


[System.Environment]::SetEnvironmentVariable

("Path", `
    
  [Microsoft.Win32.Registry]::GetValue
    (
      "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment", 
      "Path",
       ""
    ),

"Process")