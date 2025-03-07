#include <stdio.h>
#include <stdlib.h>

//scanf在读取数值时，会将回车等间隔符留在输入队列中，使用字符型输入来处理这个留在队列中的回车符
int main()
{
    char ch;
    int i;
    printf("Please input a number and a character: ");
    scanf("%d", &i);
    getchar(); // 读取一个字符，这个字符是输入的回车或者换行符,间隔符
    scanf("%c", &ch);

    printf("The number you input is: %d\n", i);
    printf("The character you input is: %c, ASCII is: %d\n", ch, ch);
    
    exit(0);
}   