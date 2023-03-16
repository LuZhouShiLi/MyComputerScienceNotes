# servlet

## 介绍

* servlet是运行在Java服务器端的程序，用于接受和响应来自客户端基于HTTP协议的请求
* 如果想实现Servlet的功能，可以通过实现javax.servlet.Servlet接口或者继承它的实现类，比如GenericServlet
* 核心方法：service,任何客户端的请求都会经过该方法

![图 1](../images/3cd8417cf4c3248b5f4233112e6e21248554fb5750714cbb31b60bd79b3acb51.png)  

## servlet快速入门

![图 2](../images/d9d2ffcde94b3215b166cb7604d88c5429deacdf3238c3baa932142ab5d56a27.png)  

* 继承GenericServlet
* 重写service方法

![图 3](../images/2a075a38941606688fe12c621d34933343ba144b3ae31375f5ae8b3931be9ac6.png)  

* 在WEB.XML配置Servlet

![图 6](../images/6793a1f09d23bb0e4cc319cf3da1ae2c36f3490d638f45a3bd8a5d300708a1c0.png)  


* 部署并启动项目
![图 5](../images/7602619705b5a27cb34c6fa5bf6c27e476f96e362b5ef53b3b04b9fbeb0d6171.png)  

## servlet的执行过程

```
http://localhost:8080/demo1/servlet1

* demo1是虚拟路径
* servlet1:是资源路径
* localhost是本机地址
* 8080是端口号
```

![图 8](../images/910a88af326818aee953a482e708e80f6bcb014285c8834fea126b8660e09a48.png)  

## servlet关系视图

![图 9](../images/80038d8a0af43a35adf52bf09f3660ccabf43ae59adcce319d6dd1eaf722a396.png)  

## Servlet实现方式-继承HTTPSERVLET

![图 10](../images/7137a15261ea23c565a47c44bd64ec50cbec312137a8046d884b112a6ae4ab4b.png)  


* 创建一个类继承HTTPSERVLET

* 重写doGet和doPost方法
![图 12](../images/8e871f18f6f58388cbd25a8277a1dc4a5ec9fc3192cba936400b70f4f96681e4.png)  


* 在web.xml中配置Servlet
![图 13](../images/d6ccc2c8d231fdb18dfef7fbfb2ed81d1e74c4d7bd1bed7fe0ebeb6952ee99ab.png)  



* 部署并启动项目

![图 14](../images/e59b63cf8b2dc84143a3fa5f9c239cbbd9c98155d67f9d353301b0964ff5792a.png)  



* 通过浏览器测试

```
http://localhost:8080/demo1/servlet2

```

## Servlet的生命周期

![图 15](../images/c50f6be14570fa67e768431ec477d225860fa2efe172b744afadac6cf05f5f95.png)  

结论：Servlet对象只会创建一次，销毁一次，所以Servlet对象只有一个实例。如果一个对象实例在应用中是唯一的存在，那么我们就称之为单例模式。

## 线程安全问题

* 由于Servlet采用的是单例模式，也就是整个应用中只有一个实例对象。所以需要分析一下该实例对象的类成员是否线程安全

* 模拟用户登录功能来查看Servlet线程是否安全

```java
package com.hfut.serv.ServletDemo1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class servlet3 extends HttpServlet {
    private String username;// 定义一个用户名的成员变量
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doGet(req, resp);
        username = req.getParameter("username");// 获取提交的用户名  根据username获取用户名称

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        // 将用户名响应给；浏览器
        PrintWriter pw = resp.getWriter();
        pw.println("welcome:" + username);// 打印
        pw.close();
    }


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

* 结论：一个浏览器代表一个线程，多个浏览器代表多个线程，按理来说，应该是每一个浏览器查看的都是自己的用户名。而现在的结果是浏览器中数据混乱，因此，可以认为Servlet不是线程安全的

![图 16](../images/8558f9c15d93acc72f701d17db534acb939bd136539f41d099a1b375bba2a271.png)  

1. 解决办法一：定义为局部变量

```java
package com.hfut.serv.ServletDemo1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class servlet3 extends HttpServlet {
//    private String username;// 定义一个用户名的成员变量
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = null;// 定义成局部变量  解决线程安全问题
//        super.doGet(req, resp);
        username = req.getParameter("username");// 获取提交的用户名  根据username获取用户名称

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        // 将用户名响应给；浏览器
        PrintWriter pw = resp.getWriter();
        pw.println("welcome:" + username);// 打印
        pw.close();
    }


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}
```


2. 解决办法二:使用同步代码块

```java
package com.hfut.serv.ServletDemo1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class servlet3 extends HttpServlet {
    private String username;// 定义一个用户名的成员变量
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        String username = null;// 定义成局部变量  解决线程安全问题
//        解决办法二：使用同步代码块
        synchronized (this){
            username = req.getParameter("username");// 获取提交的用户名  根据username获取用户名称

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            // 将用户名响应给；浏览器
            PrintWriter pw = resp.getWriter();
            pw.println("welcome:" + username);// 打印
            pw.close();
        }


    }


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

