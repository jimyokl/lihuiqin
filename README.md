# lihuiqin course videos
bilibili.com/video/BV18p4y167Md

别人的笔记: github.com/impact-eintr/LinuxC/blob/main/C/README.md
其他自己的笔记在note文件夹里面
video4: 
  1. main is a thread too,多线程并发,如果事先结束这个线程,程序还能跑, 对应的源代码是d_hello.c
	 内核对于进程/线程不能区别，只知道进程
	1.1 以函数为单位,模块化: 想要实现加减乘除的一个目的
		错:把4个功能写一个函数里面
		对:分开写4个小函数,后面如果想移植复用这块小代码,就很方便
	1.2 声明+实现
	1.3 "return 0",给父进程看的.echo $?,
  2. #if 0
     #endif
     #if 0和#endif也可以拿来用作大段的注释，#后的代码在预处理阶段就已经完成了，所以到后面编译的时候，这些就是注释了
     条件编译
   3. 流程图、NS图、有限状态机(FSM) ---描述算法
   4. 进程:32位机器,一个进程占用4g虚拟空间
   5. 防止写越界,防止内存泄漏,谁打开谁关闭,谁申请谁释放
7.函数 8.构造类型 9.动态内存管理 10.调试工具和技巧gdb,make 11.常用库函数
![image](https://github.com/jimyokl/lihuiqin/blob/main/media/bg2015120901.png)
一、
1. working directory的文件可能有以下几种状态：
   未跟踪（Untracked）：新创建的文件，未被 Git 记录。
   已修改（Modified）：已被 Git 跟踪的文件发生了更改，但这些更改还没有被提交到 Git 记录中。
2. 暂存区Staging（Index） Area
   暂存区，也称为索引（Index），是一个临时存储区域，用于保存即将提交到本地仓库的更改。你可以选择性地将工作目录中的更改添加到暂存区中，这样你可以一次 
   提交多个文件的更改，而不必提交所有文件的更改。 git add <filename>或者git add .
3. 本地仓库（Local Repository）
   本地仓库是一个隐藏在 .git 目录中的数据库，用于存储项目的所有提交commit历史记录。
二、
  未跟踪(Untracked):新建文件；已跟踪(Tracked):git add将未跟踪的文件添加到暂存区,状态为tracked；已修改（Modified):更改已跟踪的文件后,这些更改会显 
  示为已修改状态，但这些更改还未添加到暂存区;已暂存（Staged):git add 命令将修改过的文件添加到暂存区后，文件进入已暂存状态，等待提交。
  ?git commit后的状态是什么？

#1, 在网页新建repository
#2, 在github网页,头像-->设置里面添加ssh key
   ssh-keygen -t ed25519 -C "jimyshow@hotmail.com"
#3 install git
#4 配置提交代码后的提交人的个人信息
  #git config --global user.name "yan"
  git config --global user.email "yannetwork@qq.com"
    ssh -T git@github.com
    The authenticity of host 'github.com (20.205.243.166)' can't be established.    ECDSA key fingerprint is SHA256:...    Are you sure you want to continue connecting (yes/no/[fingerprint])? yes      Warning: Permanently added 'github.com,20.205.243.166' (ECDSA) to the list of known hosts.    Hi jimyokl! You've successfully authenticated, but GitHub does not provide shell access.
    如果URL以`https://`开头，那么就是使用HTTP协议访问远程仓库；如果URL以`git@`开头，那么就是使用SSH协议访问远程仓库。
    
#然后可以把repository clone到本地client
git init
    在当前目录下多了一个.git的目录，这个目录是Git来跟踪管理版本库的，不要修改里面的文件,会破坏Git仓库
　  注意:Git会自动为我们创建唯一一个master分支
git clone https://github.com/jimyokl/lihuiqin.git
    Cloning into 'lihuiqin'...  remote: Enumerating objects: 15, done. remote: Counting objects: 100% (15/15), done.
    remote: Compressing objects: 100% (10/10), done.     remote: Total 15 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
    Receiving objects: 100% (15/15), 5.20 KiB | 1.04 MiB/s, done.      Resolving deltas: 100% (4/4), done.
