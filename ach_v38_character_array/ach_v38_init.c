#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 10

int main()
{
    // 单个字符初始化：
    char str[M] = {'p', 'r', 'o', 't', 'o', 'n'}; int i;  //if M==3, for loop i<6, output: pro�C
    printf("init: \t\t\tchar str[6] = {'p', 'r', 'o', 't', 'o', 'n'}, \n");
    printf("print with for loop: \tfor(i=0; i<6; i++)   printf(""%%c"", str[i]: \n");
    for(i=0; i<M; i++)                                    //if M==6, for loop i<9, output: proton:�
        printf("%c", str[i]);       
    printf("\n");

    // 字符串常量初始化：
    char string_literal[N] = "p";
    printf("\ninit: \t\t\tchar string_literal[10] = ""p"";\n");
    printf("print with printf: \tprintf(""%%s"", string_literal);\n");
    printf("%s\n", string_literal);  //输出：p
    printf("\nprint string_literal with for loop: for(i=0; i<10; i++) printf(""%%c"",string_literal[i]):\n");
    for(i=0;i<N;i++)
        printf("%c",string_literal[i]);

    printf("\nprint str[6](""proton"") with puts(): ""puts(str);""\n");
    puts(str);
    
    puts("\npls input a string, we are using gets():"); char str_gets[50];
    gets(str_gets);
    puts(str_gets);

    exit(0);
}

/*          ######*******$$$$$$$$$$$~~~~~~~----   为什么第26一行puts(str)输出“protonp”?   ask gpt

str[6] = {'p', 'r', 'o', 't', 'o', 'n'};  puts(str);

1. str[6]没有 '\0'，不是以null结尾的字符串。
2. puts()从str[0]开始读，一直打印字符，直到遇到 `'\0'` 为止。
       Writes every character from the null-terminated string str and 
   one additional newline character '\n' to the output stream stdout

3. str没有'\0'，会继续从内存中往后读取字符，直到遇到'\0'

4. str之后定义了string_literal[N] = "p";

   "p"是字符串常量，等价于：string_literal[N] = {'p', '\0', 0, 0, ..., 0}; // 总共 N 个字符

   puts(str)输出的是：`proton` + 后面 string_literal 中的 'p'（被当作后续的字符） + ...'\0'为止。

*/