# JSP


## 概述

![图 1](../images/b810d6893c749fefa147500e592ec19ebea3c2088ac8e494df1d6ea733244b98.png)  

## JSP的快速入门

![图 2](../images/c7683cb51b484b696133e08d1128092ecdf1e8c17e0acdd7ad06eb2f66f3692b.png)  

```html
<%--
  Created by IntelliJ IDEA.
  User: Admini
  Date: 2023/1/23
  Time: 20:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
<%--  浏览器默认打开index.jsp文件--%>
   <h1> 这是一个jsp文件</h1>
  </body>
</html>
```


## JSP的执行过程

**JSP文件本质是JAVA文件**

![图 3](../images/6f966ae4f1889f14132caa4d5e489afe8b5cfceaf1a1fd0f74770ee3d372fc3f.png)  


## JSP的语法

![图 4](../images/8d65c2d84dad03d3fb93667d972ca821486a8095beaa8f5daf3b12558f7c2dbf.png)  

```java
<%--
  Created by IntelliJ IDEA.
  User: Admini
  Date: 2023/1/23
  Time: 20:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
   <% 
    out.println("Hello JSP");
   %>
<%--   相当于输出语句--%>
  <%="HELLO"%>

<%--  JSP的声明--%>
  <% String s = "abc";%>
<%--  输出声明的变量--%>
<%=s%>

  </body>
</html>


```

## JSP的Page指令

![图 5](../images/48ab84578a924657225472d82b54d575c3745e81193926d8665c9f1242c9e0c8.png)  

![图 6](../images/5730341c12e039fe6552ded321ddb45f784ed2732bec6edf2c8c58be8beb5267.png)  

## JSP使用细节

![图 7](../images/ac78754a33679a5d7cab1d34d0b6d87fd75e5e653d4ec847871292db85a7f555.png)  


