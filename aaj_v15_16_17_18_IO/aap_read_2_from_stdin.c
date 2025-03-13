#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[50];
    ssize_t bytesRead;

    printf("请输入一些文字：\n");
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // 读取用户输入

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // 确保字符串正确终止
        printf("你输入的是：%s", buffer);
    } else {
        perror("读取失败");
    }

    return 0;
}