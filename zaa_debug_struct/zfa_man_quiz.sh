






man-strcat中提到的"The strings may not overlap"的意思是：

1. 在使用 `strcat` 函数时，参与连接的两个字符串在内存中不能有重叠的部分,否则结果是未定义行为

    char *strcat(char *dest, const char *src);

   函数作用:把 `src` 字符串追加到 `dest` 字符串的末尾**，并在末尾添加 `\0` 结束符。

2. 为什么不能重叠？

    因为 `strcat` 是按字节从 `src` 复制到 `dest` 末尾的，如果两个字符串在内存中的区域有交叉（overlap），
    会导致复制过程中文件被修改，
    造成未定义行为, undefined behavior, 可能程序会崩溃，结果也可能错误。


3. 非法的用法
    char buf[20] = "Hello";
    strcat(buf, buf + 1);  // 错误！buf 和 buf+1 在内存上有重叠

4. 正确替代方案（如果你需要重叠复制）：

    使用 `memmove()`。与 `strcpy`、`strcat` 不同，`memmove` 专门设计来处理重叠区域的复制：

    memmove(dest, src, length);
