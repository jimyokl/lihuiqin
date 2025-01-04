# lihuiqin course videos
bilibili.com/video/BV18p4y167Md

#在github网页,头像-->设置里面添加ssh key
ssh -T git@github.com
The authenticity of host 'github.com (20.205.243.166)' can't be established.
ECDSA key fingerprint is SHA256:p2QAMXNIC1TJYWeIOttrVc98/R1BUFWu3/LiyKgUfQM.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com,20.205.243.166' (ECDSA) to the list of known hosts.
Hi jimyokl! You've successfully authenticated, but GitHub does not provide shell access.

#新建repository后


#在网页账户-->设置personal access token后
  对于还没git init的client, 先init, 再把token直接添加远程仓库链接, git remote add origin
  如果已经init, 则git remote set-url origin
  #origin 为远程仓库地址的别名



#配置提交代码后的提交人的个人信息
#git config --global user.name "yan"
git config --global user.email "yannetwork@qq.com"

#

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
