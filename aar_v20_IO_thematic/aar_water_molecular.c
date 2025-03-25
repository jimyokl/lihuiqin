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
static void water(void)
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
