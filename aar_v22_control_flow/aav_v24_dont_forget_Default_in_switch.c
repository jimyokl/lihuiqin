
int main(void)
{
    if语句，2种情况（1和2）

    if(1)
        ;
    else if(2)
        ;
        else
        ;
    // 最后一个else是1和2都不成立的情况，万一程序还有error


    switch最后的default：
    
    switch (op)
    {
    case 1:
        ...
        break;                  // 一定记得加上break
    case 2:
        ...
        break;
    
    default:                   //  !!!!!  相当重要
        _exit(1);          
    }
    // default之后的是所有预知case之外的情况，属于error
    // 用_exit(1)报错结束退出，
    // 直接结束当前进程，不做任何清理工作，不刷新IO，不调用钩子函数（因为程序已经出现意外）

    // 可以用sig信号函数替代_exit(), 能够杀死当前进程的信号，
    // 最好在杀死当前进程的同时，生成core dump文件，
    // core dump文件是当前进程的内存快照，事故现场，能帮助我们debug
    // 可用GDB分析core dump文件，调试

}