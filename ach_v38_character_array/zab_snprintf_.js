

拷贝固定长度二进制数据(非字符串), memcpy 更合适

int snprintf(char *str, size_t size, const char *format, ...); format长度小于str长度，会在什么地方添加\0

1. 当生成的格式化内容format长度 < size - 1时,snprintf将内容写入str,然后在末尾添加\0.

2. 当格式化内容format长度 ≥ size时,snprintf会截断写入str,并确保在str[size - 1]的位置写入\0(只要 size > 0)

   反汇编或源码层面分析 glibc 中这个 \0 是怎么写进去的，也可以继续提问

3. snprintf函数的返回值是不包括最后面的\0, 在ISO C99标准中, 写的是不计算最后null值
    The snprintf function returns the number of characters that would have been written had n been sufﬁciently large, 
    not counting the terminating null character, or a neg ative value if an encoding error occurred.

   


