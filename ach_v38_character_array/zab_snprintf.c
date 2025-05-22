
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100] = "Hello, ";
    
    // 计算当前已有内容长度
    size_t len = strlen(buffer);
    printf("Current length: %zu\n", len);  // Current length: 7
    
    // 从已有内容之后继续写入追加内容
    snprintf(buffer + len, sizeof(buffer) - len, "World! Number: %d", 42);

    printf("%s\n", buffer);  // 输出：Hello, World! Number: 42
    printf("%s\n", buffer+len);  // 输出：

    return 0;
}

