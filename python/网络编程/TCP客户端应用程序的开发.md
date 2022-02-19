# TCP客户端应用程序的开发


## 一、开发TCP客户端程序开发步骤回顾
* 创建客户端套接字对象
* 和服务端套接字建立连接
* 发送数据
* 接受数据
* 关闭客户端套接字

## 二、socket类的介绍
导入socket模块
import socket

创建客户端socket对象
```python
socket.socket(AddressFamily,Type)
```


参数说明：

* AddressFamily 表示IP地址类型，分为IPv4 和 IPv6
* Type表示传输协议类型

方法说明：
* connect((host,port)) 表示和服务器套接字建立连接，host是服务器ip地址，port是应用程序的端口号
* send(data) 表示发送数据，data是二进制数据
* recv(buffersize)表示接受数据，buffersize是每次接受数据的长度


```python
import socket

# 1. 创建tcp客户端套接字
# 这里使用 AF_INET:ipv4类型的ip地址  SOCK_STREAM:TCP 传输协议
tcp_client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

# 2. 和服务端套接字建立连接
tcp_client_socket.connect(("192.168.1.7",8080))

# 3. 发送数据到服务端
send_content = "Hello World"

# windows网络调试助手使用的是gbk编码
# linux 里面的网络你调试助手使用的是utf-8编码

send_data = send_content.encode("utf-8")


tcp_client_socket.send(send_data)

# 4. 接收服务端的数据

# 1024表示每次接受的最大字节数
rece_data = tcp_client_socket.recv(1024)
print(rece_data)

# 5. 关闭套接字
tcp_client_socket.close()



```




