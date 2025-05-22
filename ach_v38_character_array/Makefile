CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -I./include
LDFLAGS = -lm

# 查找所有 .c 文件
SRC = $(wildcard *.c)

# 生成对应的可执行文件名称（去掉 .c 扩展）
TARGETS = $(basename $(SRC))

OBJ = $(SRC:.c=.o)

# 规则：编译所有目标
all: $(TARGETS)

#下面5行编译所有的源文件
#$(TARGETS): $(OBJ)
#	$(CC) $(OBJ) -o $(TARGETS) $(LDFLAGS)
# 通用编译规则
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

# 下面的规则可以编译单个源文件为目标文件
# 动态编译规则,对于每个源文件，创建一个对应的目标文件（即去掉 .c 后缀的文件）。
# 例如，如果有 main1.c，它将生成 main1，并且 make 会把 main1.c 编译成 main1。
$(TARGETS): %: %.c
	$(CC) $(CFLAGS) -o $@ $<  $(LDFLAGS)

#%：这是一个模式字符，用来代表目标文件和源文件中公共部分的“占位符”。在规则中，% 将会被文件名的具体部分替换掉。它相当于正则表达式中的通配符。
#在 $(BASENAMES): %: %.c 这个规则中，% 表示目标文件的名称和源文件名称中共同部分的占位符。换句话说，它让我们可以为多个文件定义相同的规则。
#$(BASENAMES) 是一个由源文件名去除 .c 后缀得到的目标文件名列表。因此，% 将匹配这些目标文件。
#$(BASENAMES) 是目标文件的名字，实际情况下就是去掉 .c 后缀的文件名。
# 假设你的目录下有以下源文件：main1.c main2.c 
# basename 操作后，$(BASENAMES) 会变成 main1、main2
# make main1 时，% 会被 main1 替代，%.c 就会变成 main1.c

clean:
	rm -f $(OBJ) $(TARGETS)
