#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    //最好加上\n，否则可能会出现输出不及时的情况, 因为printf是行缓冲的, 遇到\n才会刷新缓冲区
    printf("to print with function printf,\n");
    printf("it's better to trail a '\\n' in the end to flush, otherwise buffer won't get flushed, nothing to be printed.\n");
    printf("[%s:%d:%s], before while loop.", __FILE__, __LINE__, __func__);
    sleep(5);
    printf("[%s:%d:%s], after while loop.", __FILE__, __LINE__, __func__);

    //到exit之前，并不会刷新缓冲区，所以before和after while loop不会输出
    exit(0); //到了这一句，此时会刷新缓冲区，输出before和after while loop
    //
}