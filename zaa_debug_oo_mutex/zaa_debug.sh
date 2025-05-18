gdb直接调式,把栈上相关地址内容都打印出来

gcc -g test.c -o test
gdb ./test
break main         # 设置断点在main函数,也可以在main内具体的某一行设置断点,比如行10: break 10, run
run                # 运行程序，停在 main
输入多个next        # 直到 执行完成 string_literal[N] = "p";
print str

x/10cb some_ptr:    从some_ptr指向的地址开始,以字符格式查看连续10个字节的内存内容.
x:                  examine(查看内存)
/10:                查看10个单位
c:                  以字符格式显示(character)
b:                  每单位为1字节(byte)
some_ptr:           起始地址(比如指针)
(gdb) x/10cb str
0x7fffffffe020: 112 'p'    114 'r'   111 'o' 116 't' 111 'o' 110 'n' 112 'p' 0 '\000'
0x7fffffffe028:  0 '\000'   0 '\000'

next/step/continue:
    next命令的作用:显示的代码是下一步要执行的，而不是已经执行完的。
    与step不同,next会跳过函数调用(不进入函数内部)
    与continue不同,next仅执行一行代码后暂停


想查看“上一条执行的是哪一行”，可以使用:(gdb) info line,可知当前停在哪一行,以及哪一行已经被执行
    (gdb) info line
    Line 11 of "ach_v38_init.c" starts at address 0x5555555551f1 <main+40> and ends at 0x555555555200 <main+55>


| 地址        |  属于的区域             |              用途                             |
| 0x5555...   | 代码段(Text Segment)   |    存储程序的指令(也就是你写的代码)              |
| 0x7fff...   | 栈区(Stack)            |    存储局部变量(如你定义的str和i)等函数栈帧      |

现代操作系统和编译器会使用 虚拟内存地址空间隔离，将不同的区域放在不同的地址范围，以增强安全性、性能和可移植性:

高地址(比如0x7fffffffffff)
│
├─── 栈区(stack),高地址向低地址增长,例如从 0x7fffffffe000 往下
│     用于函数调用、局部变量等
│     例如：你的 str 数组地址在这里,例子：0x7fffffffe020
│       ...
│
├─── 堆区(heap)
│     动态分配内存区域(malloc/new)
│       ...
│
├─── BSS 段（未初始化的全局变量）
│
├─── 数据段(data segment)
│     已初始化的全局变量
│
├─── 代码段(text segment)          0x400000 - 0x600000 左右，例如 0x55555555xxxx
│     存放编译后的机器指令
│     例如:main 函数的地址
│     例子:0x5555555551f1
│
├─── 程序入口（例如 0x400000 左右）
│
低地址(例如 0x000000000000)


char str[M] 是一个局部变量，放在栈上，因此它的地址是：0x7fffffffe020（高地址）

main 函数代码在可执行文件中属于代码段，加载后地址是：0x5555555551f1（较低地址）

栈是从高地址往低地址增长的;堆是从低地址往高地址增长的.

各段之间有空隙,防止越界(栈溢出,堆溢出等问题),这种布局也有助于实现例如ASLR(地址空间随机化),增强安全性.


看到完整的内存映射：
(gdb) info proc mappings
会列出程序各段(text、heap、stack、libs等)的地址范围，
你会看到代码段(text segment)是低地址，栈段(stack segment)是高地址。
(gdb) info proc mappings
process 19259
Mapped address spaces:
    Start Addr           End Addr       Size     Offset  Perms  objfile
