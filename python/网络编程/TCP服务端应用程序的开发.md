# TCP服务端应用程序的开发



## 一、开发TCP服务端程序开发步骤回顾
* 创建服务端套接字对象
* 绑定端口号
* 设置监听
* 等待接受客户端的连接请求
* 接受数据
* 发送数据
* 关闭套接字


## 二、socket类的介绍
导入socket模块
import socket

创建服务器socket对象
socket.socket(AddressFamily,Type)


参数说明：

* AddressFamily 表示IP地址类型，分为IPv4 IPv6
* Type表示传输协议类型

方法说明：
* bind((host,port))表示绑定端口号，host是ip地址，port是端口号,ip地址一般不指定，表示本机的任何一个ip地址都可以
* listen(backlog) 表示设置监听。backlog参数表示最大等待建立连接的个数
* accept()表示等待接受客户端的连接请求
* send(data) 表示发送数据，data是二进制数据
* recv(buffersize)表示接受数据，buffersize是每一次接受数据的长度（单位：字节）




测试代码：
```python
import socket


if __name__ == '__main__':
    # 创建tcp服务端套接字   这个套接字只起到建立连接的作用  不能用于收发消息
    tcp_server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    # 绑定端口号 服务器端的ip地址与自定义端口号
    # 第一个参数表示ip地址，一般不用指定，表示本机的任何一个ip即可
    # 第二个参数表示端口号
    tcp_server_socket.bind(("",8080))

    # 设置监听  128 表示最大等待建立连接的个数
    tcp_server_socket.listen(128)

    # 等待接受客户端的连接请求  返回的是一个新的套接字 原来的套接字只是用来进行连接使用的
    # 服务端与客户端进行通信使用新的套接字  目的是为了服务多个客户端



    new_client,ip_port = tcp_server_socket.accept()
    # print(result)
    # (<socket.socket fd=352, family=AddressFamily.AF_INET, type=SocketKind.SOCK_STREAM, proto=0, laddr=('192.168.1.4', 8080), raddr=('192.168.1.7', 61864)>, ('192.168.1.7', 61864))
    # 对于打印结果  返回的是一个元组，元组只有两个数据  第一个数据是新的套接字，第二个数据是客户端的ip地址与端口号

    # 可以使用拆包的方法 将客户端的ip地址与端口号打印出来
    print("客户端的ip与端口号是：",ip_port)
    # 可以看到客户端的ip与端口号是： ('192.168.1.7', 62097)  这里的看到客户端的端口号是系统随机分配的 变化的



    # 接受客户端的数据  收到的数据是二进制数据  需要进行解码

    receive_data = new_client.recv(1024)

    receive_content = receive_data.decode("gbk")

    print("接收到客户端的数据为：",receive_content)




    # 发送数据到客户端
    send_content = "问题正在处理中"
    send_data = send_content.encode("gbk")  # 编码 二进制数据
    new_client.send(send_data)  # 发送数据


    # 关闭套接字
    # 所有的套接字都要关闭


    # 关闭客户端与服务端的套接字 终止通信
    new_client.close()

    # 关闭服务端的套接字，表示服务端以后不再接受客户端的连接请求
    tcp_server_socket.close()

```




