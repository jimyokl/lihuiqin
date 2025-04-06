#ifndef BOOK_MGMT_H
#define BOOK_MGMT_H

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
} Book;

extern Book books[MAX_BOOKS];  // .h中定义，在.c中访问, 可以在.c中使用 extern 声明这个变量
                               // 也可以用于函数的声明，尤其是当你将函数定义放在一个文件中，在其他文件中使用该函数时。
                               // eg在1.c中定义了一个函数，在2.c中使用这个函数, extern void printMessage(); 声明外部函数
                               // 通常将外部声明放在头文件中，并在不同的源文件中包含这个头文件。
extern int book_count;

void addBook();
void deleteBook();
void modifyBook();
void searchBook();
void listBooks();
void menu();
void init_books();

#endif