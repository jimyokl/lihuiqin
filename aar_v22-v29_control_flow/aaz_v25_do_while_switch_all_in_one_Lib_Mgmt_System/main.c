#include <stdio.h>
#include <stdlib.h>
#include "book_Mgmt.h"

int main() {
    init_books();
    int choice, ret_scanf;
    
    do {
        menu();
        printf("请输入你的选择: ");
        ret_scanf = scanf("%d", &choice);
        if (  (ret_scanf != 1) || (choice < 0) || (choice > 5) ) { // yan add
            printf("输入无效，请输入数字。\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
        switch (choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: modifyBook(); break;
            case 4: searchBook(); break;
            case 5: listBooks(); break;
            //case 0: exit(0);
            default: printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 0);
    printf("感谢使用图书管理系统！\n");
    exit(0);
}