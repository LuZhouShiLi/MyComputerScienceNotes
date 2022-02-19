# ip地址的介绍

## 1.ip地址的概念

IP地址就是标识网络中设备的一个地址，好比现实生活中的家庭地址。

![图 1](../../images/cf56d72f3d3200e1f4919be656900ab742eb82990b504e162e7251f600df4fb1.png)  



## 2.ip地址的表现形式
![图 2](../../images/4014e95e2d1915bbeff4e101644a21a41bb755286b5e19e70274fa661312a536.png)  

通常分为ipv4 ipv6

说明：
 * ip地址分为两类： ipv4 和 ipv6
 * ipv4是目前使用的ip地址
 * ipv6是未来使用的ip地址
 * ipv4是由点分十进制组成
 * ipv6是由冒号十六进制组成

## 3.查看ip地址

* Linux和Mac os 使用ifconfig这个命令
* windows使用ipconfig这个命令

说明：
 ifconfig 和 ipconfig 都是查看网卡信息的，网卡信息中包括这个设备对应的ip地址

![图 3](../../images/7b41181f3d88fbf6df83b84660f42ca555568b21b04adfea6129b8e56245a01e.png)  

说明：

* 192.168.1.107 是设备在网络中的ip地址
* 127.0.0.1 是本机地址，提示：如果和自己的电脑通信就可以使用该地址
* 127.0.0.1 该地址对应的域名是localhost,**域名是ip地址的别名**，通过域名就可以解析出一个对应的ip地址。


## 4.检查网络是否正常

* 检查网络是否可以正常使用ping命令

![图 4](../../images/e88ab0d8f6bbc974af1fef1c3cbfb3b29e7b678a0ef5ce02d01d3aec2b46679f.png)  

说明：

* ping www.baidu.com
* ping 当前局域网的ip地址，检查是否在同一个局域网内
* ping 127.0.0.1 检查本地网卡是否正常
 

## 5.ip地址的作用
ip地址的作用是表示网络中唯一的一台设备的，也就是说通过ip地址能够找到网络中某台设备

![图 5](../../images/6502c5c091c62627e80b7a3a7330515629d6ec8b3d95cc6a6d7d2020de5af8a0.png)  


## 6.小结
* ip地址的作用是标识网络中唯一的一台设备的
* ip地址的表现形式分为：ipv4和ipv6
* 查看网卡信息：ifconfig
* 检查网络：ping