0x555555554000     0x555555555000     0x1000        0x0  r--p   lihuiqin/ach_v38_character_array/ach_v38_init
0x555555555000     0x555555556000     0x1000     0x1000  r-xp   lihuiqin/ach_v38_character_array/ach_v38_init
0x555555556000     0x555555557000     0x1000     0x2000  r--p   lihuiqin/ach_v38_character_array/ach_v38_init
0x555555557000     0x555555558000     0x1000     0x2000  r--p   lihuiqin/ach_v38_character_array/ach_v38_init
0x555555558000     0x555555559000     0x1000     0x3000  rw-p   lihuiqin/ach_v38_character_array/ach_v38_init
0x555555559000     0x55555557a000    0x21000        0x0  rw-p   [heap]
0x7ffff7da4000     0x7ffff7da7000     0x3000        0x0  rw-p
0x7ffff7da7000     0x7ffff7dcf000    0x28000        0x0  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
0x7ffff7dcf000     0x7ffff7f57000   0x188000    0x28000  r-xp   /usr/lib/x86_64-linux-gnu/libc.so.6
0x7ffff7f57000     0x7ffff7fa6000    0x4f000   0x1b0000  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
0x7ffff7fa6000     0x7ffff7faa000     0x4000   0x1fe000  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
0x7ffff7faa000     0x7ffff7fac000     0x2000   0x202000  rw-p   /usr/lib/x86_64-linux-gnu/libc.so.6
0x7ffff7fac000     0x7ffff7fb9000     0xd000        0x0  rw-p
0x7ffff7fbe000     0x7ffff7fc0000     0x2000        0x0  rw-p
0x7ffff7fc0000     0x7ffff7fc4000     0x4000        0x0  r--p   [vvar]
0x7ffff7fc4000     0x7ffff7fc5000     0x1000        0x0  r-xp   [vdso]
0x7ffff7fc5000     0x7ffff7fc6000     0x1000        0x0  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
0x7ffff7fc6000     0x7ffff7ff1000    0x2b000     0x1000  r-xp   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
0x7ffff7ff1000     0x7ffff7ffb000     0xa000    0x2c000  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
0x7ffff7ffb000     0x7ffff7ffd000     0x2000    0x36000  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
0x7ffff7ffd000     0x7ffff7fff000     0x2000    0x38000  rw-p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
0x7ffffffde000     0x7ffffffff000    0x21000        0x0  rw-p   [stack]
每一行代表该进程中一个连续的地址区间的映射信息,包括代码段、数据段、堆、栈、共享库等
| 列名         | 含义                                             |
| ---------- | ---------------------------------------------- |
| Start Addr | 映射区域的起始地址                                      |
| End Addr   | 映射区域的结束地址                                      |
| Size       | 映射区域的大小（End - Start）                           |
| Offset     | 在文件中的偏移位置（如果映射的是文件）                            |
| Perms      | 访问权限：r=读，w=写，x=执行，p=私有（拷贝写）                    |
| objfile    | 映射对应的文件或对象（比如二进制文件、共享库、匿名映射、\[heap]、\[stack]等） |

程序自身的可执行文件:0x555555554000 - 0x555555559000
映射的是可执行文件 /home/yan/.../ach_v38_init, 分为多个段:
r--p:只读段(一般是ELF头等)
r-xp:可执行代码段(.text 段）
rw-p:可写段(.data 段）
多段的起止地址和偏移不同，反映了ELF 文件的布局

堆内存:0x555555559000 - 0x55555557a000
rw-p[heap]
rw-p可读写，私有映射。
动态分配的内存(如malloc)来自这里

C库(libc.so.6)
0x7ffff7da7000 - 0x7ffff7faa000    r-xp   /usr/lib/x86_64-linux-gnu/libc.so.6
r-xp:只读 + 可执行，加载了 libc 的.text段
后面还有.data, .bss, 符号表等对应的段

动态链接器(ld-linux-x86-64.so.2)
0x7ffff7fc5000 - 0x7ffff7fff000
加载负责运行时链接的动态链接器。
包括代码段(r-xp), 数据段(rw-p), 只读段等

虚拟变量区和虚拟动态共享对象(VVAR, VDSO):
0x7ffff7fc0000 - 0x7ffff7fc4000    r--p   [vvar]
0x7ffff7fc4000 - 0x7ffff7fc5000    r-xp   [vdso]
vvar` 和 `vdso` 是内核提供的特殊内存映射
用于高效执行系统调用(如gettimeofday)而不切换到内核

栈空间：
0x7ffffffde000 - 0x7ffffffff000    rw-p   [stack]
用户空间的栈，支持局部变量、函数调用等
会根据需要动态增长(向低地址方向)

总结:
程序在内存中各段的位置、权限、文件映射等
    检查段权限是否合理(防止代码注入)
    理解崩溃时栈/堆/库函数地址情况
    判断段的增长与释放情况


This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>     Enable debuginfod for this session? (y or [n])

建议输入n(默认值),因为这个功能对调试你自己的程序通常不需要
它的作用是:当调试系统库(如libc,libm等)时,可以自动下载符号信息,让你能看到库函数的源代码和更详细的信息
但在你当前这种情况(调试你自己的代码，例如 puts(str);),这个功能没有帮助,还可能让调试变慢或联网失败.
