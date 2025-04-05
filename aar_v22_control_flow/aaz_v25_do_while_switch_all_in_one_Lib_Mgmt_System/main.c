#include <stdio.h>
#include <stdlib.h>
#include "book_Mgmt.h"

int main() {
    int choice;
    
    do {
        menu();
        printf("请输入你的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: modifyBook(); break;
            case 4: searchBook(); break;
            case 5: listBooks(); break;
            case 0: exit(0);
            default: printf("无效的选择，请重新输入。\n");
        }
    } while (1);  // 无限循环，直到用户选择退出

    return 0;
}