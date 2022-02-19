# 远程登陆、远程拷贝命令

## 1.远程登录、远程拷贝命令的介绍
* SSH 远程登陆
* SCP 远程拷贝

## 2.SSH命令的使用
SSH是专门为远程登陆提供的一个安全性协议，常用于远程登陆，想要使用SSH服务，需要安装相应的服务端和客户端软件，当软件安装成功之后就可以使用SSH命令，以后可以通过远程登陆之间的操作远程的服务器

![图 1](../../images/f364697c2cc028f062356a21bb7926595cc2d9bd4e3c002ac5459f8a43b3133f.png)  



软件安装步骤：

1. 假如Ubuntu作为服务端，需要安装SSH服务端软件，执行命令：sudo apt-get install openssh-server
2. 客户端电脑如果是macos系统则不需要安装SSH客户端软件，默认已经安装过，直接可以使用ssh命令
3. 客户端电脑如果是windows系统则需要安装OpenSSH for Windows这个软件

SSH命令格式：ssh 用户名@ip地址


输入 apt list | grep openssh-server 查看服务端软件是否安装

![图 1](../../images/329bad19132dd4ef61bbdfc547d8640ecc769f5cf142faa40aa24d059c722df9.png)  


安装OpenSSH for windows

这里客户端与服务端都装上
![图 2](../../images/a613f95d558a5205f963806c913e47648938064b1edd24be82d957201b54ec94.png)  

一路next

选择域用户
![图 3](../../images/9056a54622f895e0f3cc7fc5eecfa6f621d10cfc0c91234472bbde7ffec9ff95.png)  


输入ssh -V   查看客户端版本
![图 4](../../images/823e6962c55ed4d7f0ae7d9d5798bc0a1559241b20588eccc8a49ededd97a542.png)  


输入 ssh (服务器名称)@(服务器IP地址)
![图 5](../../images/5d42e2af86dc34535a393077ac89696486ddb58ded04bc56b92b56d2fa7d60b4.png)  


在服务器上使用who命令 查看当前有几个用户登录服务器
![图 6](../../images/2eda4ca913b627635f63d8a07fb07bb204decbd1927abe42860df48471c37b7e.png)  

使用ctrl + d 退出服务器




windows作为服务器  ubuntu作为客户端

使用apt list | grep openssh-client 查看虚拟机是否安装了客户端软件
![图 7](../../images/33e1bd1537a7aed24f20483765e9a532ede7fb0fb0b66f106061b09bb2a1f64e.png)  


在windows命令行输入 ipconfig 查看ip地址
![图 8](../../images/89e9671a63529858c5773fda9009efe54183a8cd048e4f381fcfacdad3e0b008.png)  


同样的 在客户端输入ssh （服务器）@服务器ip地址
![图 9](../../images/c9c30d8e8fbf005a14faa3e7c88cd48a074f4645ee0a76beeaa6c7b9db97a105.png)  


