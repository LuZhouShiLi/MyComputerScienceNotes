# 请求对象resquest

## 概述

![图 1](../images/1a2ae536001b18cf94e95433631d940400102d403942fcb9cf927254f6ee85ff.png)  

## 请求对象常用方法-获取各种路径

![图 2](../images/1e91d7682a422aaeba47992b434dbcc9de2182cf6db6b76acbbd5f6f2d5357ea.png)  

```java
package com.hfut.servlet;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // req 客户端请求资源
        // 获取虚拟目录名称
        String contextPath = req.getContextPath();
        System.out.println(contextPath);

        // 获取servlet的映射路径  也就是映射的servlet类
        String servletPath = req.getServletPath();
        System.out.println(servletPath);

        // 获取访问者ip
        String remoteAddr = req.getRemoteAddr();
        System.out.println(remoteAddr);

        // 获取请求的消息数据
        String queryString = req.getQueryString();
        System.out.println(queryString);

        // 获取统一资源标识符  输出 虚拟目录和 资源路径
        String requestURI = req.getRequestURI();
        System.out.println(requestURI);

        // 获取统一资源定位符  打印 浏览器的地址栏url
        StringBuffer sb = req.getRequestURL();
        System.out.println(sb);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

## 获取请求头的信息

![图 3](../images/9cc198bb99590c613771db6c05235ffb282d32da42066170e6247b896fe1a323.png)  

```java
package com.hfut.servlet;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Enumeration;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       // 根据请求头名称获取一个值
       String connection = req.getHeader("connection");// 获取连接状态
        System.out.println(connection);

        // 根据请求头名称获取多个值
        Enumeration<String> values = req.getHeaders("accept-encoding");

        while(values.hasMoreElements()){
            String s = values.nextElement();
            System.out.println(s);
        }

        // 获取所有的请求头名称
        Enumeration<String> names = req.getHeaderNames();

        while(names.hasMoreElements()){
            String name = names.nextElement();// 获取Key
            String value = req.getHeader(name);  // 根据key获取value
            System.out.println(value);
        }
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

## 获取请求参数的信息

![图 4](../images/32b2fc52fd43e9c35cebf77e197a3fe2cb09be793db3f1a7125585c69b800047.png)  

```java
package com.hfut.servlet;
import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Map;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        System.out.println(username);

        String password = req.getParameter("password");
        System.out.println(password);
        System.out.println("----------------------------");
        
        // 根据name获取所有的数据  返回一个数组
        String[] parameterValues = req.getParameterValues("hobby");
        for (String parameterValue : parameterValues) {
            System.out.println(parameterValue);
        }

        // 获取所有的名称
        Enumeration<String> parameterNames = req.getParameterNames();

        while(parameterNames.hasMoreElements()){
            String s = parameterNames.nextElement();
            System.out.println(s);
        }
        
        // 获取所有参数的键值对
        Map<String, String[]> parameterMap = req.getParameterMap();
        for (String s : parameterMap.keySet()) {
            // 使用keySet 返回Map的所有键的集合
            String[] strings = parameterMap.get(s);// 返回该键对应的值数组
            for (String string : strings) {
                System.out.println(string);
            }
        }


    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```

启动tomcat之后，提交表单之后，信息被存入servlet1资源中
![图 5](../images/4a681e5d4fe5869595bc85cd5e242466013cad994702fc6ac7af816a6de833a7.png)  

![图 6](../images/841d2c146b1ecb8c088f4bc243f835137a1240341d523d744901dc6d9058518e.png)  


## 获取参数手动封装对象

```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 根据名称获取参数对象
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String[] parameterValues = req.getParameterValues("hobby");

        // 封装学生对象
        Student s = new Student(username,password,parameterValues);

        // 输出学生对象
        System.out.println(s);
    }
```

## 获取参数反射封装对象

```java
package com.hfut.servlet;
import com.hfut.bean.Student;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.io.IOException;
import java.lang.reflect.Method;
import java.util.Enumeration;
import java.util.Map;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取所有的数据
        Map<String,String[]> map = req.getParameterMap();

        // 封装学生对象
        Student s = new Student();
        for (String key : map.keySet()) {
            // 遍历每一个key
            String[] value = map.get(key);

            try {
                PropertyDescriptor pd = new PropertyDescriptor(key,s.getClass());
                // 获取对应的set方法
                Method writeMethod = pd.getWriteMethod();

                if(value.length > 1){
                    writeMethod.invoke(s,(Object) value);
                }else{
                    writeMethod.invoke(s,value);
                }

            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println(s);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}


```


## 参数工具类封装对象

```java
package com.hfut.servlet;
import com.hfut.bean.Student;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Enumeration;
import java.util.Map;

public class Servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取所有的数据
        Map<String, String[]> parameterMap = req.getParameterMap();
        // 封装学生对象
        Student stu = new Student();

        try {
            BeanUtils.populate(stu,parameterMap);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        } catch (InvocationTargetException e) {
            throw new RuntimeException(e);
        }


    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
    }
}
```

## 流对象获取信息

![图 7](../images/3ff00f3114caf6a701b3d36bb4f20d3b587224fca497435ac57d481f5f42c2ba.png)  

```java
protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取字符流  必须是post方式
        BufferedReader br = req.getReader();
        String line;
        while((line = br.readLine()) != null){
            System.out.println(line);
        }

        // 字节流
        ServletInputStream is = req.getInputStream();
        byte[] arr = new byte[1024];
        int len;

        // 读取字节流 填充到字节数组arr
        while((len = is.read(arr)) != -1){
            System.out.println(new String(arr,0,len));
        }
    }
```


## 请求域

![图 8](../images/f09efc6c1e2ae3767904ca62cba039c6745ff9cbec203b83baf9b397a220de66.png)  

## 请求转发

* 请求转发：客户端的一次请求到达之后，发现需要借助其他Servlet来实现功能
* 特点：
  * 浏览器地址栏不变
  * 域对象中的数据不丢失
  * 负责转发的Servlet转发前后的响应正文会丢失
  * 由转发的目的地来响应客户端

![图 9](../images/3b93260e8da742e26cde72afba91ebc3a08852595e174385a9dfd9fd57fff6db.png)  

```java
protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        // 设置共享数据
        req.setAttribute("encoding","gbk");

        // 获取请求调度对象
        RequestDispatcher requestDispatcher = req.getRequestDispatcher("/Servlet2");//转发给servlet2

        // 将请求和响应转发给目标对象
        requestDispatcher.forward(req,resp);

    }

```


## 请求包含

![图 10](../images/329157a32ff537dc0b3d985581ed473dd355ab6f00f454e8da63f1f44bbde095.png)  

![图 11](../images/055454080848a0528eeaa11ee5c22cee5689d9a195b968e0d5a09c7241316576.png)  


```java
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        System.out.println("servlet1执行");
        
        // 获取请求调度对象
        RequestDispatcher requestDispatcher = req.getRequestDispatcher("/servlet2");

        // 实现请求包含功能
        requestDispatcher.include(req,resp);
    }

```










