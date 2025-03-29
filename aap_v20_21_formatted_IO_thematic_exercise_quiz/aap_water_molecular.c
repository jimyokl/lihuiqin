#include <math.h>                                           //编译时需要加上 -lm，显式链接数学库
#include <stdio.h>
#include <stdlib.h>
#define WATER_MOLECULAR_WEIGHT 3.0e-23
#define GRAM_PER_QUART         950                          //quarter, 1/4 gallon加仑
static void water(void); static void area(void); static void root(void);// 3个题目在最后
int main(void)
{
    //water();
    //area();
    root( );
    exit(0);
}
static void area(void)
{
    float a, b, c, s, area; int ret;
    printf("Please input 3 integers:");
    ret = scanf("%f%f%f", &a, &b, &c);
    if(ret != 3)
    {
        printf("what you entered is not 3 integer, program will abort.\n");
        fprintf(stderr, "Input Error!\n");
        exit(1);
    }
    while(getchar() != '\n');
    if (a + b <= c || b + c <= a || a + c <= b)
    {
        fprintf(stderr, "EINVAL, 2 triangle side len sum < 3rd side length.\n");//EINVAL是常见的错误码，表示Invalid argument
        exit(0);
    }
    printf("1st triangle side: a = %f\n", a);
    printf("2nd triangle side: b = %f\n", b);
    printf("3rd triangle side: c = %f\n", c);
    s = 1 / 2 * (a + b + c);               // 三边长之和除以2叫做半周长（semi-perimeter）
    //两个操作数都是整数，除法运算 (/) 执行的是整数除法，即舍弃小数部分，只保留整数部分。
    //可以：(float)1 / 2；(double)1 / 2；1.0 / 2；1 / 2.0；
    printf("半周长（semi-perimeter） s = %f\n", s);
    area = sqrt( s * (s-a) * (s-b) * (s-c) )   ;//海伦公式， sqrt是square root的缩写，开平方
    printf("面积 area = %f\n", area);
}
static void area_todel_(void)
{
    float a, b, c;     float s, area;
    printf("Please input:");     scanf("%f%f%f", &a, &b, &c);
    if (a + b <= c || b + c <= a || a + c <= b)
    {
        fprintf(stderr, "EINVAL!\n");
        exit(0);
    }
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    // s = 1 / 2 * (a + b + c);
    s = 1.0 / 2 * (a + b + c);
    printf("s = %f\n", s);
    // s=0.000000
    // 1 / 2是int型计算，得到的是商0余1
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("area = %f\n", area);
    return;
}
static void water(void)        // static禁止函数在其他文件中使用（外部扩展）
{
    float num; double total_molecule;
    printf("Please input how many quart of water:");
    scanf("%f", &num);
    if (num <= 0)
    {
        fprintf(stderr, "Input Error! number of quart should greater than 0\n");
        exit(1); // exit is better than return
    }
    total_molecule = num*GRAM_PER_QUART/WATER_MOLECULAR_WEIGHT;
    printf("totally there are %lf water melecule.\n", total_molecule);//31,666,666,666,666,665,598,517,248

    printf("sizeof(float) = %lu\n", sizeof(float)); //结果是4，但是float4字节也能表示很大的数
    //float 可以表示非常大的数（比如 3.4 × 10³⁸）。例如，最大值 3.402823466e+38, 
    //假设float用32位存储数据,1 位符号位,8 位指数部分,23 位尾数部分,
    //浮点数的表示方式能够通过使用 指数部分 来扩展数值的范围
    //浮点数的指数部分可以表示正负指数，所以它能够表示非常大的或非常小的数。eg指数部分为127时，表示 2^127,这个数非常大
    //对于最大值，指数部分的最大值是 254（二进制表示），表示的数值大约是 2^128。
    printf("scientific number format: totally there are %e water melecule.\n", total_molecule);
    return;
}
void root(void)
{
    float a, b, c;
    float disc;
    float p, q;
    float x1, x2;

    printf("Please input :\n");
    scanf("%f%f%f", &a, &b, &c);

    if (b * b - 4 * a * c < 0)
    {
        fprintf(stderr, "EINVAL\n");
        exit(1);
    }
    disc = b * b - 4 * a * c;
    p    = -b / 2 * a;
    q    = sqrt(disc) / 2 * a;

    x1 = p + q;
    x2 = p - q;

    printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
}
// 从终端输入水的夸脱数，求水分子的个数，1夸脱=950g, 1g水分子个数=3.0e23, quart, 1/4 gallon加仑
//从终端输入三角形的三边长, 求面积, s =1/2*(a+b+c); area = sqrt(s*(s-a)*(s-b)*(s-c));