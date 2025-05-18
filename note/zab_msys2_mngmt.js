
du -sh ucrt64/* : 查看每个子目录的大小

cd ucrt64/lib
du -sh * | sort -hr | less
列出 lib 目录下所有文件和文件夹的大小，并按降序排列, -h选项会以 KB、MB 或 GB 等更友好的单位显示大小








