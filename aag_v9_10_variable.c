#include <stdio.h>
#include <stdlib.h>

// define auto variable
int main() {

    auto int a;
    auto int b;
    
    printf("auto int a; auto variable a: %d\n", a);
    printf("auto int b; auto variable b: %d\n", b);

    // static variable
    static int c;
    printf("static int c; static variable c: %d\n", c);

    exit(0);
}