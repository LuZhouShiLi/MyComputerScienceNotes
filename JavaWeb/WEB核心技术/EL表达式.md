# EL表达式

## 概述

![图 4](../images/ab8ee1e9c91c9eb04904c14b3c4f2a55d49a7e391917b7b4f936574f0d2671f5.png)  


## 基本使用


```jsp
<%--
  Created by IntelliJ IDEA.
  User: Admini
  Date: 2023/1/25
  Time: 21:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <%--    想请求域中添加username数据--%>
  <%request.setAttribute("username","zhangsan");%>

  <%--  获取请求域中的username信息  使用JAVA代码块--%>
  <%out.println(request.getAttribute("username"));%><br>

  <%--  JSP表达式获取--%>
  <%= request.getAttribute("username")%><br>

  <%--  使用EL表达式获取  不需要使用请求域--%>
  ${username}
  </body>
</html>


```

## EL表达式获取数据

![图 5](../images/307d28b18102f52c94d462f6e17d5bca6aa37cafcaae9e4e38e80b0fc143afc5.png)  

```java
<%@ page import="com.hfut.servlet.Student" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.HashMap" %><%--
  Created by IntelliJ IDEA.
  User: Admini
  Date: 2023/1/25
  Time: 21:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" import="com.hfut.servlet.Student"%>
<html>
  <head>
    <title>EL表达式获取数据</title>
  </head>
  <body>
<%--      1.获取基本数据类型--%>
<%--使用页面域对象  添加数据--%>
  <% pageContext.setAttribute("num",10);%>
  基本数据类型：${num}<br>

<%--  获取自定义数据类型--%>
  <%
    Student stu = new Student("张三",23,1);
    pageContext.setAttribute("stu",stu);
  %>
  自定义对象：${stu}<br>
<%--直接通过属性名称即可  底层调用get方法--%>
  学生年龄:${stu.name}

<%--  获取数组类型--%>
  <%
    String[] arr = {"hello","world"};
    pageContext.setAttribute("arr",arr);
  %>
  数组:${arr}
  0索引元素:${arr[0]}

<%--  获取List集合--%>
  <%
    ArrayList<String> list = new ArrayList<>();
    list.add("aaa");
    list.add("bbb");
    pageContext.setAttribute("list",list);// 添加集合到共享资源中
  %>

<%--不显示地址值  因为list已经重写toString方法--%>
  集合对象：${list}

<%
  HashMap<String,Student> map = new HashMap<>();
  map.put("hm01",new Student("张三",23,1));
  map.put("hm02",new Student("李四",23,1));
  pageContext.setAttribute("map",map);
%>
  map对象:${map}
  第一个学生对象：${map.hm01} <br>

  </body>
</html>


```

## EL表达式的注意事项

*  EL表达式没有空指针异常
*  EL表达式没有索引越界异常
*  EL表达式没有字符串的拼接

## EL表达式的运算符

![图 6](../images/54988b1e7a41649ebc92f9868126f6d5be39659c8325a730c046eaccad4af232.png)  

![图 7](../images/0c9adeac81551628ed4bb69a180b572163caa210808f53e71bec50bd0e0ceca3.png)  

![图 8](../images/6c95d3eae286c6e255b3524384a204fd0e20f6d61e743b4e6d1bab8c5fc94b20.png)  



## EL表达式使用细节
![图 9](../images/c66dae0ef4bb267a82dafee252813156a2a5a0ae9336152f2ea87dd3bff8630b.png)  



