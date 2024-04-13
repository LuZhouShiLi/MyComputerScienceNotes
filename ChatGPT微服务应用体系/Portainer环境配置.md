# Portainer环境配置

## 概述

* Portainer 是一种用于管理 Docker 和 Kubernetes 容器的开源工具。通过其用户友好的 Web 界面，用户可以轻松管理容器、镜像、网络和卷等资源


## 拉去最新的Portainer


* docker pull portainer/portainer


![图 0](../images/c2af9cea79b11a6fae8583f9f2f7b8e4a5646b599088b3f0e3edc46d111d4dd4.png)  


## 安装和启动

* docker run -d --restart=always --name portainer -p 8001:9000 -v /var/run/docker.sock:/var/run/docker.sock portainer/portainer

* 运行Portainer提供的镜像，也就是创建和启动容器
* 查看容器是否启动成功 docker ps
* http://192.168.1.4:8001/  192.168.1.4 是服务器的IP地址,8001 是客户端映射到服务器9000端口的端口


## 访问portainer

* 地址：http://180.76.175.***:9000/
* 操作：登录后设置你的用户名和密码，并设置本地Docker即可，设置完成后，如下:  
* 一定先创建admin账号啊
![图 1](../images/d5d9a6dd03a9cd5a5c977f80e5b33e40c9be33ca2ce241ae64a49378a6a7c467.png)  


![图 2](../images/c09552f16e17467d77be5de000755f945e64ce97be1182874bcda3f9a94177aa.png)  

## 查看本地的docker环境

![图 3](../images/7282c4f1ed7311a01fec0414288bb2d1b54a018c738ef51a9e9a7b1554997e5c.png)  

### 展示容器信息

![图 4](../images/99cff0763298e42da7d47a6c8cc3bc80f7b4a1ced0489556187deffb852a9898.png)  


### 展示镜像信息

![图 5](../images/09b488836909c74e4fd7d2ccf54ef40a83f4e5fb2821a5adbf86f7fb132f1dfd.png)  



