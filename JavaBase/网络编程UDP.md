# 网络编程UDP和TCP

## 网络编程的三要素

![图 1](../images/17acc979e23b06e46eb2658d5bc5644df87d834e62ff8e77ff47dbc2a1410d54.png)  

## 网络编程的常见命令

* ipconfig 查看本机IP地址
* ping IP地址： 检查网络是否联通
* 127.0.0.1是回送地址，可以代表本机地址，一般用来测试使用

## InetAddress类

InetAddress类是JAVA方便对ip地址的使用


![图 2](../images/61665f724ace4a927c7599825d3c1c1deb141fa764d2bf99a348744188e55244.png)  


```java
package com.hfut.edu.test14;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class test3 {
    public static void main(String[] args) throws UnknownHostException {
        InetAddress address = InetAddress.getByName("DESKTOP-49VK0HU");// 获取改主机 通过主机名称

        // 获取此IPD地址的主机名
        String name = address.getHostName();

        // 获取IP地址的字符串
        String ip = address.getHostAddress();

        System.out.println("主机名" + name);
        System.out.println("IP地址" + ip);
    }
}
```

## 端口

![图 3](../images/4613c67b22c32314b01508da5d90b309143751e0239428e72d693b61097075ac.png)  


## 协议

![图 4](../images/5cbf83a6dac9567c6603e2ac3fc44deb2bbb2ed2241e227e3d7cbedddf9d7541.png)  

## UDP发送数据

![图 5](../images/3b0be34536bd784475d69eddc3be8faec3e25afeb048169d049f870abcb23560.png)  

```java
package com.hfut.edu.test14;

import java.io.IOException;
import java.net.*;

public class SendDemo {
    public static void main(String[] args) throws IOException {
        // 创建发送端的Socket对象
        // 创建数据 将数据打包
        // 调用DatagramSocket对象的方法发送数据
        // 关闭发送端
        DatagramSocket ds = new DatagramSocket();// 创建发送端对象

        //创建数据 将数据打包
        byte[] bys = "hello world".getBytes();
        int length = bys.length;// 计算字符串的长度
        InetAddress address = InetAddress.getByName("DESKTOP-49VK0HU");// 根据主机名获取

        // 设置端口
        int port = 10086;
        DatagramPacket dp = new DatagramPacket(bys,length,address,port);

        // 调用DatagramSocket对象的方法发送数据
        ds.send(dp);

        // 关闭发送端
        ds.close();// 关闭数据包套接字
    }
}


```

## UDP接受数据

![图 6](../images/1d1090320eb9783bfbb6a0752abd3409b3984e9563999b3079da0b8ba5c7874d.png)  


```java
package com.hfut.edu.test14;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class receiveDemo {
    public static void main(String[] args) throws IOException {
        // 创建接收端对象Socket  绑定本机的指定端口
        DatagramSocket ds = new DatagramSocket(10086);

        // 创建数据包用于接受数据
        byte[] bys = new byte[1024];
        DatagramPacket dp = new DatagramPacket(bys,bys.length);

        // 调用ds对象接受数据
        ds.receive(dp);

        // 接收数据
        byte[] datas = dp.getData();

        // 限制接受的字符串长度
        String s = new String(datas,0,dp.getLength());// 将字节数组作为参数  构造字符串

        System.out.println(s);

        ds.close();

    }
}

```

## UDP通信程序的练习

![图 7](../images/b49b968d51ef520e50fe533813783eb5688221d3e83b684471972654db85ec2c.png)  


发送端：
```java
package com.hfut.edu.test15;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class Send {
    public static void main(String[] args) throws IOException {
        // 创建发送端Socket对象
        DatagramSocket ds = new DatagramSocket();
        // 将键盘录入的数据封装成缓冲流数据
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = br.readLine()) != null){
            // 输入数据时886 结束循环
            if(line.equals("886")){
                break;
            }
            byte[] bys = line.getBytes();//将输入的字符串转换成字节数组
            // 封装数据
            DatagramPacket dp = new DatagramPacket(bys,bys.length, InetAddress.getByName("DESKTOP-49VK0HU"),1234);
            ds.send(dp);
        }
        ds.close();// 关闭发送端
    }
}


```

接收端：

```java
package com.hfut.edu.test15;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class Receive {
    public static void main(String[] args) throws IOException {
        // 创建接收端的Socket对象
        DatagramSocket ds = new DatagramSocket(1234);

        while(true){
            // 创建数据包
            byte[] bys = new byte[1024];
            DatagramPacket dp= new DatagramPacket(bys,bys.length);// 接收数据包

            ds.receive(dp);// 接受数据

            // 解析数据包
            System.out.println("数据：" + new String(dp.getData(),0,dp.getLength()));
        }
//        ds.close();// 关闭接收端

    }
}


```

## TCP通信程序-发送数据

![图 8](../images/b614840477271a924da6a8d590ce4eafd707f4b4e3d20fa7f6fbb1f360a7f1a2.png)  


![图 9](../images/5fea9e822f995a05cc3d68a9da39c0c094f92d39f15afa9de9f31ac18a5d61aa.png)  


```java
package com.hfut.edu.test16;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.charset.StandardCharsets;

public class ClientDemo {
    public static void main(String[] args) throws IOException {
        // TCP 发送端数据

        // 创建客户端的套接字
        Socket s = new Socket(InetAddress.getByName("DESKTOP-49VK0HU"),10000);

        // 获取输出流  写数据
        OutputStream os = s.getOutputStream();
        os.write("hello world".getBytes());// 将字符串转换为字节数组  写入输出流

        // 释放资源
        s.close();
    }
}


```

## TCP通信程序-接受数据

![图 10](../images/7cb3550722ccaea9390c4c1705ca159cd68ad8739be1f3cf89729e9f6518798c.png)  

```java
package com.hfut.edu.test16;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerDemo {
    public static void main(String[] args) throws IOException {
        // 创建服务器的Socket对象
        ServerSocket ss = new ServerSocket(10000); 

        Socket s = ss.accept();// 侦听要连接到此套接字并且接受他

        // 获取输入流 读取数据 并把数据显示在控制台
        InputStream is = s.getInputStream();
        byte[] bys = new byte[1024];
        int len = is.read(bys);// 将输入流中的数据读入字节数组
        String data = new String(bys,0,len);
        System.out.println("数据：" + data);

        // 释放资源
        s.close();
        ss.close();

    }
}
```



