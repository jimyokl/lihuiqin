#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_Mgmt.h"

Book books[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("图书馆已满，无法添加更多书籍。\n");
        return;
    }
    
    printf("请输入图书 ID: ");
    scanf("%d", &books[book_count].id);
    printf("请输入图书标题: ");
    getchar();  // 清除缓冲区的换行符
    fgets(books[book_count].title, sizeof(books[book_count].title), stdin);
    books[book_count].title[strcspn(books[book_count].title, "\n")] = 0;  // 去除换行符

    printf("请输入图书作者: ");
    fgets(books[book_count].author, sizeof(books[book_count].author), stdin);
    books[book_count].author[strcspn(books[book_count].author, "\n")] = 0;  // 去除换行符

    printf("请输入出版年份: ");
    scanf("%d", &books[book_count].year);
    
    book_count++;
    printf("图书添加成功！\n");
}

void deleteBook() {
    int id, found = 0;
    printf("请输入要删除的图书 ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
            found = 1;
            printf("图书已删除。\n");
            break;
        }
    }
    
    if (!found) {
        printf("没有找到指定 ID 的图书。\n");
    }
}

void modifyBook() {
    int id, found = 0;
    printf("请输入要修改的图书 ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("修改图书信息：\n");
            printf("请输入新的图书标题: ");
            getchar();  // 清除缓冲区的换行符
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = 0;  // 去除换行符

            printf("请输入新的图书作者: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;  // 去除换行符

            printf("请输入新的出版年份: ");
            scanf("%d", &books[i].year);
            printf("图书信息已修改。\n");
            break;
        }
    }

    if (!found) {
        printf("没有找到指定 ID 的图书。\n");
    }
}

void searchBook() {
    int id, found = 0;
    printf("请输入要查找的图书 ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("找到图书：\n");
            printf("ID: %d\n", books[i].id);
            printf("标题: %s\n", books[i].title);
            printf("作者: %s\n", books[i].author);
            printf("出版年份: %d\n", books[i].year);
            break;
        }
    }

    if (!found) {
        printf("没有找到指定 ID 的图书。\n");
    }
}

void listBooks() {
    if (book_count == 0) {
        printf("没有图书可供显示。\n");
        return;
    }

    printf("\n所有图书：\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("标题: %s\n", books[i].title);
        printf("作者: %s\n", books[i].author);
        printf("出版年份: %d\n\n", books[i].year);
    }
}

void menu() {
    printf("\n图书管理系统\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 修改图书\n");
    printf("4. 查找图书\n");
    printf("5. 列出所有图书\n");
    printf("0. 退出\n");
}
