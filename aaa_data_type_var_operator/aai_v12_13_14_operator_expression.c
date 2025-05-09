#include <stdio.h>
#include <stdlib.h>
int main()
{
// 1 ---------------------------------Arithmetic Operators--------------------------------
//Subtraction —— 减法; (Multiplication) —— 乘法; (Division) / —— 除法; (Modulus) % —— 取余(模运算);
//(Increment) ++ —— 自增; (Decrement) -- —— 自减
    int a = 21; int b = 10; int c ;
    printf("int a, sizeof(a): %zd.\n", sizeof a);
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

    printf("          **************   assignment operator, assignment expression:   **************\n");
    int var_assignment_a =6;
    printf("var_assignment_a =%d\n", var_assignment_a);
    var_assignment_a *= var_assignment_a += 3; //warning: operation on ‘var_assignment_a’ *= may be undefined
    // var_assignment_a -= var_assignment_a*= var_assignment_a += 3, now var_assignment_a=0
    printf("var_assignment_a*= var_assignment_a += 3, var_assignment_a=%d\n", var_assignment_a); //81

    int assignment_expression_a = 5, assignment_expression_b;
    // x = y中，y 的值会被赋给 x，同时整个赋值表达式的值是 y 的值。
    assignment_expression_b = assignment_expression_a = 5;
    printf("assignment_expression_a = 5, assignment_expression_b = assignment_expression_a = 5, assignment_expression_b=%d.\n", assignment_expression_b); //5
    int xx, yy, zz; xx = (yy = (zz = 10)); 
    printf("xx=(yy=(zz=10)), xx=%d, yy=%d, zz=%d\n", xx, yy, zz); //10

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

    int complement_var = 0xfffffff3;
    printf("complement_var = 0xfffffff3, complement_var=%d\n", complement_var);
    //如果 0xfffffff3 是一个有符号整数（如 int），它会被解释为补码形式。
    //补码表示法中，最高位 1 表示负数，其值的计算方法是：求原码（即正数对应的绝对值）：计算 补码转原码，方法是 先取反，再加 1。
    //补码表示法会导致额外的 -1 偏移,所以加1

    //最高位（第 31 位）是 1，表示这是一个负数。
    //1111 1111 1111 1111 1111 1111 1111 0011这是一个负数的补码表示。
    //要得到它的十进制值，需要将其转换回原码：取反加一。
    //取反：0000 0000 0000 0000 0000 0000 0000 1100。加 1：0000 0000 0000 0000 0000 0000 0000 1101。
    //转换为十进制：13, 因为是负数(符号位是1)，所以最终值为 -13。

    

    //C语言及计算机系统中，整数默认以补码形式存储，这使得计算更高效、简洁
    //正数：正数的补码与其原码相同。
    //负数：负数的补码是其原码除符号位外取反加1。
    //n位二进制数，补码表示的范围为：最小值为 − 2^(n−1), 最大值为2^(n−1) −1。

    int bitwise_and = a & b; // Bitwise AND
    printf("a=%d(10101), b=%d(1010), bitwise_and = a & b, bitwise_and=%d\n", a, b, bitwise_and);

    int bitwise_or = a | b; // Bitwise OR
    printf("a=%d(10101), b=%d(1010), bitwise_or = a | b, bitwise_or=%d\n", a, b, bitwise_or);
    //21的二进制是0b10101，10的二进制是0b1010，按位或后是0b11111，十进制是31
    
    int bitwise_xor = a ^ b; // Bitwise XOR (按位异或)
    printf("a=%d(10101), b=%d(1010), bitwise_xor = a ^ b, bitwise_xor=%d\n", a, b, bitwise_xor);
    //21的二进制是0b10101，10的二进制是0b1010，按位异或后是0b11111，十进制是31

    // >>, right shift
    int right_shift_var = 0b1100;
    right_shift_var = right_shift_var >> 1; //右移1位，相当于除以2
    printf("right_shift_var == 0b1100, right_shift_var >> 1, right_shift_var=%d\n", right_shift_var);

    // <<, left shift
    int left_shift_var = 0b1100;
    left_shift_var = left_shift_var << 1; //左移1位，相当于乘以2
    printf("left_shift_var == 0b1100, left_shift_var << 1, left_shift_var=%d\n", left_shift_var);

    printf("\n位运算符 (Bitwise Operators) set a bit to 1:\n");
    // set a bit to 1
    int set_bit_var = 0b1100;
    int set_bit_pos = 1;
    int set_bit_pos_value = 1 << set_bit_pos;
    set_bit_var = set_bit_var | set_bit_pos_value;
    printf("set_bit_var == 0b1100, 1<< left shift 1, set_bit_var = set_bit_var | set_bit_pos_value, set_bit_var=%d\n", set_bit_var);

    // set a bit to 0
    int set_bit_var_0 = 0b1111;
    int set_bit_pos_0 = 2;  //第3位 
    int set_bit_pos_value_0 = ~(1 << set_bit_pos_0); //取反
    set_bit_var_0 = set_bit_var_0 & set_bit_pos_value_0;
    printf("set_bit_var_0 == 0b1111, ~(1<< left shift 2), set_bit_var_0=set_bit_var_0 & set_bit_pos_value_0, set_bit_var_0=%d\n", set_bit_var_0);

    //慧芹老师布置作业：C语言位运算，如何从一个指定宽度的数中取出其中的某几位?

    unsigned int number = 0b11011010; // 二进制 11011010，十进制 218
    int start = 2;                   // 从第 2 位开始
    int width = 4;                   // 提取 4 位
    unsigned int mask = (1 << width) - 1; // 生成掩码 00001111
    unsigned int result = (number >> start) & mask; // 右移 2 位并应用掩码
    printf("\nselect bits from a number: number=0b11011010, start=2 (实际上是从右到左第3位), width=4\n");
    printf("result = (number >> start) & mask, mask=0b00001111, result=%d\n", result); // 6

    exit(0);
}

// - `/=` —— Divide and assign (除后赋值) // - `%=` —— Modulus and assign (取模后赋值)
// - `&=` —— Bitwise AND and assign (按位与后赋值) // - `|=` —— Bitwise OR and assign (按位或后赋值)
// - `^=` —— Bitwise XOR and assign (按位异或后赋值) // - `<<=` —— Left shift and assign (左移后赋值)
// - `>>=` —— Right shift and assign (右移后赋值)

// - `&` —— Address-of operator (取地址运算符)
// - `*` —— Pointer dereference operator (指针解引用运算符)
// - `,` —— Comma operator (逗号运算符)

//     // Arithmetic Operators
//     int sum = a + b;        // Addition
//     int difference = a - b; // Subtraction
//     int product = a * b;    // Multiplication
//     int quotient = a / b;   // Division
//     int remainder = a % b;  // Modulus

//     // Relational Operators
//     if (a == b) {           // Equal to

//     int max = (a > b) ? a : b; // Ternary operator