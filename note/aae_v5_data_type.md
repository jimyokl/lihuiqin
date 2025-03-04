video 5:
---------------------------------------------part 1 data type--------------------------------------------
数据类型:
  注:后面c99制定的bool类型,没有
1.基本类型
  1.1 数值类型
    1.1.1 整型-整数类型
    ![image](https://github.com/jimyshow/image_host_lihuiqin/blob/main/image_host/v5_%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B_%E5%80%BC%E8%8C%83%E5%9B%B4.png)
        a. 短整型 short
          --在补码中，符号位的值为−2^(n−1)（而非简单的符号标记）。例如，16位数的符号位权重是−32768−32768，当符号位
            为1且其他位为0时，值就是−32768−32768。
          --因为-32768 没有正数对应的相反数（无法用 16 位存储 +32768，因为 0111 1111 1111 1111 + 1 会溢出）.
        b. 整型 int
        c. 长整型 long
    1.1.2 浮点型-小数类型
        a. 单精度浮点型 float
        b. 双精度浮点型 double
  1.2 字符类型char
2.构造类型
    2.1 数组类型
    2.2 结构体类型 struct
    2.3 共用体类型 union
    2.4 枚举类型 enum
3.指针类型
4.空类型void

c标准规定: int比char占用的字节数多,int比float占用的字节数少
![image](https://github.com/jimyokl/lihuiqin/blob/main/media/float%E6%B5%AE%E7%82%B9%E6%95%B0%E5%86%85%E5%AD%98%E5%AD%98%E6%94%BE.png)
0.000789-> 0.789(存为小于1的数) *10^-3, 浮点数, 0.789是尾数, -3是指数, 例如32位, 1位符号位, 然后是8位存指数位, 接着23位存尾数位

ascii code:
![image](https://github.com/jimyshow/image_host_lihuiqin/blob/main/image_host/v5_2_ASCII%E8%A1%A8.jpg)
空字符 '\0', ascii码为000,
'\0'一般放在字符串的结束处，用来表示字符串的结束，其是ascii值为0的字符的转义
strlen()计算长度时不考虑末尾的'\0'

特殊性:
 3). char类型数据,是否有符号,是未定义的行为,char和unsigned char

 转换有精度损失
    convert longer number to shorter, lost accuracy
    implicit conversion: two different types of data add/minus/muliple/, auto convert the result 
    explicit conversion: int a; float b = (float) a;
 1). bool:
    logical type
 2). float:
    float number eg 1.5 is not a precise number
    eg: (1/3)*3 !=1, because 1/3 = 0.333..., then 1/3*3 = 0.999...
    how to get to know if a float number is 0, to make use of |f| if smaller than 10^-6
    ?去网上查查怎么比较,去copy别人的程序
 4). 不同形式的0值
   0
   '0'
   "0"
   '\0', 相当于NULL吗？
 5). 数据类型与后续代码中所使用的输入输出要相匹配
  int num = 2147483647; num = num + 1; 输出-2147483648

---------------------------------------------part 2 constant--------------------------------------------
常量:在程序执行过程中值不会发生变化的量
1.1) 常量变量之间关系--会影响对数组的理解, 数组名就是一个典型的常量.
      数组一旦定义，gcc分配一段空间，数组位置就定死了，数组名是数组的起始位置，数组名是常量，不能放在等号左边了(1=2不行)，
变量:用来保存一些特定内容，并且在在程序执行过程中值随时会发生变化的量

常量分类：整型常量eg int，实型常量eg float，
         字符常量:由单引号引起来的单个的字符 或 转义字符(\0==NULL,'\000'是八进制, '\x7f'是16进制)
         字符串常量:由双引号引,\0结束. 

         标识常量: #define   -- v8文件