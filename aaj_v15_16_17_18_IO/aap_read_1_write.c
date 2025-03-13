#include <stdio.h>
#include <fcntl.h>   // open()
#include <unistd.h>  // read(), close()
#include <stdlib.h>  // exit()
//ssize_t read(int fd, void *buf, size_t count);通常用于低级I/O操作（类似于fread，但read直接操作文件描述符）
//成功时返回实际读取的字节数。失败返回-1，并设置errno。返回0表示读取到文件末尾（EOF）。
int main() {
    printf("example 1: 从文件中读取数据:\n");
    char buffer[100] = ""; // 读取缓冲区
    int fd = open("text_file.txt", O_RDONLY); // 以只读模式打开文件

    if (fd == -1) {
        perror("打开文件失败");
        return 1;
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1); // 读取数据
    if (bytesRead == -1) {
        perror("读取失败");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0'; // 确保字符串以 '\0' 结尾
    printf("读取的内容：\n%s\n", buffer);

    close(fd); // 关闭文件
    
    printf("example2: 从标准输入（键盘）读取数据:\n");
    // putchar('\n'); //
    // fflush(stdout); // 刷新输出缓冲区
    // while (getchar() != '\n');  // 清空输入缓冲区

    buffer[0] = '\0'; // 清空缓冲区
    bytesRead = 0;
    printf("请输入一些文字：\n");
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // 从标准输入读取数据

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // 确保字符串正确终止
        printf("你输入的是：%s", buffer);
    } else {
        perror("读取失败");
    }
////////////////////////////////////////////////////////////////////////////////////
    printf("example 3: 使用 read 读取二进制文件:\n");
    int fd_bin = open("binary_file.dat", O_RDONLY);
    if (fd_bin == -1) {
        perror("打开文件失败");
        return 1;
    }

    unsigned char buffer_bin[100] = ""; // 读取缓冲区
    bytesRead = 0;
    bytesRead = read(fd_bin, buffer_bin, sizeof(buffer_bin)); // 读取数据

    if (bytesRead > 0) {
        printf("读取了 %zd 字节数据：\n", bytesRead);
        for (ssize_t i = 0; i < bytesRead; i++) {
            printf("%02X ", buffer_bin[i]); // 以十六进制打印数据
        }
        printf("\n");
    } else {
        perror("读取失败");
    }
    close(fd_bin); // 关闭文件

    exit(0);
}