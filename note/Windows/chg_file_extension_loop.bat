for /d %%i in (*) do (
    pushd %%i
    for /f %%j in ('dir /b *') do (
        ren "%%j" "%%j.gif"
    )
    popd
)

:: 逐项解释：
:: for /d %%i in (*):

:: for /d 用于遍历目录（子目录）。%%i 代表当前子目录的名字。

:: (*) 匹配当前目录下的所有子目录。

:: pushd %%i:

:: pushd 用于切换到当前子目录 %%i。

:: for /f %%j in ('dir /b *'):

:: 在进入到子目录后，使用 dir /b * 列出该子目录下的所有文件和文件夹。

:: %%j 是子目录下每个文件的名字。

:: ren "%%j" "%%j.gif":

:: 对子目录下的每个文件，执行重命名，将其扩展名改为 .gif。

:: popd:

:: popd 返回到上一级目录，继续处理下一个子目录。


if false==true 
(
    echo 这也是一种多行注释方式
    echo 这里的代码不会执行
)