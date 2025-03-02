#include <stdio.h>
#include <stdlib.h>
int main()
{
// 1 ---------------------------------Arithmetic Operators--------------------------------
//Subtraction —— 减法; (Multiplication) —— 乘法; (Division) / —— 除法; (Modulus) % —— 取余(模运算);
//(Increment) ++ —— 自增; (Decrement) -- —— 自减
    int a = 21; int b = 10; int c ;
    c = a + b;
    printf("Line 1 - Value of c is %d\n", c );

    c = a - b;
    printf("Line 2 - Value of c is %d\n", c );

    c = a * b;
    printf("c=a*b, c=%d\n", c);

    c = a / b;
    printf("c=a/b, c=%d\n", c);

    float d = 21.0;
    float e;
    e = d / b;
    printf("e=d/b, e=%f\n", e);
    // e=d%b; //报错：invalid operands to binary % (have ‘float’ and ‘int’) e=d%b;
    // printf("e=d%%b, e=%f\n", e);

    c = a % b; // 取余(模运算)两侧必须是整数
    printf("c=a%%b, c=%d\n", c);
    // 连续两个%才是打印出一个%, \% 转义不能打印出%

    c = a++;
    printf("c=a++, c=%d\n", c);
    c = a--;
    printf("c=a--, c=%d\n", c);

    printf("\n++ -- 运算符:\n");

    int i =1, j=10,value;
    value= i++ + ++j;
    printf("i = %d\n",i);
    printf("j = %d\n",j);
    printf("value = %d\n",value);

// 2 ---------------------------------关系运算符 (Relational Operators)--------------------------------
    printf("\n关系运算符: value of i>j: %d.\n", i>j); //i值为1，j值为10,line 40
    printf("i=1,j=10, value of i < j: %d \n", i<j); //i值为1，j值为10,line 40
    printf("i=1,j=10, value of i!= j: %d \n", i!=j); //i值为1，j值为10,line 40
// 3.1 ---------------------------------逻辑运算符 (Logical Operators)--------------------------------
    printf("\n逻辑运算符: j=10, value of !j: %d.\n", !j); //j值为10
    printf("value of !0: %d \n", !0); //
// 3.2 ---------------------------------逻辑与或的短路特性 (Short-Circuit Evaluation)--------------------------------
    int aa = 1, bb = 2, cc=3, dd=4;
    int ii=1, jj=1;
    int kk = (ii=aa>bb)&&(jj=cc>dd);//与运算符，左边为假则整个表达式为0，不用执行右边了,所以ii值改为0，jj值不变
    printf("kk=(ii=aa>bb)&&(jj=cc>dd), aa=%d, bb=%d, cc=%d, dd=%d, kk=%d\n", aa, bb, cc, dd, kk);
    printf("ii=%d, jj=%d\n", ii, jj);//jj值还是1

    int kk2 = (ii=aa<bb)||(jj=cc>dd);//或运算符，左边为真，右边不执行,所以ii值改为1，jj值不变
    kk2++;
    printf("ii=%d, jj=%d\n", ii, jj);//jj值还是1

    int kk3 = (ii=aa>bb)||(jj=cc>dd);//或运算符，左边为假，右边执行,所以ii值改为0，jj值也改为0
    printf("kk3=(ii=aa>bb)||(jj=cc>dd), aa=%d, bb=%d, cc=%d, dd=%d, kk3=%d\n", aa, bb, cc, dd, kk3);
    printf("Logical OR result: ii=%d, jj=%d\n", ii, jj);//jj值变为0

// 4 ---------------------------------assignment operator---------------------------------
    printf("\nassignment operator, x = 10, y = 20:\n");
    int x = 10, y = 20;
    x += y; // x = x + y;
    printf("x += y, x=%d\n", x);
    x -= y; // x = x - y;
    printf("x -= y, x=%d\n", x);
    x *= y; // x = x * y;
    printf("x *= y, x=%d\n", x);
    x /= y; // x = x / y;
    printf("x /= y, x=%d\n", x);
    x %= y; // x = x % y;
    printf("x %%= y, x=%d\n", x);
    x &= y; // x = x & y;
    printf("x &= y, x=%d\n", x);
    x |= y; // x = x | y;
    printf("x |= y, x=%d\n", x);
    x ^= y; // x = x ^ y;
    printf("x ^= y, x=%d\n", x);
    x <<= y; // x = x << y;
    printf("x <<= y, x=%d\n", x);
    x >>= y; // x = x >> y;
    printf("x >>= y, x=%d\n", x);

    int var_assignment_a =6;
    var_assignment_a *= var_assignment_a += 3; //warning: operation on ‘var_assignment_a’ *= may be undefined
    printf("var_assignment_a -= var_assignment_a*= var_assignment_a += 3, var_assignment_a=%d\n", var_assignment_a);

// 5 ---------------------------------条件运算符 Conditional Operator---------------------------------
    int max = (a > b) ? a : b;
    printf("max = (a > b) ? a : b, max=%d, a=%d, b=%d\n", max, a, b);

// 6 ---------------------------------sizeof 运算符--------------------------------
    printf("size = sizeof(int), size=%ld\n", sizeof(int));
    printf("size of short: %ld\n", sizeof(short));
    printf("size of double: %ld\n", sizeof(double));
    printf("size of float: %ld\n", sizeof(float));
    printf("size of char: %ld\n", sizeof(char));
    printf("size of long: %ld\n", sizeof(long));
    printf("size of long long: %ld\n", sizeof(long long));
    printf("size of pointer: %ld\n", sizeof(int*));

// 7 ---------------------------------强制类型转换运算符 type casting operator---------------------
    printf("\n强制类型转换运算符 type casting operator:\n");
    int sum = 17, count = 5, mean_type_casting_a;
    double mean = 3.9; 
    mean_type_casting_a = mean;
    printf("宽字节->窄,损失精度：mean = 3.9, mean_type_casting_a (int) =mean, mean_type_casting_a=%d\n", mean_type_casting_a);
    mean =  sum / count;
    double mean_type_casting = (double) sum / count;
    //隐式转换：字节数占得少的类型转换为字节数占得多的类型,3-->3.0
    printf("sum=17, count=5, mean = sum / count, mean=%f\n", mean);
    //加上强制类型转换，就可以得到正确的结果
    printf("sum=17, count=5, mean = (double) sum / count, mean=%f\n", mean_type_casting);

    int var_type_casting_a = 10;
    double var_type_casting_b = 2.5;
    var_type_casting_a = var_type_casting_b;
    printf("隐式转换,损失精度: var_type_casting_a = var_type_casting_b (2.5), var_type_casting_a=%d\n", var_type_casting_a);
    var_type_casting_a = (int) var_type_casting_b;
    printf("显式转换,保留整数部分: var_type_casting_a = (int) var_type_casting_b (2.5), var_type_casting_a=%d\n", var_type_casting_a);
    //type casting operator不改变原始值，只是改变表达式的值，var_type_casting_b的值还是2.5

// 4 ---------------------------------位运算符 (Bitwise Operators)--------------------------------
    printf("\n位运算符 (Bitwise Operators):\n");
    //位图是一种对整数进行操作的方法，它们在二进制形式下操作。位运算符是用于执行位操作的运算符。
    //linux的stat函数，st_mode是一个16位的二进制数，每一位代表一个权限，用位运算符来判断权限
/*
    POSIX  refers  to  the  stat.st_mode  bits corresponding to the mask S_IFMT (see below) as the file type, 
    the 12 bits corresponding to the mask 07777 as the file mode bits and
    the least significant 9 bits (0777) as the file permission bits.

    S_IFSOCK   0140000   socket
           S_IFLNK    0120000   symbolic link
           S_IFREG    0100000   regular file
           S_IFBLK    0060000   block device
           S_IFDIR    0040000   directory
           S_IFCHR    0020000   character device
           S_IFIFO    0010000   FIFO

    S_ISREG(m)  is it a regular file?
    S_ISDIR(m)  directory?
    S_ISCHR(m)  character device?
    S_ISBLK(m)  block device?
    S_ISFIFO(m) FIFO (named pipe)?
    S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)
    S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)

    The following mask values are defined for the file mode component of the st_mode field:

    S_ISUID     04000   set-user-ID bit
    S_ISGID     02000   set-group-ID bit (see below)
    S_ISVTX     01000   sticky bit (see below)

    S_IRWXU     00700   owner has read, write, and execute permission
    S_IRUSR     00400   owner has read permission
    S_IWUSR     00200   owner has write permission
    S_IXUSR     00100   owner has execute permission

    S_IRWXG     00070   group has read, write, and execute permission
    S_IRGRP     00040   group has read permission
    S_IWGRP     00020   group has write permission
    S_IXGRP     00010   group has execute permission

    S_IRWXO     00007   others (not in group) have  read,  write,  and
                        execute permission
    S_IROTH     00004   others have read permission
    S_IWOTH     00002   others have write permission
    S_IXOTH     00001   others have execute permission
*/
    //权限位, 0开头表示8进制，
    #define S_IRUSR 00400   //用户读权限
    #define S_IWUSR 00200   //用户写权限
    #define S_IXUSR 00100   //用户执行权限

    #define S_IRGRP 00040   //组读权限
    #define S_IWGRP 00020   //组写权限
    #define S_IXGRP 00010   //组执行权限
    
    #define S_IROTH 00004   //其他读权限
    #define S_IWOTH 00002   //其他写权限
    #define S_IXOTH 00001   //其他执行权限

    //C23 及部分编译器的 C11 扩展 开始，C 语言官方支持 二进制字面量，你可以直接使用 0b 前缀来表示二进制数。
    int binary_var = 0b1100; //二进制数，0b开头
    printf("binary_var = 0b1100, binary_var=%d\n", binary_var);
    int octal_var = 014; //八进制数，0开头
    printf("octal_var = 014, octal_var=%d\n", octal_var);
    int hex_var = 0xA; //十六进制数，0x开头
    printf("hex_var = 0xA, hex_var=%d\n", hex_var);

    // - `<<` —— Left shift (左移)
    binary_var = binary_var << 1; //左移1位，相当于乘以2
    printf("binary_var == 0b1100, binary_var << 1, binary_var=%d\n", binary_var);
    // - `>>` —— Right shift (右移)
    binary_var = 0b1100;
    binary_var = binary_var >> 1; //右移1位，相当于除以2
    printf("binary_var == 0b1100, binary_var >> 1, binary_var=%d\n", binary_var);
    // - `~` —— Bitwise NOT (按位取反)
    binary_var = 0b1100;
    binary_var = ~binary_var; //按位取反
    printf("binary_var == 0b1100, binary_var = ~binary_var, binary_var=%d\n", binary_var); //-13


    int bitwise_and = a & b; // Bitwise AND
    printf("a=21, b=10, bitwise_and = a & b, bitwise_and=%d\n", bitwise_and);
    


    exit(0);
}

