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
    int sum = 17, count = 5;
    double mean;
    mean =  sum / count;
    double mean_type_casting = (double) sum / count;
    printf("sum=17, count=5, mean = sum / count, mean=%f\n", mean);
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
    int bitwise_and = a & b; // Bitwise AND
    printf("a=21, b=10, bitwise_and = a & b, bitwise_and=%d\n", bitwise_and);
    


    exit(0);
}

// ---

// ### 4. **位运算符 (Bitwise Operators)**
// - `&` —— Bitwise AND (按位与)
// - `|` —— Bitwise OR (按位或)
// - `^` —— Bitwise XOR (按位异或)
// - `~` —— Bitwise NOT (按位取反)
// - `<<` —— Left shift (左移)
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