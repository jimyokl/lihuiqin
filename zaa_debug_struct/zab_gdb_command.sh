
bt是backtrace的缩写,用于显示当前程序的函数调用栈(即调用堆栈)
它可以帮助你查看程序运行到当前位置时，经过了哪些函数调用，非常适合用来调试程序崩溃、断点处或异常行为的问题。

用法示例：
(gdb) bt
输出示例：
#0  func_c () at main.c:12
#1  0x0804841a in func_b () at main.c:8
#2  0x08048406 in func_a () at main.c:4
#3  0x080483f2 in main () at main.c:2
这说明程序目前停在func_c(),而它是被func_b()调用的,func_b()又是被func_a()调用的,依此类推直到main()

常见扩展用法：
    bt full:    显示每一帧中局部变量的详细信息。
    bt n:       只显示前 `n` 层调用栈。
                bt后接帧号范围,例如: bt 3 5, 显示第3到第5层调用

如果你在调试程序崩溃(如segmentation fault), bt是查看错误发生路径的首选命令


backtrace显示当前线程的函数调用栈，也就是程序是如何一步步调用到当前代码位置的
用法：
(gdb) backtrace 或者简写为： (gdb) bt
显示结果说明：
举个例子：
#0  func_c () at example.c:30
#1  func_b () at example.c:20
#2  func_a () at example.c:10
#3  main () at example.c:5
这个调用栈的含义是：
* 当前程序停在 `func_c` 中（这是栈顶，编号为 `#0`）
* `func_c` 是被 `func_b` 调用的
* `func_b` 是被 `func_a` 调用的
* `func_a` 是在 `main` 函数中被调用的（栈底）
常见用途：
* 当程序崩溃（比如 segmentation fault）时，`backtrace` 能帮助你找到导致崩溃的函数调用链。
* 可以配合 `frame` 命令查看具体某一帧的变量状态：
  (gdb) frame 1  # 查看调用栈中第1帧的上下文
常用变体：
* `bt full`：不仅显示函数调用栈，还显示每一帧中的局部变量的值。
* `bt n`：只显示前 n 层的栈帧，例如 `bt 5`。



0000000011117777777######$$$$$$$########---------11----------######$$$$$$$########--------------

GDB调试已运行的本地进程(即attach模式),可以让你在程序正在运行时将调试器“附加”到这个进程上，从而进行调试操作。
这在调试守护进程、服务或某些只在特定情况下出错的程序时特别有用。

前提准备
    1.程序 用 带调试信息(-g)的方式编译
    2.GDB对目标进程有足够权限(通常是相同用户,或使用sudo)

2.attach到进程: gdb xxx, 进入GDB后输入: attach <PID>
  或者直接一行命令: gdb -p <PID>

    如果想附加的进程属于另一个用户,可能需要sudo: sudo gdb -p <PID> 

3.附加成功后的调试
    查看调用栈：  bt
    查看变量值：  print var_name
    设置断点：    break function_name
    恢复程序运行: continue

4.退出调试器并让程序继续运行
    detach
    quit
    如果直接 `quit` 而没有 `detach`，程序可能会被终止

补充（权限不足问题）:有些 Linux 系统（如 Ubuntu 20.04+）出于安全原因默认限制调试其他进程。
解决方法（临时）：
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
永久修改可编辑 `/etc/sysctl.d/10-ptrace.conf` 或 `/etc/sysctl.conf`：
kernel.yama.ptrace_scope = 0
然后执行: sudo sysctl -p

0000011117777777######$$$$$$$########---------22gdb调试模式----------######$$$$$$$########--------------

+------------------+--------------------------+----------------------------------------+
| 模式             | 用途                      | 命令示例                               |
+------------------+---------------------------+---------------------------------------+
| 启动调试         | 调试新启动的程序           | gdb ./a.out                             |
| attach           | 附加到运行中的进程         | gdb -p 1234                            |
| core dump        | 分析崩溃后的 core 文件    | gdb ./a.out core                        |
| remote           | 跨主机调试                | target remote ip:port          gdbserver|
| 批处理（batch）  | 自动化调试                 | gdb -batch -x script.gdb ./a.out        |
| TUI 模式         | 图形化终端界面             | gdb -tui ./a.out                        |
+------------------+---------------------------+----------------------------------------+


00000011117777777######$$$$$$$########---------33info proc mapping----------######$$$$$$$########--------------

查看当前调试进程的内存映射情况,即这个进程的地址空间中各个区域（比如代码段、数据段、堆、栈、共享库等）是如何映射的
命令语法：
(gdb) info proc mapping
通常在使用GDB调试已运行的本地进程(attach模式)或运行某个 ELF 程序时可用（需要 GDB 启动时启用 `/proc` 支持，如在 Linux 上）。

映射区域的意思：

内存映射区域指的是一个进程虚拟地址空间中一段连续的地址区间，这段地址有对应的用途和属性。比如：

* 可执行文件的代码段 `.text`（只读 + 可执行）
* 数据段 `.data`（可读写）
* 动态链接库（共享库）
* 栈（stack）
* 堆（heap）
* 匿名映射（比如 malloc 分配的内存）

输出示例：

(gdb) info proc mapping
process 12345
Mapped address spaces:

Start Addr   End Addr       Size     Offset objfile
0x00400000  0x0040b000      0xb000   0x0     /path/to/a.out
0x0060a000  0x0060b000      0x1000   0x0     [heap]
0x7ffff7dd7000 0x7ffff7ff2000 0x21b000 0x0   /lib/x86_64-linux-gnu/libc-2.31.so
0x7ffffffde000 0x7ffffffff000 0x21000 0x0     [stack]
各列含义说明：
* **Start Addr / End Addr**：起始和结束的虚拟地址
* **Size**：区域大小
* **Offset**：映射文件中的偏移
* **objfile**：映射的文件路径，或特殊用途的标签（如 `[heap]`、`[stack]`、`[vdso]` 等）
用途：
* 查找程序崩溃地址属于哪段（代码段？堆？栈？）
* 分析共享库是否正确加载
* 理解程序内存布局（尤其调试 malloc、栈溢出等问题时）
* 与 `/proc/<pid>/maps` 信息类似，但格式更易读


如需进一步调试内存映射内容，也可以直接查看：
cat /proc/<pid>/maps
