# Filter过滤器

## 概述

![图 1](../images/e9bcb4e9df98f0b631dff25db5dcf3ed60c7402a017ad8c37c619ad2c4d898bc.png)  

## 基本介绍

![图 2](../images/c71df853771a2de8a0cdd32f3d00cf23eed6ad8d7847170c78cac677e920df37.png)  

## 基本使用

![图 3](../images/c0a6ecbd71564e9afca6cb8e62a10f1d6a4fc77819f1fb1478ecdbc129acd1c5.png)  

![图 4](../images/87e349e610b13a9ea378e4074ee09aee913efff2b0beb05e3e24d7700e1809e5.png)  

servlet1

```java
package com.hfut.servlet;
import org.w3c.dom.html.HTMLHtmlElement;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.function.DoubleBinaryOperator;

public class servlet01 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doGet(req, resp);
        System.out.println("servlet01执行");
        // 使用指定格式
//        resp.setContentType("text/html;charset =utf-8");
        resp.getWriter().write("servlet1执行");// 中文乱码
    }


    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

Filter

```java
package com.hfut.filter;

import javax.servlet.*;
import javax.servlet.annotation.*;
import java.io.IOException;

// 表示请求的资源是servlet1 请求会被拦截进行处理  /* 表示拦截所有的请求
@WebFilter("/servlet1")
public class Filter1 implements Filter {
    public void init(FilterConfig config) throws ServletException {

    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
//        chain.doFilter(request, response);
        // 过滤器用于拦截请求  然后执行过滤方法
        System.out.println("filter1执行了");

        // 设置请求的格式
        response.setContentType("text/html;charset=UTF-8");// 处理乱码

        // 放行
        chain.doFilter(request,response);

    }
}


```

## 使用细节

* 配置方式
  
![图 5](../images/adb7acf37219b89462c1b87cd08453794a0cf99ebd4beff244bc9ff5ca64124d.png)  


* 使用顺序
![图 6](../images/10e0e6bd405365dda7040f55d39e66796a906f35afc6c05145ff97e911fad2e0.png)  



## 过滤器的生命周期

![图 7](../images/3e240a631e88bfd3c690c81ab0cf204699db68f4d7261e74783bce8b709c462d.png)  


## FilterConfig对象的配置

![图 8](../images/6c36f92c7372b5172c9ba51c665f362775c6f1d18d1bb37e3ac1f62cc167c871.png)  

```java
    <filter>
        <filter-name>Filter1</filter-name>
        <filter-class>com.hfut.filter.Filter1</filter-class>
<!--        配置filterConfig参数对象-->
        <init-param>
            <param-name>username</param-name>
            <param-value>zhangsan</param-value>
        </init-param>
    </filter>

    <filter-mapping>
        <filter-name>Filter1</filter-name>
        <url-pattern>/*</url-pattern>
    </filter-mapping>

```

```java
package com.hfut.filter;

import javax.servlet.*;
import javax.servlet.annotation.*;
import java.io.IOException;

// 表示请求的资源是servlet1 请求会被拦截进行处理  /* 表示拦截所有的请求

public class Filter1 implements Filter {
    public void init(FilterConfig config) throws ServletException {
        System.out.println("对象初始化成功");
        
        // 获取过滤器名称
        String filterName = config.getFilterName();
        System.out.println(filterName);

        // web.xml 文件中配置config  参数
        
        // 根据name获取value
        config.getInitParameter("username");

    }

    public void destroy() {

        System.out.println("对象销毁");
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
//        chain.doFilter(request, response);
        // 过滤器用于拦截请求  然后执行过滤方法
        System.out.println("filter1执行了");

        // 设置请求的格式
        response.setContentType("text/html;charset=UTF-8");// 处理乱码

        // 放行
        chain.doFilter(request,response);

    }
}
```




