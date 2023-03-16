# Cookie

## 概述

![图 1](../images/ab6c667496fe5b5ac27a03d769312f1885b14dc4c6595f974089ebc1eccb029c.png)  


## Cookie介绍

* Cookie: 客户端会话管理技术
  * 将要共享的数据保存到客户端中
  * 每次请求时，把会话信息带到服务器端，从而实现多次请求的数据共享
* 作用：可以保存客户端访问网站的相关内容，从而保证每次访问时先从本地缓存中进行获取，一次提高效率

## cookie的常见属性

![图 2](../images/1eea8d97f000975320dc0354b05740fed4e7752efe08f622f7a2af41ad18525a.png)  

## Cookie常用的方法

![图 3](../images/4c53b010f81df89369eea6ccc56d701a8a179c9634ef2c7f068a535991107e4b.png)  


## Cookie的添加以及获取

![图 4](../images/c64788fab5a3a512d49983bada4c4909ed362727663ce05d520a1d906bfedc65.png)  

## Cookie的使用

```java
package com.hfut.servlet;
import javax.servlet.*;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 设置编码格式
        resp.setContentType("text/html;charset=UTF-8");

        // 通过响应对象写出提示信息
        resp.getWriter().write("欢迎访问本网站，您的最后访问时间为：<br>");

        // 创建cookie对象  用于记录最后的访问时间
        // 设置两个属性 Name  还有Value
        Cookie cookie = new Cookie("time",System.currentTimeMillis() + "");

        // 设置最大的存活时间
        cookie.setMaxAge(3600);// 一个小时  单位是秒

        // 将cookie对象添加到客户端
        resp.addCookie(cookie);// 通过响应对象添加cookie对象

        // 获取cookie数组
        Cookie[] cookies = req.getCookies();
        for (Cookie cookie1 : cookies) {
            if(cookie1.getName().equals("time")){
                // 将value取出来
                String value = cookie1.getValue();
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");// 设置指定格式进行解析
                resp.getWriter().write(sdf.format(new Date((Long.parseLong(value)))));// 解析一下字符串
            }
        }



    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);

    }
}


```

## Cookie的使用细节

![图 5](../images/2a33d743f72aa2f9381f67b39b6a77ddbe8b89cf51fca78b418e835776472fad.png)  