## servlet的映射方式

* 具体名称的方式。访问的资源路径必须和映射配置完全相同
* /开头 + 通配符的方式。只要符合目录结构即可，不用考虑结尾是什么
* 通配符 + 固定格式结尾的方式。只要符合固定结尾格式即可，不用考虑前面的路径

1. 具体名称的方式，随便起一个名字 这里不一定是servlet4

```java
<!--    第一种映射方式servlet4  指定名称的方式-->
<!--    配置servlet4-->
    <servlet>
        <servlet-name>servlet4</servlet-name>
        <servlet-class>com.hfut.serv.ServletDemo1.servlet4</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>servlet4</servlet-name>
<!--        资源访问路径-->
        <url-pattern>/servlet4</url-pattern>
    </servlet-mapping>

```

2. /开头+ 通配符

```java
<!--    第二种映射方式/开头 + 通配符-->

    <servlet>

        <servlet-name>servlet4</servlet-name>
        <servlet-class>com.hfut.serv.ServletDemo1.servlet4</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>servlet4</servlet-name>
<!--        只要前面是/servlet 后面不管填写什么 都可以找到servlet4资源-->
        <url-pattern>/servlet/*</url-pattern>
    </servlet-mapping>
 
```

3. 通配符+ 固定格式结尾

```java
<!--    第三种方式：通配符+ 固定格式结尾  -->
    <servlet>
        <servlet-name>servlet4</servlet-name>
        <servlet-class>com.hfut.serv.ServletDemo1.servlet4</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>servlet4</servlet-name>
<!--        /*.do  指定格式  访问servlet4资源路径  前面都是虚拟目录-->
        <url-pattern>*.do</url-pattern>
    </servlet-mapping>

```

**优先级问题：越是具体的优先级越高，越是模糊通用的优先级与越低。第一种优先级越高**


## 案例-多路径映射问题-指定名称的方式

![图 17](../images/2d5b98c6cabf44eda015ab087f6ad9fbfb57d3413c7d6334888df39f3c0fbb1d.png)  


**这里的案例使用指定的开头加上通配符进行的**

```java
    <servlet>
        <servlet-name>servlet5</servlet-name>
<!--        具体的资源路径  通过servlet的名字找到-->
        <servlet-class>com.hfut.serv.ServletDemo1.Servlet5</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>servlet5</servlet-name>
<!--        指定开头加上通配符-->
        <url-pattern>/hfut/*</url-pattern>
    </servlet-mapping>

```


```java
package com.hfut.serv.ServletDemo1;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Servlet5 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 定义一个商品金额
        int money = 1000;

        // 获取访问资源路径
        String path = req.getRequestURI();

        // 将最后一个/之后的字符串进行截取  先定位最后一个/的索引  然后进行字符串的截取
        path = path.substring(path.lastIndexOf("/"));

        // 条件判断
        if("/vip".equals(path)){
            System.out.println("打九折");
        }else if("/vvip".equals(path)){
            System.out.println("打五折");
        }else{
            System.out.println("不打折");
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);


    }
}


```

## Servlet的创建时机

![图 18](../images/ea87617f70c122346ba740f9494ad5c1c4e486a7f6ec1c2b8fbf0714b86c1487.png)  


**一个xml文件中有多个servlet配置文件，所以加载servlet的时候有个优先级的问题**

```java
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">

    <servlet>
        <servlet-name>servlet5</servlet-name>
<!--        具体的资源路径  通过servlet5的名字找到-->
        <servlet-class>com.hfut.serv.ServletDemo1.Servlet5</servlet-class>
<!--        默认创建时机是第一次访问时 创建servlet5资源-->

<!--        添加这句话 正整数表示服务器启动的时候进行访问  数字大小代表启动的优先级-->
<!--        修改servlet的优先级-->
        <load-on-startup>1</load-on-startup>

    </servlet>

    <servlet-mapping>
        <servlet-name>servlet5</servlet-name>
<!--        指定开头加上通配符-->
        <url-pattern>/hfut/*</url-pattern>
    </servlet-mapping>


</web-app>

```

## 默认Servlet

![图 19](../images/474f9bd1b9f902532788033bfb8991f5f4719a6c0100814fdab484b1c67b830a.png)  


