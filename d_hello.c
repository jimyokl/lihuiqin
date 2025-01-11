#include <stdio.h>
#include <stdlib.h>

/*
void main(void); 
int main(void);

void main(int argc, char **argv);
void main(int argc, char *argv[]);

int main(int argc, char **argv);
int main(int argc, char *argv[]);

//最开始没有void类型，所有main函数都是int，后来创建了void类型，main就开始用void类型。
//有的编译器认为main函数作为程序的入口，也是程序出口，不需要返回值

preprocessor -> compiler -> assembler -> linker -> loader
proprocess -E -> compile -S产生汇编文件 -> 有了汇编文件后，对汇编文件进行汇编assemble汇编 -> link链接 -> load
proprocess预处理,处理编译之前#号相关的,主要处理#include、#define、#ifdef、#endif等预处理指令

-E  Stop after the preprocessing stage; do not run the compiler proper.  The output is in the form of preprocessed source code, which is sent to the standard output.
    Input files that don't require preprocessing are ignored.
-S  Stop after the stage of compilation proper; do not assemble.  
    The output is in the form of an assembler code file for each non-assembler input file specified.
    By default, the assembler file name for a source file is made by replacing the suffix .c, .i, etc., with .s.
    Input files that don't require compilation are ignored.
-c  Compile or assemble the source files, but do not link.  The linking stage simply is not done.  
    The ultimate output is in the form of an object file for each source file.
    By default, the object file name for a source file is made by replacing the suffix .c, .i, .s, etc., with .o.
-o 如果不指定输出文件名，那么默认输出文件名是a.out. (这一步是链接吗?)

make hello
cc     hello.c   -o hello //cc是预定义好的一个名字,cc默认是gcc的一个符号链接,指向gcc
  //如果make hello.c,会去找hello.c.c，不存在

*/

int main(void) {
	printf("Hello, world!\n");
    //	exit(0);
    //  return 0;    
    //printf("This line will not be executed.\n")
}

