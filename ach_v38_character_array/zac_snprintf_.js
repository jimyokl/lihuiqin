
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
一:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~拷贝固定长度二进制数据(非字符串), memcpy更合适~~~~~~~~~~~~~~~~


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~int snprintf(char *str, size_t size, const char *format, ...); ~~~~~~~~~~~~~~~~
二:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~format长度小于str长度,会在什么地方添加\0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. 当生成的格式化内容format长度 < size - 1时,snprintf将内容写入str,然后在末尾添加\0.

2. 当格式化内容format长度 ≥ size时,snprintf会截断写入str,并确保在str[size - 1]的位置写入\0(只要 size > 0)

   反汇编或源码层面分析 glibc 中这个 \0 是怎么写进去的，也可以继续提问

3. snprintf函数的返回值是不包括最后面的\0, 在ISO C99标准中, 写的是不计算最后null值
    The snprintf function returns the number of characters that would have been written had n been sufﬁciently large, 
    not counting the terminating null character, or a neg ative value if an encoding error occurred.
   

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
三:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~snprintf in C17~~~~~~~~~~~~~~~~    
Description:
   The snprintf function is equivalent to fprintf, except that the output is written into an array (speciﬁed by argument s) 
rather than to a stream. 
   snprintf的作用类似于fprintf(向文件流写入格式化文本),但不同的是:它不是将格式化结果写入文件或标准输出,而是写入一个字符数组s中.

   If n is zero, nothing is written, and s may be a null pointer. 
   如果参数n为0,表示不写入任何字符.此时,s(输出缓冲区指针)可以是NULL,因为不会写入任何数据.

   Otherwise, output characters beyond the n-1st are discarded rather than being written to the array, 
and a null character is written at the end of the characters actually written into the array. 
   如果n大于0,最多写入n-1个字符到数组s中(保留一个位置用于结尾的空字符\0),多出来的字符将被丢弃,不会写入数组.
最后,实际写入的字符串末尾会添加一个空字符\0来终止字符串.

   If copying takes place between objects that overlap, the behavior is undeﬁned
   如果在源数据和目标数组之间发生了重叠复制(即它们的内存区域重叠),那么其行为是未定义的.
(这意味着结果可能是不可预测的，程序可能会崩溃或产生错误的结果)

Returns:
   The snprintf function returns the number of characters that would have been written
had n been sufﬁciently large, not counting the terminating null character,
   snprintf返回的是本来应该写入的字符数(如果n足够大的话),不包括末尾的空字符\0.
(也就是说,即使你给的缓冲区不够大,它也会告诉你原本需要多少字符来完整输出格式化的字符串(不算\0) )

   or a negative value if an encoding error occurred. 
   如果在格式化过程中发生了编码错误(例如多字节字符无法表示,格式非法等),则返回一个负值,表示失败.

   Thus, the null-terminated output has been completely written 
if and only if the returned value is nonnegative and less than n
   因此,只有在返回值是非负数,并且小于n时,
你才可以确信整个输出字符串已经完整地写入了缓冲区中,并且已经正确以\0结尾.

示例:
      char buf[10];
      int written = snprintf(buf, sizeof(buf), "hello world");
      "hello world"是11个字符.

   sizeof(buf)是10,最多写入9个字符(留一个给'\0'), written返回11(表示如果空间够,它会写11个字符).
实际上buf中只写了"hello wor",末尾加上'\0', 所以,written>=sizeof(buf),说明内容被截断了.

   if (written >= 0 && written < sizeof(buf)) {
      // 输出完整写入，且以 '\0' 结尾
   } else {
      // 输出被截断，或者出错
   }


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
四:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~虚拟语气that would have been written had n been sufficiently large~~~~~~~~~~~~~~~~

----宾语是一个限制性定语从句,修饰"the number of characters": that would have been written had n been sufficiently large
   这个句子中, that would have been written, 本质上是虚拟语气的过去完成式,意指--本可以被写入的字符数
   had n been sufficiently large, 倒装结构,用于表示与过去事实相反的假设,等价于:

   if n had been sufficiently large, "如果n足够大(但实际上不够大)"
   所以整个从句意思是,那些本可以被写入(如果n足够大)字符的数量
