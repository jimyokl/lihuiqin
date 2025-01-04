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
proprocess -> compile -> assemble -> link -> load
proprocess预处理,处理编译之前#号相关的,主要处理#include、#define、#ifdef、#endif等预处理指令
*/

int main(void) {
    printf("Hello, world!\n");
    exit(0);
    // return 0;    
    printf("This line will not be executed.\n")
}

