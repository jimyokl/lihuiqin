#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("255, %%x: %x\n", 255);
    printf("65, octal of 65 with %%o: %o\n", 65);
    printf("567.89, %%e: %e\n", 567.89);
    printf("567.89, %%f: %f\n", 567.89);
    printf("567.89, %%g: %g\n", 567.89);

    //#修饰符显示前导符号，0x或0X表示十六进制，0表示八进制，在octal和hexadecimal前面加上0和0x
    printf("\n#修饰符:\n");
    printf("255, %%#x: %#x\n", 255);
    printf("65, octal of 65 with %%#o: %#o\n", 65);

    printf("\n修饰符:\n");
    printf("456.789, %%10.2f, m=10,n=2: %10.2f\n", 456.789);//2:     456.79, 前面有4空格
    printf("456.789, %%10f, m=10: %10f\n", 456.789);//10: 456.789000
    printf("456.789, %%10f, m=2: %2f\n", 456.789);//2: 456.789000
    //m输出数据域宽,数据长度<m,左补空格;否则按实际输出对实数,
    //n指定小数点后位数(四舍五入).n对字符串,指定实际输出位数

    //.n修饰符控制字符串输出的长度，不足n位的，左补空格
    printf("\n修饰符控制字符串输出长度:\n");
    printf("abcdefg, %%.3s, n=3: %.3s\n", "abcdefg");//3: abc
    printf("abcdefg, %%10.3s, m=10,n=3: %10.3s\n", "abcdefg");//10:        abc

    //"-"表示左对齐输出 (缺省是右对齐，左补空格)
    printf("\n左对齐输出:\n");
    printf("abcdefg, %%-10.3s, m=10,n=3: %-10.3s[end]\n", "abcdefg");//10: abc        [end],右边补了有7个空格
    // "+"表示输出带符号，" "表示输出空格，"#"表示输出带前缀

    printf("\nfloat精度不准确:\n");
    printf("123.45678, %%f: %f\n", 123.45678);//老师的例子显示是123.456779,我的gcc没问题
    //有的时候，用浮点数和整数进行运算，会出现精度不准确的情况
    //这是因为浮点数在计算机中是以二进制存储的，而二进制无法精确表示十进制的小数

    printf("\nASCII characters:\n");
    printf("65 of ascii is: %c\n", 65);
    printf("[输出表项是a]，%d\n", 'a');

    FILE *fp;
    char ch;
    char filename[20];
    printf("\nPlease input the filename:\n");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }
    ch = fgetc(fp);
    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp);
    }
    printf("\n");
    fclose(fp);

    exit(0);
}