#include <stdio.h>

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int *p1 = &arr[1];  // 指向 20
    int *p2 = &arr[4];  // 指向 50


    printf("arr[1] add: %p, arr[4] add: %p, diff: %ld\n", p1, p2, p2 - p1);
    // arr[1] add: 0x7ffd348c7a14, arr[4] add: 0x7ffd348c7a20, diff: 3
    // 0x20-0x14 = 0x0c, 0x0c = 12, 12 / 4 = 3

}

