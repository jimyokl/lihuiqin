#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    //最好加上\n，否则可能会出现输出不及时的情况, 因为printf是行缓冲的, 遇到\n才会刷新缓冲区
    // printf("[%s:%d:%s], before while loop.", __FILE__, __LINE__, __func__);
    // while (1)
    // printf("[%s:%d:%s], after while loop.", __FILE__, __LINE__, __func__);
    //这里printf能输出，可能是因为编译器和慧芹老师的版本不一样

    printf("[%s:%d:%s], before while loop.", __FILE__, __LINE__, __func__);
    sleep(5);
    printf("[%s:%d:%s], after while loop.", __FILE__, __LINE__, __func__);
    
//输出：[yan@localhost aaj_v15_16_17_IO]$ ./a.out 
//输出：[aaj_v17_10min_newline_character_flush.c:13:main], before while loop.[aaj_v17_10min_newline_character_flush.c:15:main], after while loop.

    exit(0); //此时会刷新缓冲区，输出before和after while loop
}   
