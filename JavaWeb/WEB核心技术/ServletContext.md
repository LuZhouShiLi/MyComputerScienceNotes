# ServletContext

## 概述

* ServletContext是应用上下文对象（应用域对象）。每一个应用中只有一个ServletContext对象
* 作用：可以配置和获得应用的全局初始化参数，可以实现Servlet之间的数据共享
* 生命周期：应用一加载则创建，应用被停止则销毁。


![图 1](../images/75a7a9c3c0a6056c5113837d25f0e0bd1115ace330aa7a3c8bff527acd619dca.png)  


## 域对象

* 域对象指的是对象有作用域。也就是有作用范围。域对象可以实现数据的共享。不同作用范围的域对象，共享数据的能力也不一样。
* 在Servlet规范中，一共有四个域对象。ServletContext就是其中的一个。他也是web应用中最大的作用域，也叫application域，它可以实现整个应用之间的数据共享。

## ServletContext的配置方式

![图 2](../images/7f0bb19860f40a63530af87d5a7b081834f368adc600b20526796c7fbdb2dcf9.png)  

**注意：配置ServletContext不能再servlet标签下进行配置，必须在web-app标签下面进行配置 因为他是多个servlet资源的共享的配置，不是某一个独有的配置**

```java
<!--配置servletContext-->
    <context-param>
        <param-name>globalEncoding</param-name>
        <param-value>UTF-8</param-value>
    </context-param>

    <context-param>
        <param-name>globalDesc</param-name>
        <param-value>This is ServletContext</param-value>
    </context-param>

```

## ServletContext的常用方法

![图 3](../images/c0ef59bd09edc2345a67b995d3c71409f8e0fee7713d1f924b1db846f0ac6225.png)  

```java
 @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取ServletContext对象
        ServletContext context = getServletContext();

        // 根据key获取value
        String globalDesc = context.getInitParameter("globalDesc");
        System.out.println(globalDesc);

        // 获取应用的虚拟目录
        String contextPath = context.getContextPath();
        System.out.println(contextPath);

        // 根据虚拟目录获取绝对路径 getRealPath
        String realPath = context.getRealPath("/");
        System.out.println(realPath);
    }

```

## ServletContext共享数据的方法

**不同servlet共享数据的方法**

![图 4](../images/fb24439d29debf0f3812c448099a77009541d18ee3fffb8d3dfeea36a1f1630f.png)  

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取ServletContext对象
        ServletContext context = getServletContext();

        // 根据key获取value
        String globalDesc = context.getInitParameter("globalDesc");
        System.out.println(globalDesc);

        // 获取应用的虚拟目录
        String contextPath = context.getContextPath();
        System.out.println(contextPath);

        // 根据虚拟目录获取绝对路径 getRealPath
        String realPath = context.getRealPath("/");
        System.out.println(realPath);

        // 设置共享数据 使得不同的servlet都可以访问到该共享数据
        context.setAttribute("username","xxx");

        // 根据key获取共享数据
        Object uesrname = context.getAttribute("uesrname");
        System.out.println(uesrname);

        context.removeAttribute("username");// 移除共享数据  根据Key
    }

```











