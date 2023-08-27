# Nacos简单入门

## 快速安装


在Nacos的GitHub页面，提供有下载链接，可以下载编译好的Nacos服务端或者源代码：

下载完压缩包之后，放在任意目录下面进行解压：

GitHub主页：https://github.com/alibaba/nacos

GitHub的Release下载页：https://github.com/alibaba/nacos/releases


bin：启动脚本
conf：配置文件

![图 0](../images/695890f04c41217e1a196a8233246030a9e66907934ef469d6036b5148c51192.png)  


## 端口配置

Nacos的默认端口是8848，如果你电脑上的其它进程占用了8848端口，请先尝试关闭该进程。

**如果无法关闭占用8848端口的进程**，也可以进入nacos的conf目录，修改配置文件中的端口：

![图 1](../images/34ab2eab9a676a74d487966e47217f104b7344923c4bc4ddcb38e36b866c47d2.png)  

## 启动

进入bin目录 ，执行命令：

```
startup.cmd -m standlone

```
![图 2](../images/3c5634415826401018bd4ded60222063d45ef76148a3f3bfe9a13832cf77cc06.png)  



访问nacos

![图 3](../images/d6bd3c09a986d27bd20e201e3600dec3b3e2e456d50f18368591a769e37d4086.png)  

