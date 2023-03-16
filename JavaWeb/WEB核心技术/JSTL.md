# JSTL

## 概述
![图 1](../images/de6c5bfdd00e09b007c7d1c8505dae5015f2fa36da9e68b83a85075961be4451.png)  

## 基本使用

![图 2](../images/5aa0bc82323e656d3e040d9e7289c08926d1c068f21268f75940488842ec2a18.png)  

```java
<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: Admini
  Date: 2023/1/28
  Time: 9:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
    <title>流程控制</title>
</head>
<body>
<%--向域对象中添加成绩数据  EL表达式--%>
${pageContext.setAttribute("score","A")}

<%--对成绩进行判断--%>
<c:if test="${score eq 'A'}">优秀</c:if>

<%--对成绩进行多条件判断--%>
<c:choose>
    <c:when test="${score eq 'A'}">优秀</c:when>
    <c:when test="${score eq 'B'}">良好</c:when>
    <c:when test="${score eq 'C'}">及格</c:when>
    <c:when test="${score eq 'D'}">不及格</c:when>
    <c:otherwise>成绩非法</c:otherwise>
</c:choose>

<%--向域对象中添加集合--%>
<c:forEach items="${list}" var="str">
    ${str}<br>
</c:forEach>

<%
    ArrayList<String> list = new ArrayList<>();
    list.add("aa");
    list.add("bb");
    list.add("cc");
    list.add("dd");

    pageContext.setAttribute("list",list);

%>


</body>
</html>


```