git remote add origin https://。。。@github.com/jimyokl/lihuiqin.git 报错
#在网页账户-->设置personal access token后
git remote set-url origin https://。。。@github.com/jimyokl/lihuiqin.git //重设远端仓库地址,例如加token

git add *, git commit -m " first time", 
git push -u origin master 报错，25年自动创建的branch名叫main了
git branch 
    * main
git push -u origin main
    Enumerating objects: 4, done.     Counting objects: 100% (4/4), done.      Delta compression using up to 2 threads
    Compressing objects: 100% (3/3), done.      Writing objects: 100% (3/3), 734 bytes | 45.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)      To https://github.com/jimyokl/lihuiqin.git
       a5efbbe..9a2c8bf  main -> main          branch 'main' set up to track 'origin/main'.

  先init,然后就可以clone,然后就可以git remote set-url origin,把token直接添加远程仓库链接,
  #origin 为远程仓库地址的别名 
  //这里可能有错: "git remote add origin"是没有clone时,如果不init直接add, 报错Stopping at filesystem boundary

#查看状态，可以经常看
git status
    On branch main,  Your branch is up to date with 'origin/main'.   nothing to commit, working tree clean
    Changes not staged for commit: deleted:    bg2015120901.png  	deleted:    git-command.jpg    	deleted:    media/toDel.c
Untracked files:
  (use "git add <file>..." to include in what will be committed)	media/bg2015120901.png  	media/git-command.jpg
git add .
git status
      Changes to be committed:     (use "git restore --staged <file>..." to unstage)
  	    renamed:    bg2015120901.png -> media/bg2015120901.png
	    renamed:    git-command.jpg -> media/git-command.jpg
	    deleted:    media/toDel.c
git commit -m "mv files to media folder"
    3 files changed, 1 deletion(-)
        rename bg2015120901.png => media/bg2015120901.png (100%) ,        rename git-command.jpg => media/git-command.jpg (100%)
        delete mode 100644 media/toDel.c
#git pull 需要设置 pull.rebase=false
  cnblogs.com/wangiqngpei557/p/6056624.html, juejin.cn/post/6844903895160881166讲得不错

#stackoverflow.com/questions/18031946/when-doing-a-git-push-what-does-set-upstream-do, -u
git push -u origin <local-branch> //-u(upstream)
    This automatically creates an upstream counterpart branch for any future push/pull attempts from teh current <local-branch>. The upstream remote branch derived from the branch name - <local-branch> is also configured as the default for all subsequent actions like push/pull etc.
    For example, executing the above command for <local-branch> = test, will result in creating a <remote branch> = remotes/origin/test.
    #-u是指本地分支与远程仓库中的分支之间的流通道，建立流通道就是建立本地分支与远程分支的关联

#关联远程仓库
$ git remote -v
origin  https://github.com/tianqixin/runoob-git-test (fetch)
origin  https://github.com/tianqixin/runoob-git-test (push)
origin 为远程地址的别名。

#vscode ssh with rsa key, without passwd
#blog.songjiahao.com/archives/262
sudo chmod 600 authorized_keys
sudo chmod 700 ~/.ssh
sudo vim /etc/ssh/sshd_config
    Port 22
    RSAAuthentication yes
    PubkeyAuthentication yes
    sudo service sshd restart
#change repo    
sudo mv CentOS-*.repo backup/
sudo curl -o CentOS-Base.repo https://mirrors.aliyun.com/repo/Centos-vault-8.5.2111.repo
sudo yum makecache

sudo yum groupinstall "Development Tools"
sudo yum install curl-devel expat-devel gettext-devel openssl-devel  perl-CPAN perl-devel zlib-devel

cd /usr/src/
sudo wget https://github.com/git/git/archive/refs/tags/v2.47.1.tar.gz
sudo tar -xf git.tar.gz
cd git-*
sudo make prefix=/usr/local all
sudo make prefix=/usr/local install

############CentOS 上传代码到git
https://blog.csdn.net/yangshiyan1991/article/details/128319304
5. ssh-keygen: 进入/root/.ssh文件夹下，找到一个rsa.pub的文件，运行命令：vim rsa.pub将文件打开，复制文件中的所有内容。
6. git中输入密匙, 将step5 中复制的密匙输入Git    7. 生成Token   8.

#########
代码自动补全: fittencode
