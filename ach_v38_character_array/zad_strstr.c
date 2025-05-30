#include <stdio.h>
#include <string.h>
int main() 
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";

    char *result = strstr(haystack, needle);

    if (result) 
    {
        printf("Found:%s\n", result);
        // 计算返回指针在原字符串中的索引位置
        int index = result - haystack;
        printf("Index:%d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
/*
内存空间布局 的详细讲解，各个内存区域在**虚拟内存中的位置（高地址 → 低地址）**。

1.  程序的内存空间布局（虚拟地址空间）
   一段典型的程序在内存中的布局如下图(以32位Linux为例,64位类似,布局可能不同但原理一致):
		高地址（High Address）
		──────────────────────
		│      栈区（Stack）        │  ← 向下增长
		│  （局部变量，函数调用等）│
		├──────────────────────
		│      空闲区 / guard pages │
		├──────────────────────
		│      堆区（Heap）        │  ← 向上增长
		│  （malloc等动态分配）   │
		├──────────────────────
		│ BSS段（未初始化全局变量）│
		├──────────────────────
		│ 数据段（初始化全局变量）│
		├──────────────────────
		│ 代码段（text/code）     │
		│  （只读，存放机器指令） │
		低地址（Low Address）
2.  各区域详细说明：
    1. 代码区（Text Segment / Code Segment)
	内容**：存放程序的机器指令（编译后的代码）。
	特性**：
  	  通常是**只读**，防止恶意修改程序逻辑。
	  所有相同程序的进程可以共享这段代码，提高效率。
	  地址靠近低地址端**。
    2. 数据区（Data Segment)
	内容**：存放**已初始化的全局变量和静态变量**。
  	  例如：`int a = 5; static int x = 3;`
	  特性**：程序启动时由操作系统分配和初始化。
    3. BSS区（Block Started by Symbol）**
	内容**：存放**未初始化的全局变量和静态变量**。
  	  例如：`int b; static int y;`
	特性**：
  	  系统在程序启动时自动将这些变量初始化为0。
    4. 堆区（Heap）**
	内容：动态分配的内存，如 `malloc()`、`new` 分配的内存。
	特性**：
 	  程序运行时由程序员控制分配与释放。
	  从低地址向高地址增长**。
	  若管理不当，可能会造成内存泄漏或碎片。
    5. 栈区（Stack）**
	内容**：函数调用信息，如：
          返回地址
          局部变量
          参数传递等
	特性**：
	  由编译器自动分配和释放。
	  从高地址向低地址增长**。
	  栈大小有限，如果递归太深可能导致栈溢出。
3.   地址增长方向图示（32位系统为例）
	内存地址（高 → 低）：
		  0xFFFF_FFFF  ← 栈顶（高地址）
		       ↓ 向下生长
		   栈区（局部变量）
		       ↓
		   未使用空间
		       ↑
		   堆区（malloc） ← 向上生长
		       ↑
		   BSS段
		       ↑
		   数据段
		       ↑
		   代码段
		  0x0000_0000  ← 低地址
4.   栈和堆之间的“夹缝地带”

	栈和堆之间是**动态变化的空闲空间**。
	如果堆无限向上增长而栈也无限向下增长,它们可能*相撞*,导致程序崩溃(如内存耗尽)

     如果你需要我用图像方式可视化这部分内存结构，我也可以为你生成图解。需要吗？
*/
///////////////////////////////////////////////////////////////////
/*

const char *haystack = "Hello, world!";变量haystack在哪个区

	这是一个非常经典的问题，我们来逐步分析这句代码：
	const char *haystack = "Hello, world!";

1. 这句代码背后发生了什么？这实际上包含两个部分：
   i). 字符串字面量 `"Hello, world!"`** 是一个常量字符串，编译器会将它放在**代码段或只读数据段（.rodata).
   ii). const char *haystack是一个指针变量,它存储了这个字符串字面量的地址。

2. 各部分所属的内存区：
| 元素                      | 存放位置                                                               |
| ----------------------- | ------------------------------------------------------------------ |
| `"Hello, world!"` 字符串常量 | **只读数据段（.rodata）**（在代码区附近）                                         |
| 指针变量 `haystack`         | 如果在函数中定义：**栈区（Stack）**<br>如果是全局变量：**数据段（Data Segment）**（初始化的静态变量区） |

3. 示例分析：
情况 1：局部变量
		void foo() {
		    const char *haystack = "Hello, world!";
		}
* `haystack` 是局部变量，位于**栈区**。
* 它指向的 `"Hello, world!"` 是只读的，位于**代码区或.rodata区**。

情况 2：全局变量
		const char *haystack = "Hello, world!";
* `haystack` 是**初始化的全局指针变量**，存放在**数据段（Data Segment）**。
* 它指向的字符串字面量仍然在 **.rodata（只读数据段）**。

### 📌 小结

* 字符串 `"Hello, world!"` → **.rodata（只读数据段）**
* 指针 `haystack`：

  * 如果是**局部变量** → 在**栈区**
  * 如果是**全局或静态变量** → 在**数据段**

需要我帮你用图示画出这个内存分布吗？

*/

/*
const char *haystack = "Hello, world!";
    const char *needle = "world";

    char *result = strstr(haystack, needle);

    if (result) 
    {
        printf("Found:%s\n", result);
        // 计算返回指针在原字符串中的索引位置
        int index = result - haystack;
        printf("Index:%d\n", index);
    } else {
        printf("Substring not found.\n");
    }，index是正值，result的地址大于haystack吗

*/

/*

const char *haystack = "Hello, world!";变量haystack在哪个区

const char *haystack = "Hello, world!";
    const char *needle = "world";

    char *result = strstr(haystack, needle);

    if (result) 
    {
        printf("Found:%s\n", result);
        // 计算返回指针在原字符串中的索引位置
        int index = result - haystack;
        printf("Index:%d\n", index);
    } else {
        printf("Substring not found.\n");
    }，index是正值，result的地址大于haystack吗

是不是因为这里的变量地址是向上生长的


和大端存储、小端存储有关系吗

*/
