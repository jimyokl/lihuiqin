#include <stdio.h>
#include <stdlib.h>

// suppressor
// 镇压者, 压制者, 查禁者, 抑制物
// suppressor:sup（=sub 下）+press=压下去=镇压
// 抑制器，阻尼器, 消音器

// %*c 是一种 抑制符（suppressor），用于 读取但丢弃 一个字符
// * 号用于 抑制输入，即 读取但不存储
// 用于清除缓冲区中的多余字符
// 通常用于丢弃 换行符（\n）或其他不需要的字符，避免输入错误或缓冲区问题。

int main()
{
    int num;
    char ch;

    printf("请输入一个整数: ");
    scanf("%d", &num);  // 读取整数
    scanf("%*c");       // 读取并丢弃换行符

    printf("请输入一个字符: ");
    scanf("%c", &ch);   // 读取字符
    printf("你输入的integer and character are: %d, %c\n", num, ch);

    printf("\n请输入一个整数和一个字符: ");
    scanf("%d", &num);  // 读取整数
    scanf("%*c%c", &ch); // 读取并丢弃一个字符，然后读取一个字符
    //此时可以输入一个整数，一个间隔符（空格、制表符、换行符等）和一个字符，例如：123 a，能够正确读取整数和字符

    printf("你输入的整数是: %d\n", num);
    printf("你输入的字符是: %c，ASCII码是: %d\n", ch, ch);

    exit(0);
}