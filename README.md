# lihuiqin course videos
bilibili.com/video/BV18p4y167Md

#1, 在网页新建repository
#2, 在github网页,头像-->设置里面添加ssh key
    ssh -T git@github.com
    The authenticity of host 'github.com (20.205.243.166)' can't be established.
    ECDSA key fingerprint is SHA256:p2QAMXNIC1TJYWeIOttrVc98/R1BUFWu3/LiyKgUfQM.
    Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
    Warning: Permanently added 'github.com,20.205.243.166' (ECDSA) to the list of known hosts.
    Hi jimyokl! You've successfully authenticated, but GitHub does not provide shell access.
#然后可以把repository clone到本地client
git init
    能够发现在当前目录下多了一个.git的目录，这个目录是Git来跟踪管理版本库的，千万不要手动修改这个目录里面的文件，不然改乱了，就把Git仓库给破坏了。
　  注意:Git会自动为我们创建唯一一个master分支
git clone https://github.com/jimyokl/lihuiqin.git
    Cloning into 'lihuiqin'...
    remote: Enumerating objects: 15, done.
    remote: Counting objects: 100% (15/15), done.
    remote: Compressing objects: 100% (10/10), done.
    remote: Total 15 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
    Receiving objects: 100% (15/15), 5.20 KiB | 1.04 MiB/s, done.
    Resolving deltas: 100% (4/4), done.
git add *
git commit -m " first time"
git remote add origin https://。。。@github.com/jimyokl/lihuiqin.git 报错
git remote set-url origin https://。。。@github.com/jimyokl/lihuiqin.git
git push -u origin master 报错，25年自动创建的branch名叫main了
git push -u origin main
    Enumerating objects: 4, done.
    Counting objects: 100% (4/4), done.
    Delta compression using up to 2 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 734 bytes | 45.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
    To https://github.com/jimyokl/lihuiqin.git
       a5efbbe..9a2c8bf  main -> main
    branch 'main' set up to track 'origin/main'.

#在网页账户-->设置personal access token后
  对于还没git init的client, 先init, 再把token直接添加远程仓库链接, git remote add origin, 如果不init直接add, 报错Stopping at filesystem boundary
  如果已经init, 则git remote set-url origin
  #origin 为远程仓库地址的别名



#配置提交代码后的提交人的个人信息
#git config --global user.name "yan"
git config --global user.email "yannetwork@qq.com"

#

#stackoverflow.com/questions/18031946/when-doing-a-git-push-what-does-set-upstream-do, -u
git push -u origin <local-branch>
    This automatically creates an upstream counterpart branch for any future push/pull attempts from teh current <local-branch>. The upstream remote branch derived from the branch name - <local-branch> is also configured as the default for all subsequent actions like push/pull etc.
    For example, executing the above command for <local-branch> = test, will result in creating a <remote branch> = remotes/origin/test.
    #-u是指本地分支与远程仓库中的分支之间的流通道，建立流通道就是建立本地分支与远程分支的关联

#git config
https://www.runoob.com/git/git-remote.html
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
5. ssh-keygen
进入/root/.ssh文件夹下，找到一个rsa.pub的文件，运行命令：vim rsa.pub将文件打开，复制文件中的所有内容。
6. git中输入密匙, 将step5 中复制的密匙输入Git
7. 生成Token
8.

#########
