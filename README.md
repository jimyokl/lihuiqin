# lihuiqin
bilibili.com/video/BV18p4y167Md


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
