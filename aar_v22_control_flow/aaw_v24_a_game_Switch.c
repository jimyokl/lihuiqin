#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int ch;
    printf("a=%d\n", 'a');
    printf("A=%d\n", 'A');
    printf("\nPlease input a character:\n");
    ch = getchar();

    
    if( (ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z'))
    {
        fprintf(stderr, "input error, please input a character.\n");
        exit(1);
    }


    switch (ch)
    {
    case 'a':
    case 'A':
        printf("Ant: a small insect that lives in colonies, lives in groups.\n");
        //break;
    case 'b':
    case 'B':
        printf("Bee: a flying insect that is known for its role in pollination.\n");
        printf("Butterfly: a flying insect with large, often brightly colored wings, long thin body.\n");
        //break;
    case 'c':
    case 'C':
        printf("Cat: a small domesticated carnivorous mammal with soft fur, a short snout, and retractable claws.\n");
        printf("Cobra: a highly venomous snake known for its hood and ability to spit venom, highly dangerous.\n");
        //break;
    case 'd':
    case 'D':
        printf("Dog: a domesticated carnivorous mammal that typically has a long snout, an acute sense of smell, and barks.\n");
        printf("Dolphin: a highly intelligent marine mammal known for its playful behavior and acrobatics.\n");
        printf("Donkey: a domesticated hoofed mammal with long ears, known for its strength and endurance, short legs long ears.\n");
        //break;
    default:
        printf("input error.\n");
        break;
    }

    exit(0);
}