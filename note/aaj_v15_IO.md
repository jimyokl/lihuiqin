                                    三 输入、输出专题
2部分：标准IO，系统调用IO（或者叫文件IO）

1、格式化输入输出函数:scanf,printf
2、字符输入输出函数:getchar,putchar
3、字符串输入输出函数：gets（此函数比较危险，有更好alternative），puts
    字符串相关存储机制（字符数组）

1. printf-格式化输出
   man 3 printf, 因为是标准IO的标准库函数
   int printf(const char *format, ...); "..."表示不知道传几个参数, 变参函数
    -format格式："%[修饰符]格式字符"（eg：%ld长整型）,参照 v15_标准输出格式字符.png, v15_标准输修饰符.png
    -printf("hello world.\n")
    -printf("a=%d.\n",a)
    ![image](https://github.com/jimyshow/image_host_lihuiqin/blob/main/image_host/v15_1_%E6%A0%87%E5%87%86%E8%BE%93%E5%87%BA%E6%A0%BC%E5%BC%8F%E5%AD%97%E7%AC%A6.png)
    ![image](https://github.com/jimyshow/image_host_lihuiqin/blob/main/image_host/v15_2_%E6%A0%87%E5%87%86%E8%BE%93%E4%BF%AE%E9%A5%B0%E7%AC%A6.png)

   printf("%[修饰符]格式字符", [输出表项])