# HTTP协议的初步认识

##  HTTP协议的介绍
* http协议：超文本传输协议
* http协议是基于TCP/IP协议的
* 超文本：比普通文本更加强大
* 传输协议：客户端和服务器端的通信规则（握手规则）

![图 2](../../../images/bc32928dab3b541ea4004f2dab81726a4e7e8207247f4d88e37a91b40de9bc7e.png)  

## HTTP协议的请求
1.请求的组成部分
* 请求行
* 请求头
* 请求空行
* 请求体

2.请求的方式
* GET 用户提交的内容会显示在URL
* POST 用户提交的内容不会显示在URL
* 只用post方式才有请求体
  
![图 3](../../../images/5a8f4cf662501f66baccbd97a5eb825d6c8a9a97b5bec779cb2f3f65ba0385ce.png)  

* 请求行包含了用户名以及密码 http协议的版本号
* Host代表请求的主机 端口号8080
* User-Agent代表请求的浏览器
* Accept-text/html代表支持的文本格式
* Accept-Language代表支持的语言
* Accept-Encoding代表支持的压缩格式
* Connection：代表连接的状态

可以看到请求行是没有用户名以及密码，用户名和密码存在于请求体中
![图 4](../../../images/0c82e3cedfda9596d41e27d456e8ae69f822743fdac0e34c0de6aca5ee9c39f2.png)  


将已经写好的css login img文件导入web目录下
![图 1](../../../images/f44a7395df6e0a743eda319e6350afb7cb7f1a094e154af94dba80a66c23cea2.png)  

然后最好重启一次idea（资源导入进去） 不然启动tomcat会加载不出来login.html

![图 2](../../../images/0bbb598e2120a08d0fd8cfb7fe1d4c82445b4af38c044d99487a6485611612bc.png)  


## HTTP协议的响应

1.相应的组成部分
* 响应行
* 响应头
* 响应空行
* 响应体

![图 3](../../../images/5b73b8723221fc74b8034e16315c09ee734b84a92b7dc7817c70867f00a9a651.png)  

2. 响应行有个200 OK 代表状态码 常见状态码如下：
![图 4](../../../images/cccb02dd5c3794ee776662cd2448fa162734b4edb1d96737f6f50e8fd2bcc182.png)  

3. 响应头的格式
![图 5](../../../images/472ed155025bda329a3310f90342a96711c756000efc5998aa53d46e68f199ca.png)  

4. 响应空行：普通的换行，用于区分响应头和响应体
5. 响应体：将资源文件发送给客户端浏览器进行解析

