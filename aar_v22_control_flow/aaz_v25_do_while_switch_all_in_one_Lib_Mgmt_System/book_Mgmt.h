#ifndef BOOK_MGMT_H
#define BOOK_MGMT_H

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
} Book;

extern Book books[MAX_BOOKS];
extern int book_count;

void addBook();
void deleteBook();
void modifyBook();
void searchBook();
void listBooks();
void menu();

#endif