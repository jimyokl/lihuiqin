CFLAGS主要用于控制编译过程，比如警告、优化、调试、包含路径 等。

-g:生成gdb调试信息

优化选项
    -O0:            不优化(默认)
    -O1、-O2、-O3:  分别表示不同级别的优化
    -Os:            优化目标为减小代码大小
    -Ofast:         启用激进优化（可能不符合标准）。
警告控制
    -Wall:          开启大多数有用的警告。
    -Wextra:        开启额外的警告。
    -Werror:        把所有警告当作错误。
    -Wno-xxx:       关闭特定的警告，比如 `-Wno-unused-variable`。
标准和兼容性
    -std=c99, -std=c11: 使用特定的C语言标准
    -ansi:              等同于 -std=c89
    -pedantic:          强制标准兼容
包含路径
    -I./include:        指定头文件搜索路径
宏定义
    -DNAME=value:       定义宏，例如 -DDEBUG=1
    -Uname:             取消宏定义
目标平台/架构相关
    -m32:               生成32位代码
    -m64:               生成64位代码
    march=native:       为当前CPU优化。
代码检查和安全性
    -fstack-protector:      启用栈保护
    -fsanitize=address:     启用AddressSanitizer
    -fPIC:                  生成位置无关代码(常用于动态库)
其他有用选项
    -c:                 只编译，不链接（通常 `make` 自动处理）
    -E:                 只预处理，不编译
    -S:                 只编译到汇编，不生成机器码
    -v:                 显示详细编译信息

如果你正在调试程序，常见的设置如下:
CFLAGS = -Wall -Wextra -g -std=c11 -I./include

如果是发布版本，可以用优化选项替换-g:
CFLAGS = -Wall -O2 -std=c11 -I./include
