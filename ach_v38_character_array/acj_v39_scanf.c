#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
    char scanf_str[N] = {'a', 'a', 'a'};
    
    printf("please input one string:\n");
    scanf("%s", scanf_str);
    printf("%s\n", scanf_str);


    char one_str[N], two_str[N], three_str[N];
    printf("\nplease input three strings:\n");
    scanf("%s%s%s", one_str, two_str, three_str);

    printf("\nthree strings you input are:\n");
    printf("%s\n%s\n%s\n", one_str, two_str, three_str);

    exit(0);
}

/*
    解释:The scanf function is equivalent to fscanf with the argument stdin interposed before the argu- ments to scanf. The scanf function returns the value of the macro EOF if an input failure occurs before the ﬁrst 
conversion (if any) has completed. Otherwise, the scanf function returns the number of input items
assigned, which can be fewer than provided for, or even zero, in the event of an early matching
failure.
    The scanf function is equivalent to fscanf with the argument stdin interposed before the arguments to scanf.
    scanf 函数等价于在调用 fscanf 时，将 stdin（标准输入）作为第一个参数传入。也就是说，scanf(...) 实际上相当于 fscanf(stdin, ...)。

    The scanf function returns the value of the macro EOF 
if an input failure occurs before the first conversion (if any) has completed.
    如果在完成任何一次格式转换之前就发生了输入失败（比如用户按下了 Ctrl+D 或读取错误），scanf 会返回宏 EOF 的值，表示输入失败。

    Otherwise, the scanf function returns the number of input items assigned, which can be fewer than provided for, 
or even zero, in the event of an early matching failure.
    否则，scanf 会返回成功赋值的输入项数量（也就是成功读取并存储到变量中的个数）。这个数量可能少于你预期要读取的项数，
甚至可能是 0，比如当输入内容与格式要求不匹配时。

总结：
    scanf(...) 实际上是 fscanf(stdin, ...) 的简写。
    如果输入失败（没有读到任何东西），返回 EOF。
    如果读取了一部分，但有匹配失败，返回成功赋值的个数（可能少于你指定的数量，也可能是 0）。    

示例：
    int a;
    int result = scanf("%d", &a);
    如果用户输入的是一个整数, 比如42, result会是1(表示成功赋值了一个变量).
    如果用户输入的是 hello，因为格式不匹配（不是整数），result 会是0.
    如果遇到文件结束或错误（比如按了 Ctrl+D），result 会是 EOF。



    








s*/

