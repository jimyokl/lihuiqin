#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define STRSIZE 30

int main()
{
    int i;
    printf("Please enter an interger:\n");
    //scanf里面的“”内的内容，你都要一模一样地输入，包括空格，回车，换行等，
    //所以scanf("i=%d", &i)不好, 直接写scanf("%d", &i)
    scanf("%d", &i); //回车符也不要，不要输成：scanf("i = %d\n", &i
    printf("i = %d\n", i);

    printf("Please enter for i[int] and f[float] like this: i,f (integer,comma,decimal):\n");
    float f;
    scanf("%d,%f", &i, &f);
    while (getchar() != '\n'); //清空输入缓冲区
    printf("i = %d, f = %f\n", i, f);

    //如果scanf中%d,%f之间为空，那么输入时可以敲空格，回车，换行等
    printf("Please enter for i[int] and f[float] like this: i_f (integer,'_' means tab/blank/enter,decimal):\n");
    scanf("%d%f", &i, &f);
    printf("i = %d, f = %f\n", i, f);

    printf("\nyou can't input blank/tab/enter/newline into %%s of scanf\n");
    printf("scanf中输入%%s不能中间添加间隔符，例如“空格，tab键，回车，换行”等\n");
    char str[STRSIZE];
    printf("Please enter a string:\n");
    scanf("%s", str); //输入hello可以，但是如果输入hello world，只会读取hello，
    //%s作为输入项，不能中间添加间隔符，例如“空格，tab键，回车，换行”等
<<<<<<< HEAD
    while (getchar() != '\n'); //清空输入缓冲区
    printf("str = %s\n", str);
    // puts(str);
=======
    while ( getchar() != '\n');
    
    printf("if you input blank/tab/newline among the string, you can only get: str = %s\n", str);
    //puts(str); // a trailing \n
>>>>>>> 70eddf4 (e320 at feng xi nan li)

    printf("\nit's dangerous to input a string with scanf, possible buffer overrun.\n");
    printf("scanf中输入%%s是很危险的，因为不知道输入的字符串长度，可能会造成缓冲区溢出,最好用fgets\n");
    //scanf中输入%s是很危险的，因为不知道输入的字符串长度，可能会造成缓冲区溢出, use fgets instead
    //例如改STRSIZE为3，输入hello world，会造成缓冲区溢出
    //缓冲区可能还有上次输入的未刷新的内容，所以得到的并不是本次输入的内容
    int STRSIZE_3 = 3;
    char str_3[STRSIZE_3];
    printf("Please enter a string, here STRSIZE_3 = 3:\n");
    scanf("%s", str_3); //此时也可以输入2个字符长度以上的字符串，也能完全printf输出，！！！已经溢出了，不安全
    printf("我们在scanf定义的str_3数组长度ONLY 3，但这里可以打印多于3个的字符串，不安全 = %s\n", str_3);

    // char *p; int n;

    // errno = 0;
    // printf("n = scanf( %%m[a-z], *p ), Enter a lowercase string:\n");
    // n = scanf("%m[a-z]", &p);
    // if (n == 1) {
    //     printf("read: %s\n", p);
    //     free(p);
    // } else if (errno != 0) {
    //     perror("scanf");
    // } else {
    //     fprintf(stderr, "No matching characters\n");
    // }
    exit(0);
}