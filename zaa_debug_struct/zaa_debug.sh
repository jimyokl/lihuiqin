

看汇编呗，把栈帧画出来，或者gdb直接调式，把栈上相关地址内容都打印出来

gcc -g test.c -o test
gdb ./test

break main         # 设置断点在main函数,也可以在main内具体的某一行设置断点,比如行10: break 10, run

run                # 运行程序，停在 main

print str

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n])

建议输入 n（默认值），因为这个功能对调试你自己的程序通常不需要。

它的作用是：当调试系统库（如 libc、libm 等）时，可以自动下载符号信息，让你能看到库函数的源代码和更详细的信息。

但在你当前这种情况（调试你自己的代码，例如 puts(str);），这个功能没有帮助，还可能让调试变慢或联网失败。



x/10cb some_ptr：
从some_ptr指向的地址开始，以字符格式查看连续10个字节的内存内容。

x:         examine(查看内存)
/10:       查看10个单位
c:         以字符格式显示(character)
b:         每单位为1字节(byte)
some_ptr:  起始地址(比如指针)


看到完整的内存映射：
(gdb) info proc mappings
会列出程序各段(text、heap、stack、libs等)的地址范围，
你会看到代码段(text segment)是低地址，栈段(stack segment)是高地址。




在GDB中,next命令的作用:显示的代码是下一步要执行的，而不是已经执行完的。

与step不同,next会跳过函数调用(不进入函数内部)

与continue不同,next仅执行一行代码后暂停.


想查看“上一条执行的是哪一行”，可以使用：(gdb) info line, 可知当前停在哪一行、以及哪一行已经被执行

(gdb) info line
Line 11 of "ach_v38_init.c" starts at address 0x5555555551f1 <main+40> and ends at 0x555555555200 <main+55>.

(gdb) x/10cb str
0x7fffffffe020: 112 'p' 114 'r' 111 'o' 116 't' 111 'o' 110 'n' 112 'p' 0 '\000'
0x7fffffffe028: 0 '\000'        0 '\000'

| 地址        |  属于的区域             |              用途                                       |
| 0x5555...   | 代码段（Text Segment）  |    存储程序的指令（也就是你写的代码）                     |
| 0x7fff...   | 栈区（Stack）           |    存储局部变量（如你定义的 `str` 和 `i`）等函数栈帧      |

现代操作系统和编译器会使用 虚拟内存地址空间隔离，将不同的区域放在不同的地址范围，以增强安全性、性能和可移植性。
低地址
│
├── 代码段(text):       0x400000 - 0x600000 左右，例如 0x55555555xxxx
│
├── 数据段/堆(heap):    动态分配的内存（malloc）
│
├── ...
│
├── 栈(stack):         高地址向低地址增长，例如从 0x7fffffffe000 往下
│
高地址


(gdb) info proc mappings
会列出程序各段（text、heap、stack、libs等）的地址范围，
你会看到代码段（text segment）是低地址，栈段（stack segment）是高地址。


高地址（比如 0x7fffffffffff）
│
├─── 栈区（stack）
│     用于函数调用、局部变量等
│     例如：你的 str 数组地址在这里
│     例子：0x7fffffffe020
│
│       ...
│
├─── 堆区（heap）
│     动态分配内存区域（malloc/new）
│
│       ...
│
├─── BSS 段（未初始化的全局变量）
│
├─── 数据段（data segment）
│     已初始化的全局变量
│
├─── 代码段（text segment）
│     存放编译后的机器指令
│     例如：main 函数的地址
│     例子：0x5555555551f1
│
├─── 程序入口（例如 0x400000 左右）
│
低地址（例如 0x000000000000）


char str[M] 是一个局部变量，放在栈上，因此它的地址是：
0x7fffffffe020（高地址）

main 函数代码在可执行文件中属于代码段，加载后地址是：
0x5555555551f1（较低地址）

栈是从高地址往低地址增长的。

堆是从低地址往高地址增长的。

各段之间有空隙，防止越界(栈溢出、堆溢出等问题),
这种布局也有助于实现例如ASLR(地址空间随机化),增强安全性。