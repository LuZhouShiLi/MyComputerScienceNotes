# 多任务版TCP服务端程序开发

## 一、需求
目前我们开发的TCP服务端程序只能服务于一个客户端，如何开发一个多任务版的TCP服务端程序能够服务于多个客户端

完成多任务，可以使用线程，比进程更加节省内存资源

## 二、具体实现步骤

* 编写一个TCP服务端程序，循环等待接受客户端的连接请求
* 当客户端和服务端建立连接成功，创建子线程，使用子线程专门处理客户端的请求，防止主线程阻塞
* 把创建的子线程设置成为守护主线程，防止主线程无法退出
  
## 三、多任务版TCP服务端程序的示例代码

需要安装网络调试助手

```python
import socket
import threading

# 处理客户端请求的任务
def handle(ip_port,new_client):
    print("客户端的ip与端口号是：", ip_port)

    # new_client是新的套接字
    # ip_port 是客户端的ip地址与端口号  形式：元组

    # 为了循环接受消息
    while(True):


        # 接受客户端的数据
        recv_data = new_client.recv(1024)

        if recv_data == 1:
            # 对客户端发过来的数据 进行解码  window下使用gbk格式
            recv_content = recv_data.decode("gbk")
            print("客户端发过来的数据是：", recv_content)

            send_content = "交易正在处理"
            send_data = send_content.encode("gbk")  # 服务端将需要发送的数据进行加密
            new_client.send(send_data)
        else:
            # 客户端关闭连接
            print("客户端下线了：",ip_port)
            break



    # 关闭服务端与客户端套接字，表示和客户端终止通信
    new_client.close()


if __name__ == '__main__':

    # 设置服务器端套接字 ipv4地址，TCP协议
    # 该套接字只用于等待接受客户端的连接请求
    tcp_server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    # 开始绑定端口号  第一个参数是ip地址，不用设置，第二个参数是端口号
    tcp_server_socket.bind(("",8080))

    # 设置监听  参数是最大监听客户端数目
    tcp_server_socket.listen(128)


    # 循环等待客户端的连接请求
    while(True):
        # 等待客户端的连接请求，每一次客户端与服务端建立连接成功都会返回一个新的套接字
        # accept返回的是一个元组，第一个参数是新的套接字，第二个参数是客户端的ip地址与端口号
        # 拆包
        new_client,ip_port = tcp_server_socket.accept()   # 返回的新的套接字用于收发消息

        # 代码到了这里 说明连接成功
        # 使用多线程，这里只有当服务端接收到客户端的连接请求时  再建立一个线程  让子线程专门负责接受客户端的消息
        # 创建一个线程，参数是一个函数/方法  所以即将下面客户端与服务端的交互进行封装

        # 需要传入两个参数
        sub_thread = threading.Thread(target = handle,args = (ip_port,new_client))

        # 设置线程守护  主线程退出  子线程直接销毁
        sub_thread.setDaemon(True)

        sub_thread.start() # 启动线程







    # 关闭服务端套接字，表示服务端以后不再等待客户端的连接请求
    tcp_server_socket.close()

# 未使用：多线程的编程结果
# 实验结果：第一个客户端刚刚发送完数据，服务端不仅受到了第一个客户端发送过来的数据，而且还收到了第二个客户端发送过来的ip地址与端口号
# 也就是说 第一个客户端与服务端的套接字关闭之后，服务端就立马就收到了另外一个连接请求
# 客户端的ip与端口号是： ('192.168.1.7', 64255)
# 客户端发过来的数据是： Hello Neo
# 客户端的ip与端口号是： ('192.168.1.7', 64259)

# 使用多线程的编程结果
# 客户端的ip与端口号是： ('192.168.1.7', 64570)
# 客户端的ip与端口号是： ('192.168.1.7', 64571)
# 可以看到两个客户端几乎同时返回了他们的 ip 与端口号
# 也就是说他们不需要进行 “排队等候”




```



