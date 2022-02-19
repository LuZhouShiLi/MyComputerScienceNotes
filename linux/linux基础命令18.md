# 用户相关操作

## 1.创建用户
* useradd     创建（添加）用户

useradd命令选项：
* -m   自动创建用户主目录，主目录的名字就是用户名
* -g   指定用户所属的用户组，默认不指定会自动创建一个同名的用户组


用户权限不够  使用管理员权限
![图 1](../../images/1f29fd7f857bc50f04c049d52152e49f6f79cec0af1066f0a73245d5c1a48d85.png)  

![图 2](../../images/c3281ad5a051b0966260ed69fdf6c5e9197e6283e002fce597c91ed5b1e4382c.png)  

使用cat命令查看password
![图 3](../../images/63d5fafe28863bddb482d71742879f84878f2a944c20ef073413e000da237fdc.png)  


这个用户主目录放在了home文件夹，密码显示为x  
![图 4](../../images/e44940e97813f4774e9c7688125a64889213bd2a6d1304079b05999f2369b332.png)  


home文件夹有两个文件夹 
![图 5](../../images/24ec770e49734c5bec975913c9382e07b7eef4728a184ee20df8b0cb6f1235b5.png)  


cat /etc/group 查看用户组
![图 6](../../images/41bb84f1b5d5451f0c6d21106a9aee7a6a9c6898d78171a3a04e25a421013ab8.png)  

系统创建了xiaxuefeng 用户组，也就是创建用户xiaxuefeng的同时自动创建了一个同名的用户组
![图 7](../../images/f4f0cf7ce5ae8025ad488d751d6e0f2920b51dacd026bb4e55b6a9a21dae148a.png)  

查看id  用户id是1001   用户组的id也是1001  用户组的名称为xiaxuefeng
![图 8](../../images/9cd82645fac47b6dd10d38efe7ff9cadbb15e48a29e30e03e9c11a71c85e8e2b.png)  



## 2.设置密码
给其他用户设置密码，需要使用：sudo passwd 用户名

使用管理员权限更新密码，
![图 9](../../images/159db2d43148582be1207fecac6272ccd22efabc00664cd16a01bd6b08945d44.png)  


## 3.切换用户

语法格式： su - 用户名

使用 su - xiaxuefeng 切换用户
![图 10](../../images/ab4d21835a964911055919020612a336dcb548db7347fd566451a97e7f0e4c3c.png)  




## 4.修改用户信息
* usermod   修改用户信息


usermod选项：

* -G 设置一个附加组     
* -g 修改用户组


使用 cat /etc/group  看出sudo权限组只有一个用户xiaxuefei
![图 11](../../images/18d8be26d7851ddca91c2b3984e0afcb548a98bd10173fbaf888c4ffaba6e33d.png)  


一般创建一个用户组,比如我上面创建的一个xiaxuefeng, 组名也叫xiaxuefeng,但是没有sudo权限，所以需要将xiaxuefeng用户添加到sudo附加组，才可以获得sudo权限（xiaxuefeng用户只在自己的主组）


使用命令 sudo usermod -G sudo xiaxuefeng  将xiaxuefeng用户添加到sudo组中，使用Id xiaxuefeng命令查看该用户有两个组  主组 和 附加组(sudo)
![图 12](../../images/15a21acb801afcad8ee2b6b1fcb266822e8ffb9d13eb807ef44ba34beb1ae9bb.png)  



## 5.删除附加组
* gpasswd   添加和删除附加组信息

gpasswd命令选项：

* -a 用户名  给用户添加附加组
* -d 用户名  给用户删除附加组
  
将xiaxuefeng从sudo附加组中删除：
sudo gpasswd -d xiaxuefeng sudo


## 6.删除用户
* userdel    删除用户


userdel命令选项：
* -r 用户名     删除用户主目录，必须要设置，否则用户主目录不会删除


xiaxuefeng用户被删除
 
![图 14](../../images/dde4689b563f20d0418e0d4d2bc2e2460045e3c86649a6ae1a541feccb891303.png)  


说明：删除用户，默认同名的用户组也会被删除


### 7.小结
* 创建用户命令格式：sudo useradd -m 用户名，默认创建一个同名的用户组
* 查看用户信息使用Id命令或者/etc/passwd文件
* 查看用户组信息使用/etc/group文件
* 给用户设置密码使用sudo passwd用户名
* 切换用户使用su - 用户名
* 设置附加组使用 suod usermod -G 组名 用户名
* 删除用户使用 sudo userdel -r 用户名 默认会删除同名的用户组


