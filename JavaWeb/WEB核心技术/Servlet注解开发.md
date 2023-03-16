# Servlet注解开发

## Servlet3.0 的规范

![图 1](../images/0e799577305181e5fa8280b7606a3a724614bd00d1cf9baecc578ccee4cbdf4f.png)  

## 自动注解开发的实现步骤-基于注解开发Servlet

* 创建一个web项目
* 定义一个类，继承HttpServlet
* 重写doGet和doPost方法
* 在类上使用@WebServlet注解配置Servlet
* 部署并启动项目
* 通过浏览器进行测试

**基于注解进行开发 不需要写web.xml文件**


```java
package com.hfut.servlet;

import java.io.IOException;
import java.net.http.HttpClient;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

// 基于注解开发Servlet

// WebServlet 相当于配置url 访问资源的路径  不需要写web.xml文件
@WebServlet("/servletDemo1")
public class servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doGet(req, resp);
        System.out.println("自动注解开发");
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}

```

## 自动注解开发的详解

![图 2](../images/4eac5f55b85b1fedda7abdcd4fd005aa9626c843a6d349cbf48b698781391e9a.png)  