// - `&` —— Bitwise AND (按位与)
// - `|` —— Bitwise OR (按位或)
// - `^` —— Bitwise XOR (按位异或)

// - `>>` —— Right shift (右移)

// ---

// 赋值运算符 (Assignment Operators)**
// - `=` —— Assignment (赋值) // - `+=` —— Add and assign (加后赋值)
// - `-=` —— Subtract and assign (减后赋值) // - `*=` —— Multiply and assign (乘后赋值)
// - `/=` —— Divide and assign (除后赋值) // - `%=` —— Modulus and assign (取模后赋值)
// - `&=` —— Bitwise AND and assign (按位与后赋值) // - `|=` —— Bitwise OR and assign (按位或后赋值)
// - `^=` —— Bitwise XOR and assign (按位异或后赋值) // - `<<=` —— Left shift and assign (左移后赋值)
// - `>>=` —— Right shift and assign (右移后赋值)

// ### 6. **)**
// - `? :` —— Ternary operator (三元运算符)

// ---

// ### 7. **其他运算符 (Other Operators)**
// - `sizeof` —— Size of operator (计算大小运算符)
// - `&` —— Address-of operator (取地址运算符)
// - `*` —— Pointer dereference operator (指针解引用运算符)
// - `,` —— Comma operator (逗号运算符)

// ---

// ### 示例代码：
// ```c
// #include <stdio.h>

// int main() {
//     // Arithmetic Operators
//     int a = 10, b = 3;
//     int sum = a + b;        // Addition
//     int difference = a - b; // Subtraction
//     int product = a * b;    // Multiplication
//     int quotient = a / b;   // Division
//     int remainder = a % b;  // Modulus

//     // Relational Operators
//     if (a == b) {           // Equal to
//         printf("a is equal to b\n");
//     }

//     // Logical Operators
//     if (a > 0 && b > 0) {   // Logical AND
//         printf("Both a and b are positive\n");
//     }

//     // Bitwise Operators
//     int bitwise_and = a & b; // Bitwise AND

//     // Assignment Operators
//     a += 5; // Add and assign

//     // Conditional Operator
//     int max = (a > b) ? a : b; // Ternary operator

//     // Other Operators
//     int size = sizeof(a); // Size of operator

//     return 0;
// }