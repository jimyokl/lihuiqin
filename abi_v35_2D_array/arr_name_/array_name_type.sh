要注意你的想法，只是你的想法，和现实很有可能是有区别的。

a[2][3]的类型: int (*)[3], int[2][3], 

   a[i]表示二维数组的第 i 行，类型是int[3]，也可以理解为a[i]是一个指向int数组的指针，
   a[i]是一个int[3]类型的数组（即指向包含 3 个int的数组）。

二维数组的名字，传递给函数时会退化为指针（即指向数组的首元素），不能代表完整的二维数组结构。
编译器不能根据一个一维指针计算二维数组元素的地址。
不能arr[i][j]来做下标操作，

   void printArray(int *arr, int rows, int cols) {  printf("arr[%d][%d]=%d\n", i, j, arr[i * cols + j]);

   int main() {        printArray((int*)arr, 3, 3);  // 注意传递行列数    }

   print2DArray(&arr[0][0], rows, cols);

2. 传递二维数组的指针a[2][3]，数组名的类型实际上是一个指向一维数组的指针

   a[2][3]/arr[][3] 实际上是一个 2 个元素的数组，每个元素都是一个包含 3 个整数的数组。
   会被编译器处理成指向一维数组的指针，a是一个指向包含3个整数元素的一维数组的指针（即int (*)[3]）。
   
   将参数声明为指向二维数组的指针，指定数组的维度（列数），这样可以避免指针退化的问题。
   可以arr[i][j]下标操作

3. arr[i * cols + j] 和 *(arr + i * cols + j) 连续分配，一维数组或动态分配的“伪二维数组”。

   动态分配，内存是按行优先顺序连续分配的：
   int rows = 3, cols = 3;  int* arr = (int*)malloc(rows * cols * sizeof(int));  // 按一维连续分配内存
   for (int i = 0; i < rows; i++) 
       for (int j = 0; j < cols; j++) 
           *(arr + i * cols + j) = i * cols + j + 1;  // 填充数据

4. 非连续内存的二维数组：指向数组的数组，（eg int* arr[3]），

   int* arr[3];  // 这是一个指针数组，每个元素都是指向int的指针
   arr[0] = (int*)malloc(3 * sizeof(int));  // 为每行分配内存
   arr[1] = (int*)malloc(3 * sizeof(int));
   arr[2] = (int*)malloc(3 * sizeof(int));

   每一行的内存是独立分配的，不能使用 arr[i * cols + j]，要用 arr[i][j] 或  *(arr[i] + j)。

5. err example: &arr_two_three会得到int (*)[2][3]
int (*)[2][3]看起来像指向“整个二维数组”(int[2][3])的指针，这样的声明不符合语法规则，不能有一个指向整个数组的指针，