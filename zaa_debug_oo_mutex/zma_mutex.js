
1. may18 msys2环境编译读取chrome cookie程序：

   3行代码作用：不关闭文件的情况下获取文件的大小，并且在获取大小后将文件指针恢复到文件的起始位置
预先分配内存: 在读取文件内容之前，知道文件的大小可以方便地动态分配足够大的内存缓冲区来存储整个文件内容，
从而避免多次 realloc 操作

fseek(fp, 0, SEEK_END);
file_size = ftell(fp);
fseek(fp, 0, SEEK_SET);

fseek(fp, 0, SEEK_END); 将fp 文件指针从当前位置移动到文件的末尾，并且不产生任何偏移。 
执行完这行代码后，文件指针会指向文件的最后一个字节的后面

2. 查看fseek源代码，musl libc: 这是一个轻量级的 C 标准库
   https://git.musl-libc.org/cgit/musl/tree/src/stdio/fseek.c
   主要函数是int __fseeko_unlocked(FILE *f, off_t off, int whence)，_unlocked 表明这个函数在调用时假定
文件流 f 已经被锁定，或者在单线程环境下使用。

3. 问Gemini：
   “unlocked后缀是一种常见的命名约定，用于表明该函数在调用时假定相关的共享资源已经被外部机制（通常是锁）保护”，
我编写一个main.c程序，使用了fseek，此时文件也会被加锁吗

   在多线程情况下，如果多个线程可能同时对同一个文件流进行操作（包括使用 fseek），那么在调用 fseek 之前通常需要进行加锁保护。
原因：
    1. 竞态条件 (Race Condition): 当多个线程并发地访问和修改共享资源（在这里是文件流的位置指针）时，如果没有适当的同步机制，
可能会发生竞态条件。例如，一个线程可能正在调用 fseek 移动文件指针，而另一个线程同时也在进行读写操作，这可能导致文件指针处于意想不到的位置，从而导致数据损坏或逻辑错误。
    2. 文件流内部状态: 文件流在内部维护着一些状态信息，包括当前的文件位置指针。fseek 会修改这个内部状态。
如果多个线程同时调用 fseek，它们可能会互相干扰对方的操作，导致文件流的内部状态变得不一致。
    3. 原子性: fseek 操作本身可能不是原子性的。虽然它看起来像一个简单的函数调用，但在底层可能涉及多个步骤来更新文件流的状态。
在多线程环境下，一个线程可能只完成了 fseek 的部分操作就被另一个线程抢占了，这同样会导致问题。

推荐的做法是：
1. 创建一个互斥锁:** 在你的程序中创建一个 `pthread_mutex_t` 类型的变量（如果你使用的是 POSIX 线程）。
2. 在访问文件流之前加锁:** 在任何线程试图对同一个文件流进行操作（包括 `fseek`、`fread`、`fwrite` 等）之前，
   先尝试获取这个互斥锁 (`pthread_mutex_lock`).
3. 执行文件操作:** 在成功获取锁之后，执行你的文件操作，例如调用 `fseek`。
4. 在完成文件操作后解锁:** 在完成对文件流的操作后，立即释放互斥锁 (`pthread_mutex_unlock`)，以便其他等待的线程可以访问。

代码示例 (POSIX Threads):
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t file_mutex;
FILE *fp;

void* thread_function(void* arg) {
    pthread_mutex_lock(&file_mutex); // 加锁

    fseek(fp, 10, SEEK_SET);
    // 执行其他文件读写操作

    pthread_mutex_unlock(&file_mutex); // 解锁
    return NULL;
}

int main() {
    fp = fopen("my_file.txt", "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (pthread_mutex_init(&file_mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        fclose(fp);
        return 1;
    }

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&file_mutex);
    fclose(fp);
    return 0;
}


