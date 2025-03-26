#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define WATER_MOLECULAR_WEIGHT 3.0e-23
#define QUART     950                       //quarter, 1/4 gallon加仑
static void water(void);
static void area(void);
static void root(void);
int main( )
{
    water();
    // area();
    // root( );
    exit(0);
}
static void water(void)        // static禁止函数在其他文件中使用（外部扩展）
{
    float num; double sum;
    printf("Please input how many quart of water:");
    scanf("%f", &num);
    if (num <= 0)
    {
        fprintf(stderr, "Input Error!\n");
        exit(1);
    }
    sum = num*QUART/WATER_MOLECULAR_WEIGHT;
    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("Total water molecular number is %f\n", sum); //31,666,666,666,666,665,598,517,248
    //float 可以表示非常大的数（比如 3.4 × 10³⁸）。例如，最大值 3.402823466e+38, 
    //假设float用32位存储数据,1 位符号位,8 位指数部分,23 位尾数部分,
    //浮点数的表示方式能够通过使用 指数部分 来扩展数值的范围
    //浮点数的指数部分可以表示正负指数，所以它能够表示非常大的或非常小的数。eg指数部分为127时，表示 2^127,这个数非常大
    //对于最大值，指数部分的最大值是 254（二进制表示），表示的数值大约是 2^128。
    printf("Total water molecular number is %e\n", sum);
    return;
}

static void area(void)
{
    float a, b, c;
    float s, area;

    printf("Please input:");
    scanf("%f%f%f", &a, &b, &c);
    // 对scanf做好校验是好习惯
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
