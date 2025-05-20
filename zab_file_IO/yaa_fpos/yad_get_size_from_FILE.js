
$$$$$$$$$$$$################~~~~~~~~~~~一:从fp FILE结构体得到文件大小~~~~~~~~~~~******************$$$$$$$$$$$$
    fp = fopen("xaa_ten_byte.txt", "r")后，能从fp FILE结构体里面得到文件大小吗
    内核中的eof值是文件大小，可以在程序中使用这个eof变量吗

    用户写的C程序,不能直接访问内核中的 `eof`（end of file）变量**，即便它在内核中代表文件大小。

1. 用户态和内核态隔离（User Space vs Kernel Space）**

    现代操作系统（如 Linux）采用严格的内核态与用户态隔离机制：
        内核态**：操作系统运行的特权模式，可以访问硬件资源、内核结构体，如 inode 中的 `i_size`（文件大小）。
        用户态**：用户程序运行的模式，没有权限直接访问内核内部结构或变量。
    fopen()打开的 `FILE*` 结构体，是标准库（libc）在用户空间的一个抽象，
    里面并没有直接包含内核中 `inode` 或文件描述符信息的全部内容。
    不能直接读取或使用内核中的 `inode->i_size`,没有 `eof` 这样的全局变量可以被访问

2. 方式一：使用 `fseek()` + `ftell()` 获取大小
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

   方式二：使用 `stat()` 系统调用（推荐方式）,这是直接通过文件元数据获取文件大小，不需要打开文件内容：
    #include <stdio.h>
    #include <sys/stat.h>

    long get_file_size(const char *filename) {
        struct stat st;
        if (stat(filename, &st) == 0) {
            return st.st_size;  // 文件大小
        } else {
            perror("stat failed");
            return -1;
        }
    }
    这是通过系统调用进入内核，从 `inode` 读取文件大小，但你依然不能直接访问 `inode` 或内核变量，而是通过受控接口访问。

    三、fstat()(通过文件描述符):

$$$$$$$$$###########~~~~~~~~~~~~二:获取文件大小的7种方法~~~~~~~~~~~****************$$$$$$$$$$$$$

总结一下获取文件大小的 7 种方法：

### 1. **fseek() + ftell()**

* **原理**：通过将文件指针移动到文件末尾，再调用 `ftell()` 获取当前文件指针位置，即为文件的大小。
* **适用场景**：标准文件操作，适合普通的文件读取。
* **示例**：

  ```c
  FILE *file = fopen("file.txt", "r");
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fclose(file);
  ```

### 2. **stat()**

* **原理**：`stat()` 系统调用可以获取文件的元数据，包括文件大小。返回的 `struct stat` 中的 `st_size` 字段即为文件大小。
* **适用场景**：文件的元数据查询。
* **示例**：

  ```c
  struct stat st;
  stat("file.txt", &st);
  off_t size = st.st_size;
  ```

### 3. **fstat()**

* **原理**：与 `stat()` 类似，但 `fstat()` 是针对文件描述符的操作，适用于已打开的文件。
* **适用场景**：当文件已经通过 `open()` 打开时，使用 `fstat()`。
* **示例**：

  ```c
  int fd = open("file.txt", O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  off_t size = st.st_size;
  close(fd);
  ```

### 4. **open() + lseek()**

* **原理**：通过 `open()` 打开文件后，使用 `lseek()` 将文件指针移动到文件末尾，然后返回文件的当前位置，间接得到文件大小。
* **适用场景**：底层文件操作，适用于需要处理文件描述符的场景。
* **示例**：

  ```c
  int fd = open("file.txt", O_RDONLY);
  off_t size = lseek(fd, 0, SEEK_END);
  close(fd);
  ```

### 5. **mmap()**

* **原理**：通过 `mmap()` 映射文件到内存，映射成功后，可以直接通过映射区域的大小得知文件大小。
* **适用场景**：文件较大时，适合内存映射，尤其在需要读取大文件时。
* **示例**：

  ```c
  int fd = open("file.txt", O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  size_t size = st.st_size;
  void* map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (map == MAP_FAILED) {
      // 处理错误
  }
  close(fd);
  munmap(map, size);
  ```

### 6. **ioctl()** (针对设备文件或特定文件系统)

* **原理**：通过 `ioctl()` 进行设备控制和查询，某些情况下可以用来获取设备文件的大小（仅适用于特定设备或文件系统）。
* **适用场景**：硬件设备文件，特定文件系统。
* **示例**：不常用，且需要特定平台支持。

### 7. **Windows 特有的 GetFileSize()**

* **原理**：Windows API 提供了 `GetFileSize()` 函数来获取文件大小，适用于 Windows 平台。
* **适用场景**：Windows 系统上获取文件大小。
* **示例**：

  ```c
  HANDLE hFile = CreateFile("file.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
  DWORD size = GetFileSize(hFile, NULL);
  CloseHandle(hFile);
  ```

这 7 种方法覆盖了大部分常见场景，选择时根据你所使用的操作系统和编程需求来决定最合适的方法。
