#include <stdio.h>
#include <stdlib.h>

#define WATER_WEIGHT 3.0e-23
#define GRAM_PER_QUART 950

static void water(void)
{

    float num = 0;
    double total_molecule = 0;

    printf("input how many quart water: ");
    scanf("%f", &num);

    total_molecule = (num*GRAM_PER_QUART) / WATER_WEIGHT;
    printf("totally there are %lf water melecule.\n", total_molecule);
    printf("scientific number format: totally there are %e water melecule.\n", total_molecule);

}

int main()
{
    water();


    exit(0);
}