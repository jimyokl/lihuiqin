#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("test.bin", "wb");
    char str[] = "abc\0def"; // 长度是 7，包括 null 字符
    fwrite(str, sizeof(char), sizeof(str), fp);
    fclose(fp);
    return 0;
}
//$cat test.bin
//abcdef

// 在vscode里面鼠标点击打开test.bin, 报错：
// The file is not displayed in the text editor because it is either binary or uses an unsupported text encoding.


//  size_t fwrite(const void ptr[restrict .size * .nmemb], 
//  size_t size, size_t nmemb,
//  FILE *restrict stream);


//  The function fwrite() writes nmemb items of data, each size bytes long, to the stream pointed to by stream, 
//  obtaining them from the location given by ptr.