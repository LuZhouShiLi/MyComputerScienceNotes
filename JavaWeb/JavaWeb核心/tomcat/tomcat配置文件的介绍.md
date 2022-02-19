# Tomcat虚拟目录与配置文件介绍

## 1.主配置文件 server.xml

conf文件夹中包含server.xml配置文件
![图 21](../../../images/e6ebe2da082994c6e43c2e7dbfc59f098e600158bfcb84fcbfcdf95822a80663.png)  

* 8080 端口：tomcat服务默认端口号。访问url地址后必须手动写：8080
* 80端口：http协议采用的端口号。访问url地址后不用写：80


## 2.虚拟目录
虚拟目录的作用：可以发布任意目录下的项目

* 编辑server.xml配置文件，找到<host>标签
* 加入以下内容
  ![图 22](../../../images/7583f4a046d2196c6b7347bb5e07de8ac655077fea5dca1471fafc82e3eba499.png)  

path属性：访问资源的虚拟目录名称
docbase属性：项目真实存在的路径

再次启动tomcat 
![图 23](../../../images/5fed55c33829cebc8772570d264a714eb8bd41ee72f18a5145b4acd94655c2ed.png)  


## tomcat配置虚拟主机
虚拟主机的作用：可以指定访问路径

1、编辑server.xml配置文件，找到<Endine>标签
2、加入以下内容
![图 24](../../../images/47485b46d15f90ee2c35ec37643e46425f822f98cfc7882acbe4745e785ace83.png)  

name：表示访问虚拟主机的名称
appBase:项目存放的路径
unpackWARS:是否自动解压war包
autoDeploy:是否自动发布

3.修改hosts文件
加入 127.0.0.1 www.webdemo.com

![图 25](../../../images/ef32426aa9605fb3bf7aca5645250255964e7dcf9601578ef472b3b0db8fe119.png)  


host文件位置
![图 26](../../../images/c6ed5e87479e424821ef041f6d235b380d7a2747cd5b77259a7768fec628c57c.png)  

关于如何修改hosts文件，这里需要权限：
可以鼠标右键windows，选择powershell(管理员)
![图 2](../../../images/8b6a422983d3760c334462248c143b8de4a2073df009d925cc1dfcc5aed497b3.png)  

然后输入notepad 这时会弹出一个窗口，txt文件，选择打开，打开上述hosts文件，在尾部添加127.0.0.1(这个ip地址代表本机ip)
www.webdemo.com

![图 1](../../../images/c47616eeab234b1290ed40482aa68ccd483f95376fbef061dbc8f4ea942fe6ea.png)  


4.浏览器中输入www.webdemo.com:8080
![图 1](../../../images/f114c854e4aa75879dbdd90dab6be379954c24e20631e3e4305a2a8a10c89a54.png)  




