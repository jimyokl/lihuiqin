#include <stdio.h>
#include <stdlib.h>

//字面量后面加上LL，表示这是一个long long类型的字面量
//long long类型的字面量，可以用来解决整数溢出的问题
#define SEC_PER_YEAR (60LL*60LL*24LL*365LL) //加括号, 加LL防止溢出

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
    // printf("i = %#o\ni = %#x\n",255);

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
    //有的时候，用1个非常大的浮点数和1个非常小的浮点数进行运算，会出现精度不准确的情况
    //这是因为浮点数在计算机中是以二进制存储的，而二进制无法精确表示十进制的小数

    printf("\nASCII characters:\n");
    printf("65 of ascii is: %c\n", 65);
    printf("[输出表项是a]，%d\n", 'a');

    printf("\n l modifier, l修饰符, %%lf,指定输出精度是double型:\n");
    double double_num = 12345678901234.123456;
    printf("with %%f,double_num = %f\n", double_num);
    printf("with %%lf, double_num = %lf\n", double_num); //上面2行一样，没有报warning
    //long long var 输出修饰符应该为 printf("%lld", var);

    printf("\n big number such as 5*1024*1024*1024 overflow问题, 加LL字面量:\n");
    //printf("long long var, %%lld, 12345678901234: %d\n", 5*1024*1024*1024);
    //warning: integer overflow in expression of type ‘int’ results in ‘1073741824’ [-Woverflow]

    //long long long_var = 5*1024*1024*1024;warning: integer overflow in expression of type ‘int’ results in ‘1073741824’
    long long long_var1 = 5LL*1024LL*1024LL*1024LL;
    printf("5LL*1024LL*1024LL*1024LL with LL suffix, %%lld: %lld\n", long_var1);

    long long long_var2 = 5*1024*1024;
    long_var2 = long_var2 * 1024;
    printf("long long var 5*1024*1024*1024, 先计算5*1024*1024, 再乘1024: %lld\n", long_var2);
    
    printf("\n 变参, printf(const char *format, ...), ...表示变参列表:\n");
    printf("变参列表写多一个参数，不会报错，但是不会输出: %d\n", 123, 456);
    printf("变参列表写少一个参数,会输出随机值,根据压栈的向上方向找到long_var1,然后第二个%%d输出8字节的long_var1上面存储的4字节: %lld, %d\n", long_var1);
    //man 2 open可以看到int open(const char *pathname, int flags); int open(const char *pathname, int flags, mode_t mode);
    //有点类似重载，但是不是, 是变参. printf在参数过多时，会忽略多余的参数，参数过少时，会输出随机值，这种叫变参
    //变参函数自己都不知道自己额定的参数个数，只能在调用时才知道
    //还例如man 3 exec, int execl(const char *path, const char *arg, ...  /* (char  *) NULL */);

    //最好加上\n，否则可能会出现输出不及时的情况, 因为printf是行缓冲的, 遇到\n才会刷新缓冲区
    printf("[%s:%d:%s], before while loop.", __FILE__, __LINE__, __func__);
    while (1)
    printf("[%s:%d:%s], after while loop.", __FILE__, __LINE__, __func__);
    //这里能打出，可能是因为前面有\n，刷新了缓冲区
    //本来是全缓冲模式，但是现在用到了终端设备，所以变成了行缓冲模式，所以printf遇到\n（或者等缓冲区满）才刷新缓冲区
    //
    

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