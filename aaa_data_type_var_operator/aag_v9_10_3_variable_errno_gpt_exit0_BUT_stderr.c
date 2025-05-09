#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main() {
    if (access("nonexistent_file.txt", F_OK) == -1) 
    {
        printf("Error: %s\n", strerror(errno));  // errno 会被设置为 ENOENT
        // Error: No such file or directory
    }
    return 0;
}
//an abbreviation of Error NO ENTry (or Error NO ENTity), 
// and can actually be used for more than files/directories.

//It's abbreviated because C compilers at the dawn of time didn't support more than 8 characters in symbols.

//Q: unix.stackexchange.com/questions/594666/can-a-program-output-to-stderr-and-still-return-a-zero-exit-status
//Q 可以输出到 stderr 并返回 0 退出状态码吗？
//A: Yes, programs can output to standard error and still return a zero exit status. 
//You will find many POSIX utilities specifications which state that 
//"The standard error shall be used only for diagnostic messages."
//A clear example of a program that outputs to STDERR and returns 0 is crontab. Try

//EDITOR=nano crontab -e 2> stderr.out; echo $?

//  设置环境变量 EDITOR 为 nano，这意味着当你运行 crontab -e 时，会使用 nano 作为默认的编辑器来编辑 cron 表。
//  crontab -e：这个命令用来编辑当前用户的 cron 表，即定时任务列表
//  2> stderr.out：这是一个重定向操作，将标准错误输出 (stderr) 重定向到 stderr.out 文件中。
//  如果在执行命令过程中有错误发生，错误信息会被写入到 stderr.out 文件中，而不是显示在终端上。

//Do not modify the cron file and exit the editor. 0 will be echoed and yet there will be some message in stderr.out, 
//such as (in my case)
//no crontab for user - using an empty one
//No modification made
