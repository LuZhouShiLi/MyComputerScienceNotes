# 响应对象response

## 概述

![图 1](../images/6ab0553e674adaf552bb4f170d7a428a36a6d61e1c3901b958365a78f93fbf1f.png)  

## 状态码

![图 2](../images/6625920292e427031d790f77f7d95be132798f6a6f49d59970fd0eb928efcb9c.png)  

## 字节流响应消息

![图 4](../images/f45bf2e5121f1b1639dc1bfe848e8d2ed5c4e7e817f8acde074fd8d5b8b940f1.png)  


```java
package com.hfut.servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet
public class Servlet2 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        resp.setContentType("text/html;charset=UTF-8");// 通过响应对象 设置编码格式

        // 获取字节输出流对象
        ServletOutputStream os = resp.getOutputStream();// 使用响应对象获取输出流

        // 定义一个消息
        String str = "你好";

        // 通过字节流输出对象  先将字符串转换为字节数组
        os.write(str.getBytes("UTF-8"));// 指定编码格式  浏览器一般都是gbk格式
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

## 字符流响应消息

![图 5](../images/3139b4ab9f5257242e65399e88bf44005dd9add8bf4c6968bdbe1e481d3b6e9d.png)  

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html;charset=UTF-8");// 通过响应对象 设置编码格式

        // 获取字符输出流对象
        PrintWriter writer = resp.getWriter();
        // 准备一个消息
        String str = "你好";
        // 通过字符流输出
        writer.write(str);

    }

```

## 响应图片-字节流

* 创建字节输出流对象，关联读取的图片路径
* 通过响应对象获取字节输出流对象
* 循环读取和写出图片

```java
protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 通过context对象获取图片的绝对路径  通过相对路径获取绝对路径
        String realPath = getServletContext().getRealPath("/img/vue.png");
        System.out.println(realPath);

        // 创建字节输入流对象  关联图片路径  这里填写的是绝对路径 不是相对路径
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream(realPath));

        // 通过响应对象获取字节输出流对象
        ServletOutputStream os = resp.getOutputStream();// 通过响应对象获取字节输出流对象

        // 循环读写
        byte[] arr = new byte[1024];
        int len;

        // 通过字节输入流读取字节到arr数组  然后通过字节输出流将字节数组写出去
        while((len = bis.read(arr)) != -1){
            os.write(arr,0,len);
        }

    }

```

## 设置缓存时间

* 缓存：对于不经常变化的数据，我们可以设置合理缓存时间，以避免浏览器频繁请求服务器。提高效率

![图 6](../images/a1e3dc021cb45636942d8969b86d64bd4666547f1d5704f883bd59737b5a214c.png)  

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 通过context对象获取图片的绝对路径  通过相对路径获取绝对路径
        String news = "这是一条很火爆的新闻！";

        // 设置缓存时间  一个小时 之后的访问直接从缓存中进行访问
        resp.setDateHeader("Expires",System.currentTimeMillis() + 1 * 60 * 60 * 1000);

        // 设置编码格式
        resp.setContentType("text/html;charset=UTF-8");

        // 写出数据
        // 获取字符写出对象
        PrintWriter writer = resp.getWriter();
        writer.write(news);


    }

```

## 定时刷新技术

* 定时刷新：过了指定时间之后，页面自动进行跳转

![图 7](../images/0019ba404be12000c34ae0708c9c65bdb63d81454889b6fcd26f75467edff8f3.png)  

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String news = "您输入的用户名或者密码有误，3秒之后自动跳转到登录页面";

        // 设置编码格式
        resp.setContentType("text/html;charset=UTF-8");

        // 写出数据
        PrintWriter writer = resp.getWriter();
        writer.write(news);

        // 设置定时刷新  三秒之后自动进行跳转  前面需要添加虚拟目录
        resp.setHeader("Refresh","3;URL=/test/register.html");
    }

```


## 请求重定向

![图 8](../images/cfb732ded2b8857db6c0c777bee7ad4a85ab5d270c0b4444b11217754d64079d.png)  

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("servlet2执行");

        // 设置请求域共享数据
        req.setAttribute("uesrname","zhangsan");

        // 设置重定向  虚拟路径 + 资源路径  url地址栏会进行跳转
        resp.sendRedirect(req.getContextPath() + "/servlet1");
    }

```

## 文件下载

![图 9](../images/64b03aad5d4613987f72373fba44d72739a07621fdbb69750cd062eeff66fc58.png)  

```java
protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 创建字节输入流对象 关联读取的文件  通过相对路径获取绝对路径
        String realPath = getServletContext().getRealPath("/img/vue.png");
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream(realPath));// 获取字节输入流

        // 设置响应头支持的类型
        // content-type 消息头名称 支持的类型
        // application/octet-stream  消息头参数 应用的类型为字节流
        resp.setHeader("Content-Type","application/octet-stream");

        // 设置响应头以下载方式打开附件
        resp.setHeader("Content-Dispostion","attachment;filename=vue.png");

        // 获取字节输出流对象
        ServletOutputStream outputStream = resp.getOutputStream();

        // 循环读写
        byte[] arr = new byte[1024];
        int len;

        while((len = bis.read(arr)) != -1){
            outputStream.write(arr,0,len);
        }
        // 释放资源
        bis.close();
    }

```




