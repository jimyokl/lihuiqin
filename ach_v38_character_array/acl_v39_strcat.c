#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char hello[]= "hello";
    char world[]= "world";
    printf("size of \"hello\" is %zu, with sizeof.\n", sizeof(hello));    // 6
    printf("strcat function:\n");
    // strcat(hello, ",,");
    // strncat(hello, ",,", sizeof(hello)-strlen(hello)-1 ); // 只拷贝到\0为止
    strncpy(hello, ",world", sizeof(hello) ); // 只拷贝到\0为止
    puts(hello);


    char catena_str[7]="catena";
    char overrun_str[8]="overrun";
    char ccpp[4]={'c','c', 'p', 'p'};
    strncat(catena_str,ccpp, 1);
    puts(catena_str);

    printf("\nsize of \"hello\" is %zu, with sizeof.\n", sizeof(hello));    // 6

    exit(0);
}

/*
otlv4.h:2031: inline void otl_strcat(char* trg, const char* src) 这一段代码出自 OTL (Oracle, ODBC and DB2-CLI Template Library) v4，这是一个开源的 C++ 数据库访问库。

这段代码在实现字符串拼接时，没有考虑目标缓冲区的大小，因此存在潜在的缓冲区溢出风险。

安全版本的 otl_strcat：


通过先计算 `trg` 的原有长度（`strlen`），然后再使用 `sizeof` 来计算 `trg` 的总长度。这个思路可以帮助确保我们计算剩余空间时更加清晰。

#include <cstring>  // 用于 strlen

inline void otl_strcat(char* trg, const char* src, size_t trg_size)
{
  // 计算目标字符串的当前长度
  size_t trg_len = strlen(trg);

  // 计算目标缓冲区的总大小
  size_t remaining_space = trg_size - trg_len - 1;  // 留一个空间给 '\0'

  // 将源字符串追加到目标字符串中，直到剩余空间不足
  while(*src && remaining_space > 0) {
    trg[trg_len] = *src;  // 将源字符复制到目标位置
    ++trg_len;             // 更新目标字符串的长度
    ++src;                 // 移动源指针
    --remaining_space;     // 减少剩余空间
  }

  // 确保目标字符串以 null 结尾
  trg[trg_len] = '\0';
}

### 解释：

1. **计算目标字符串的当前长度**：

   ```cpp
   size_t trg_len = strlen(trg);
   ```

   使用 `strlen` 来计算目标字符串 `trg` 的当前长度（不包括终止符 `\0`）。这为后续计算剩余空间提供了依据。

2. **计算剩余空间**：

   ```cpp
   size_t remaining_space = trg_size - trg_len - 1;
   ```

   使用 `trg_size` 来表示目标缓冲区的总大小（通过 `sizeof` 传入）。然后用总大小减去当前字符串长度（`trg_len`）和留给 `\0` 的空间（减去 1）来计算剩余空间。

3. **追加源字符串**：

   ```cpp
   while (*src && remaining_space > 0) {
     trg[trg_len] = *src;
     ++trg_len;
     ++src;
     --remaining_space;
   }
   ```

   使用 `while` 循环将源字符串 `src` 中的字符逐个追加到目标字符串 `trg` 中，直到没有剩余空间或源字符串结束。

4. **确保目标字符串以 null 结尾**：

   ```cpp
   trg[trg_len] = '\0';
   ```

   最后，确保目标字符串在追加后以 null 结尾，这样才能正确地表示一个 C 风格的字符串。

### 优点：

* 通过 `strlen` 函数获得 `trg` 的原有长度，不依赖指针运算。
* 使用 `sizeof` 计算目标缓冲区的总大小，确保不会越界。
* 留出空间给字符串终止符，避免溢出。

这个版本的代码能够有效防止缓冲区溢出，并确保目标字符串正确处理。如果 `trg` 的缓冲区空间不够，追加操作会停止。


*/
/**/
[System.Environment]::SetEnvironmentVariable

("Path", `
    
  [Microsoft.Win32.Registry]::GetValue
    (
      "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment", 
      "Path",
       ""
    ),

"Process")