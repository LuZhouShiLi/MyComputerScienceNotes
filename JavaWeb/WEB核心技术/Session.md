# Session

## 概述

![图 1](../images/08a558e6451193cc1c0b95bc0924e891fcc17237433c3a640017423171daf4b4.png)  


## 常用的方法

![图 2](../images/1e39a68638e54c3c90f0fb49aa1140cff07d7ef7e023a795016fff0b647832c8.png)  

## HttpSession的获取

![图 3](../images/df5b0e8850336b1f7f138df0f3f36db4adfbd917b4b70497126e8f2fe7811af6.png)  

## HttpSession的使用

![图 4](../images/5684f18b54a2ddaaf1cad25a4e1ff1c2ae520f9828e883f48fd66d504435c857.png)  

* 在第一个Servlet中获取请求的用户名
* 获取HttpSession对象
* 将用户名设置到共享数据中
* 在第二个Servlet中获取HttpSession对象
* 获取共享数据用户名
* 将获取到的用户名响应给客户端浏览器

Servlet1

```java
package com.hfut.servlet;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取请求的用户名
        String username = req.getParameter("username");
        // 获取httpsession对象
        HttpSession session = req.getSession();
        // 将用户名信息添加到共享数据中
        session.setAttribute("username",username);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);

    }
}


```


Servlet2
```java
package com.hfut.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class Servlet2 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取请求的用户名
        HttpSession session = req.getSession();
        Object username = session.getAttribute("username");

        // 将用户名相应给浏览器
        resp.getWriter().write(username + "");
        // 那么访问servlet2资源的时候 浏览器就会打印username信息
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);

    }
}


```

![图 5](../images/dba3dc71d66789f80c42a6475c20a6d5789b14f7db5d622de426ea7964086d29.png)  


**以上两个servlet拿到的session对象是同一个，保证共享数据资源也是一样的**






