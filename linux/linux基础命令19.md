# 用户组相关操作

## 1.创建用户组
* groupadd   创建（添加）用户组

![图 1](../../images/6f0a5ec9142dc621eec15f5d382b21188ba15f1e293adcc76664bdc90235cf4a.png)  


## 2.创建用户并指定用户组
* 创建用户并指定用户组效果图：
![图 2](../../images/81673d61b520a4c9b09637381c775b64b27b2976a85749e7bfac082973bd4ecf.png)  

* 使用cat /etc/passwd 查看用户Id
![图 3](../../images/bbc741f9f2ae99aea0cf2ac7b34b56fc66a48d5614263590b50cac1d309706ea.png)  

* 使用cat /etc/group 查看组
![图 4](../../images/9a9d634f5088f7d82f542cd6f12d30e41a46a0fa5c20b2ab1ab5a2ccc99afa8d.png)  


## 3.修改用户组

* 新建一个用户组abc
![图 5](../../images/3670ad6db0091a44e8adcea7094d80ef62e24b9a9a107a0baaa58373e548f8e7.png)  

* 将laoxia用户的用户组修改为abc
![图 6](../../images/3f1dab832ec6c59b4f31cc69ad62f357b93bf557fef95e3a06a5666866b1bc93.png)  




## 4.删除用户组

* 将test用户组删除
![图 7](../../images/d4678d7cf66ef6ea6f597cf7a8d2c01125a354044db60f09b7c97f36605bcf11.png)  


说明：
* 如果用户组下面有用户先删除用户再删除用户组
  

## 5.小结
* 创建用户组使用：sudo groupadd 用户组名
* 创建用户并指定用户组使用：sudo useradd -m -g 用户组 用户名
* 修改用户组并使用：sudo uesrmod -g 用户组 用户名
* 删除用户组使用:sudo groupdel 用户组名