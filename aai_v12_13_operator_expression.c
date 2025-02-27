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
    printf("\n关系运算符: value of i>j: %d.\n", i>j);


// 3 ---------------------------------逻辑运算符 (Logical Operators)--------------------------------

// 3 ---------------------------------逻辑运算符 (Logical Operators)--------------------------------

    exit(0);
}


// ### 3. ****
// - `&&` —— Logical AND (逻辑与)
// - `||` —— Logical OR (逻辑或)
// - `!` —— Logical NOT (逻辑非)

// ---

// ### 4. **位运算符 (Bitwise Operators)**
// - `&` —— Bitwise AND (按位与)
// - `|` —— Bitwise OR (按位或)
// - `^` —— Bitwise XOR (按位异或)
// - `~` —— Bitwise NOT (按位取反)
// - `<<` —— Left shift (左移)
// - `>>` —— Right shift (右移)

// ---

// ### 5. **赋值运算符 (Assignment Operators)**
// - `=` —— Assignment (赋值)
// - `+=` —— Add and assign (加后赋值)
// - `-=` —— Subtract and assign (减后赋值)
// - `*=` —— Multiply and assign (乘后赋值)
// - `/=` —— Divide and assign (除后赋值)
// - `%=` —— Modulus and assign (取模后赋值)
// - `&=` —— Bitwise AND and assign (按位与后赋值)
// - `|=` —— Bitwise OR and assign (按位或后赋值)
// - `^=` —— Bitwise XOR and assign (按位异或后赋值)
// - `<<=` —— Left shift and assign (左移后赋值)
// - `>>=` —— Right shift and assign (右移后赋值)

// ---

// ### 6. **条件运算符 (Conditional Operator)**
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