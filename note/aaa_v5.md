video 5:
数据类型:
  注:后面c99制定的bool类型,没有
1.基本类型
  1.1 数值类型
    1.1.1 整型-整数类型
        a. 短整型 short
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
空字符 '\0', ascii码为000,
'\0'一般放在字符串的结束处，用来表示字符串的结束，其是ascii值为0的字符的转义
strlen()计算长度时不考虑末尾的'\0'

char和unsigned char

转换有精度损失
    convert longer number to shorter, lost accuracy
    implicit conversion: two different types of data add/minus/muliple/, auto convert the result 
    explicit conversion: int a; float b = (float) a;
bool:
    logical type
float:
    float number eg 1.5 is not a precise number
    eg: (1/3)*3 !=1, because 1/3 = 0.333..., then 1/3*3 = 0.999...
    how to get to know if a float number is 0, to make use of |f| if smaller than 10^-6

