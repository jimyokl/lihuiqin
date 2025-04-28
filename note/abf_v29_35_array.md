五、数组

特点：构造类型之一，连续存放相同类型的元素。

3座大山：数组、指针、函数
易混淆点：3者一起用，函数传参，传指针数组 or 数组指针，指针的引用，

1、一维数组
    i)  定义
        [存储类型] 数据类型 标识符 [下标]，下标是常量表达式        
    ii) 初始化
        {0}
        static类型
    iii)元素引用
    iv) 数组名
        数组名是表示地址的常量，也是数组的起始位置。
    v)  数组越界

2、二维数组
   i) 定义、初始化
      [存储类型] 数据类型 标识符 [行下标][列下标]，下标是常量表达式
  ii) 元素引用
 iii) 存储形式
      顺序存储--按行存储
  iv) 深入理解二维数组


3、字符数组


4、指针数组 vs 数组指针
    int *p[3]，[]的优先级高于*，会先执行数组声明，然后 再解释 每个元素的类型是int *(指向整数的指针)
    这是一个指针数组，包含 3 个元素
    eg,
    int a = 1, b = 2, c = 3;
    int *p[3] = { &a, &b, &c };  // 三个 int 指针组成的数组


    int (*p)[3]是一个指向包含3个int的数组的指针，
    eg,
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int (*p)[3] = arr;   // 指向第一个子数组，即 arr[0]
    (*p)[1] 是第 2 个元素（即 arr[0][1]）

5、求行数、列数
   sizeof(arr) / sizeof(arr[0]);
   sizeof(arr[0]) / sizeof(arr[0][0];

6、index scope, offset，访问越界
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

7、arr name的类型
  一、
    a[2][3]的类型: int (*)[3], int[2][3], 

    a[i]表示二维数组的第 i 行，类型是int[3]，也可以理解为a[i]是一个指向int数组的指针，
    a[i]是一个int[3]类型的数组（即指向包含 3 个int的数组）。

    二维数组的名字，传递给函数时会退化为指针（即指向数组的首元素），不能代表完整的二维数组结构。
    编译器不能根据一个一维指针计算二维数组元素的地址。
    不能arr[i][j]来做下标操作，

    void printArray(int *arr, int rows, int cols) {  printf("arr[%d][%d]=%d\n", i, j, arr[i * cols + j]);

    int main() {        printArray((int*)arr, 3, 3);  // 注意传递行列数    }

    print2DArray(&arr[0][0], rows, cols);

  二、 传递二维数组的指针a[2][3]，数组名的类型实际上是一个指向一维数组的指针

   a[2][3]/arr[][3] 实际上是一个 2 个元素的数组，每个元素都是一个包含 3 个整数的数组。
   会被编译器处理成指向一维数组的指针，a是一个指向包含3个整数元素的一维数组的指针（即int (*)[3]）。
   
   将参数声明为指向二维数组的指针，指定数组的维度（列数），这样可以避免指针退化的问题。
   可以arr[i][j]下标操作

  三、 arr[i * cols + j] 和 *(arr + i * cols + j) 连续分配，一维数组或动态分配的“伪二维数组”。

   动态分配，内存是按行优先顺序连续分配的：
   int rows = 3, cols = 3;  int* arr = (int*)malloc(rows * cols * sizeof(int));  // 按一维连续分配内存
   for (int i = 0; i < rows; i++) 
       for (int j = 0; j < cols; j++) 
           *(arr + i * cols + j) = i * cols + j + 1;  // 填充数据

  四、 非连续内存的二维数组：指向数组的数组，（eg int* arr[3]），

   int* arr[3];  // 这是一个指针数组，每个元素都是指向int的指针
   arr[0] = (int*)malloc(3 * sizeof(int));  // 为每行分配内存
   arr[1] = (int*)malloc(3 * sizeof(int));
   arr[2] = (int*)malloc(3 * sizeof(int));

   每一行的内存是独立分配的，不能使用 arr[i * cols + j]，要用 arr[i][j] 或  *(arr[i] + j)。

  五、 err example: &arr_two_three会得到int (*)[2][3]
   int (*)[2][3]看起来像指向“整个二维数组”(int[2][3])的指针，这样的声明不符合语法规则，不能有一个指向整个数组的指针，

8、
    //warn: passing argument 1 of ‘print2DArray’ from incompatible pointer type [Wincompatible -pointer-types]

    //error: j of arr[i][j], subscripted value is neither array nor pointer nor vector
