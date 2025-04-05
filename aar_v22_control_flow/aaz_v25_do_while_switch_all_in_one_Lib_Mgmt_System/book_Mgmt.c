#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_Mgmt.h"
Book books[MAX_BOOKS];
int book_count = 0;
void addBook() 
{
    if (book_count >= MAX_BOOKS) {
        printf("图书馆已满，无法添加更多书籍。\n"); return;
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
    
    book_count++;   printf("图书添加成功！\n");
}
void deleteBook() {
    int id, found = 0;
    printf("请输入要删除的图书 ID: ");
    scanf("%d", &id);   
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id)
        {
            printf("before del, book_count: %d\n", book_count);  // yan add
            printf("to delete book id: %d, corresponding index of struct of books: %d\n", id, i); // yan add
            for (int j = i; j < book_count - 1; j++) 
            {
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
            printf("Book id: %d, corresponding index of struct of books: %d\n", id, i);  // yan add
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
    printf("\n All books：\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("标题: %s\n", books[i].title);
        printf("作者: %s\n", books[i].author);
        printf("出版年份: %d\n\n", books[i].year);
    }
}
void init_books()
{
    printf("before init 20 books, sizeof struct Book: %zu\n", sizeof(Book));  //yan add
    for (int i = 0; i < 20; i++) 
    {
        books[i].id = i + 1; // Setting unique ID for each book
        switch(i) {
            case 0:
                strcpy(books[i].title, "The Catcher in the Rye");
                strcpy(books[i].author, "J.D. Salinger");
                books[i].year = 1951;
                break;
            case 1:
                strcpy(books[i].title, "To Kill a Mockingbird");
                strcpy(books[i].author, "Harper Lee");
                books[i].year = 1960;
                break;
            case 2:
                strcpy(books[i].title, "1984");
                strcpy(books[i].author, "George Orwell");
                books[i].year = 1949;
                break;
            case 3:
                strcpy(books[i].title, "Pride and Prejudice");
                strcpy(books[i].author, "Jane Austen");
                books[i].year = 1813;
                break;
            case 4:
                strcpy(books[i].title, "The Great Gatsby");
                strcpy(books[i].author, "F. Scott Fitzgerald");
                books[i].year = 1925;
                break;
            case 5:
                strcpy(books[i].title, "Moby-Dick");
                strcpy(books[i].author, "Herman Melville");
                books[i].year = 1851;
                break;
            case 6:
                strcpy(books[i].title, "War and Peace");
                strcpy(books[i].author, "Leo Tolstoy");
                books[i].year = 1869;
                break;
            case 7:
                strcpy(books[i].title, "The Odyssey");
                strcpy(books[i].author, "Homer");
                books[i].year = -800; // Approximate year
                break;
            case 8:
                strcpy(books[i].title, "Crime and Punishment");
                strcpy(books[i].author, "Fyodor Dostoevsky");
                books[i].year = 1866;
                break;
            case 9:
                strcpy(books[i].title, "The Brothers Karamazov");
                strcpy(books[i].author, "Fyodor Dostoevsky");
                books[i].year = 1880;
                break;
            case 10:
                strcpy(books[i].title, "The Hobbit");
                strcpy(books[i].author, "J.R.R. Tolkien");
                books[i].year = 1937;
                break;
            case 11:
                strcpy(books[i].title, "Fahrenheit 451");
                strcpy(books[i].author, "Ray Bradbury");
                books[i].year = 1953;
                break;
            case 12:
                strcpy(books[i].title, "The Lord of the Rings");
                strcpy(books[i].author, "J.R.R. Tolkien");
                books[i].year = 1954;
                break;
            case 13:
                strcpy(books[i].title, "Brave New World");
                strcpy(books[i].author, "Aldous Huxley");
                books[i].year = 1932;
                break;
            case 14:
                strcpy(books[i].title, "The Alchemist");
                strcpy(books[i].author, "Paulo Coelho");
                books[i].year = 1988;
                break;
            case 15:
                strcpy(books[i].title, "One Hundred Years of Solitude");
                strcpy(books[i].author, "Gabriel García Márquez");
                books[i].year = 1967;
                break;
            case 16:
                strcpy(books[i].title, "The Divine Comedy");
                strcpy(books[i].author, "Dante Alighieri");
                books[i].year = 1320;
                break;
            case 17:
                strcpy(books[i].title, "Anna Karenina");
                strcpy(books[i].author, "Leo Tolstoy");
                books[i].year = 1877;
                break;
            case 18:
                strcpy(books[i].title, "The Catcher in the Rye");
                strcpy(books[i].author, "J.D. Salinger");
                books[i].year = 1951;
                break;
            case 19:
                strcpy(books[i].title, "The Picture of Dorian Gray");
                strcpy(books[i].author, "Oscar Wilde");
                books[i].year = 1890;
                break;
            default:
                break;
        }
        book_count++;
    }
    printf("after init 20 books, sizeof struct Book: %zu, book_count: %d\n", sizeof(Book), book_count); //yan add
}
void menu() {
    printf("\n############################### 图书管理系统 ###############################\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 修改图书\n");
    printf("4. 查找图书\n");
    printf("5. 列出所有图书\n");
    printf("0. 退出\n");
}