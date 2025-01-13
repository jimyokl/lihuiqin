#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <string.h>
int main()
{
    FILE *fp = NULL;
    fp = fopen("tmp", "r"); //当前目录下没有tmp文件，只读模式下要求文件一定存在, fopen肯定会失败，返回NULL
    if(fp == NULL){ //fopen返回值是FILE *, 失败返回NULL，设定errorno
        //strerror(errno); //由于用到了errno, 需要包含errno.h头文件
        fprintf(stderr, "fopen failed on Boox: %s\n", strerror(errno)); //strerror(errno)返回char*字符串错误信息
        //perror("fopen failed");
        exit(1);
    }
    puts("fopen success");
    exit(0); 
}
// gcc warning_lead_to_segment_fault.c, 会报warning, 老版本的gcc不会报warning, 但是运行./a.out, 会报segmentation fault,
// 加上-Wall: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘int’
// 这里说它返回int,说明隐式声明后返回值是int, strerror的man文件char *strerror(int errnum), 2者类型不一致,所以这里其实是个error

// ?后面的link的时候,可能编译器自动添加了一些库，所以可能实际上返回值是char *,
// ./a.out, 这里会报segmentation fault, 
// 因为strerror(errno)返回的是一个指向静态内存的指针，这个指针指向的内存是只读的，不能修改，但是这里却试图修改它，
