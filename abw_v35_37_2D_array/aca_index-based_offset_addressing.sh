C语言中，数组用下标偏移量寻址:

In C, arrays are accessed using index-based offset addressing.
C uses index offsets to compute the address of array elements.
Array elements in C are accessed via pointer arithmetic using index offsets.
In C, array indexing is equivalent to pointer offset addressing.


例如：
In C, accessing `arr[i]` is equivalent to `*(arr + i)`, which uses index offset addressing.
C relies on pointer arithmetic for array indexing, using the offset from the base address.



二维数组a[2][3]，用a[2][0]可以得到a[1][1]的值吗？

2行3列的数组，内存中按行优先存储
a[0][0], a[0][1], a[0][2],
a[1][0], a[1][1], a[1][2]

a[2][0]超出了数组的行边界（最大行索引是1），未定义行为，非法访问内存地址

数组访问是通过数组的基地址加上偏移量。

base+(i*列数+j)*元素大小，a[2][0]偏移量是(2*3+0)*元素大小，越界了，a[1][1]的偏移量是 (1*3+1)*元素大小

两者在内存中的关系depend on 编译器的具体实现。

  a[1][1]的地址是&a[0][0] + 1 * 3 + 1 = &a[0][0] + 4，假设 int 类型每个元素占1个单位
  a[2][0]的地址是&a[0][0] + 2 * 3 + 0 = &a[0][0] + 6。


行指针
Row pointer — 常见在
                    数据库、
                    矩阵运算（稀疏矩阵压缩格式（如 CSR：Compressed Sparse Row）
                    或编程
                    中表示指向某一行的指针。