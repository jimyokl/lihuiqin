CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

# 查找所有 .c 文件
SRC = $(wildcard *.c)

# 生成对应的可执行文件名称（去掉 .c 扩展）
TARGETS = $(basename $(SRC))

OBJ = $(SRC:.c=.o)

# 规则：编译所有目标
all: $(TARGETS)

$(TARGETS): $(OBJ)
	$(CC) $(OBJ) -o $(TARGETS) $(LDFLAGS)

# 通用编译规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGETS)