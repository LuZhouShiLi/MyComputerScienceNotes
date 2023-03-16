# ServletConfig


## 概述

* ServletConfig是Servlet的配置参数对象，在Servlet的规范中，允许为每一个Servlet都提供一些初始化的配置，所以，每个Servlet都有一个自己的ServletConfig。
* 作用：在Servlet的初始化时，将一些配置信息传递给Servlet
* 生命周期:和Servlet相同

![图 1](../images/eb031512f83eee975d263a485f07f08af279dd11ec5998ad11ec5f9e57e86d01.png)  

## 配置方式

![图 2](../images/d61e46d30496d93a25e34adcf7df7f516d717724dcacd81e985c3183e3e3feeb.png)  

**键值对的方式，一个init标签只允许一个键值对的方式存在,多个参数多个init标签**

```java
    <servlet>
        <servlet-name>servlet5</servlet-name>
<!--        具体的资源路径  通过servlet5的名字找到-->
        <servlet-class>com.hfut.serv.ServletDemo1.Servlet5</servlet-class>

        <init-param>
            <param-name>encoding</param-name>
            <param-value>UTF-8</param-value>
        </init-param>

        <init-param>
            <param-name>desc</param-name>
            <param-value>This is Sc</param-value>
        </init-param>

    </servlet>

```

## ServletConfig的常用方法

![图 3](../images/1dfc7f828673630bdd45d0a107182154933a089d31334c91503ec752d9995ef0.png)  

```java
package com.hfut.serv.ServletDemo1;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Enumeration;

public class Servlet5 extends HttpServlet {

    private ServletConfig config;// 声明一个ServletConfig对象

    @Override
    public void init(ServletConfig config) throws ServletException {
//        System.out.println("该servlet资源被创建了!!!");
        this.config = config;// 初始化
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 根据指定的key获取value
        String encodingValue = config.getInitParameter("encoding");
        System.out.println(encodingValue);

        // 获取所有的key  枚举值
        Enumeration<String> keys = config.getInitParameterNames();

        while(keys.hasMoreElements()){
            // 获取每一个key
            String key = keys.nextElement();

            // 根据key获取value
            String value = config.getInitParameter(key);

            System.out.println(key + "," + value);
        }

        // 获取Servlet的名称
        String servletName = config.getServletName();
        System.out.println(servletName);

        // 获取ServletContext对象
        ServletContext servletContext = config.getServletContext();
        System.out.println(servletContext);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);


    }
}


```


