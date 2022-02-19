# 获取管理员权限的相关命令

## 1.sudo命令的使用

* sudo -s 切换到root用户，获取管理员权限
* sudo   某个命令的执行需要获取管理员的权限 可以在执行命令前面加上sudo
  
1. sudo -s效果图：
![图 32](../../images/8d1485904bef138e5e8128bc03e91b0afc4b81bf3f84f5044d6d737d77332438.png)  

* 使用whoami命令查看当前用户是谁
![图 33](../../images/fb58db9f34a3fa53aa7233c1176b18af90c21b0b2cf315ebb3be1c7c896ed186.png)  

* 使用exit命令退出管理员
![图 34](../../images/07cb24ff827719477110a7556502d8f852d04e95161508eace61573da4a659bf.png)  


* 修改密码
![图 35](../../images/408ba62e31a1dd89dcbfec3c7b499746cbc07a80c56b7f287e45e403318242d6.png)  

* 查看当前系统有哪些用户在登录
![图 36](../../images/c99cff9208483e1a1db642ec6f604479c3e2d95ef05b1c37edd9ebd0f0fd43af.png)  



2. sudo 效果图
仅仅在当前命令获取管理员权限 比如使用sudo安装网络工具
![图 37](../../images/c0ab4668d786476bc0aefbf43a6958857a2069deb3454d4692d2d26abd9c5774.png)  



如果想在windows下远程登录自己的ubuntu系统，

使用ifconfig查看电脑的id地址：192.168.206.129
![图 38](../../images/e47cc67cc248c11c9ddd7cd8fc0328c69edd6b383b349a9ae65ab4ed0e9bda22.png)  


查看服务器上有没有安装SSH工具
![图 39](../../images/441e256bdad84cd4605285c7039ac708089fbb0b234ceaa543f839cee313f697.png)  

安装SSH工具
![图 40](../../images/f1ea009a367a7ed57e6bd3f138561b8488aa11a313796e9f81cf73891fc48388.png)  


打开windows终端 输入：

SSH xiaxuefei(服务器的用户名 ubuntu)@192.168.206.129（IP地址）


可以看到下面出现了绿色的用户名（这个是我的ubuntu账户）
![图 41](../../images/830a830311e4c910f068b1ed4d0b153f7e0764c22ddd48ae9c1f2fab93e18fc7.png)  



打开ubuntu 输入who 查看当前用户：可以看到有两个用户在里面 :0表示自己在登录  其他IP地址表示其他用户在登录

![图 42](../../images/e0616c23479ae23ededd30704f60041398059ddec361c7dbe17e9374f5c7387f.png)  


使用Ls查看
![图 43](../../images/69bcfce6c239404e1197a9f650068f2276280e38e9c2661836a23f255213f74c.png)  


## 3.关机和重启命令的使用
* shutdown -h now  立刻关机
* reboot           重启


## 4.小结
* sudo 是临时获取管理员权限
* sudo -s 是切换到管理员用户，一直使用管理员权限，需要谨慎操作
* exit 是退出当前用户
* password默认修改当前用户密码


