# SpringMVC视图

## 概述

![图 1](../images/5f939da28259372c81c0d15099dd076365a393dcd99d961cbe04beeb109cdf9a.png)  

## ThymeleafView视图
![图 2](../images/32e10234a1f32cafddc2ac18aeae5f77846814a8964c7026291b9a7865248874.png)  

```java
    @RequestMapping("/testModelMap")
    public String testModelMap(Map<String,Object> map){
        map.put("testRequestScope","hello,map");
        return "success";
    }

```

**视图名称没有前缀**

## 转发视图
**转发请求  转发到另一个视图 然后通过Thymeleaf进行解析**

```java

    @RequestMapping("/testThymeleafView")
    public String testThymeleafView(){
        return "success";// 跳转到test_param页面
    }

//    测试转发视图
    @RequestMapping("/testForward")
    public String testForward(){
        return "forward:/hhh/testThymeleafView";// 转发
    }

```

## 重定向视图

![图 3](../images/0e5e337efff04fe9e01065f29051beaeec79b3064affed4d24eaeb3ff84aea02.png)  

```java
//     测试重定向视图
    @RequestMapping("/testRedirect")
    public String testRedirect(){
        return "redirect:/hhh/testThymeleafView";// 重定向视图
    }

```

## 视图控制器

**当控制器方法 仅仅用来实现页面跳转，即只需要设置视图名称，可以将处理器方法使用view-controller标签进行表示**

**当SpringMVC中设置任何一个view-controller时，其他控制器中请求映射将全部失效，此时需要在SpringMVC的核心配置文件中设置开启mvc注解驱动的标签**

**也就是通过在springmvc中设置view-controller标签来代替在请求控制器中所写的映射**
![图 5](../images/92889c431d9a07377852fd8049eb1491536d9b2b6777e46f47281c9e5a3d2ab9.png)  



![图 4](../images/f488984196b525b440f3870b0e7c7b5027a7953839fdf41e4ab5d88a476e706a.png)  


```java
package com.ustc.mvc.controller;

import org.springframework.web.bind.annotation.RequestMapping;

// 控制器方法仅仅用来实现页面跳转

public class ViewController {
//    @RequestMapping("/")
//    public String index(){
//        return "index";// 转发
//    }

}


```

```xml
<!--     视图控制器仅仅用来实现页面跳转-->
    <mvc:view-controller path="/" view-name="index"></mvc:view-controller>

<!--    开启MVC的注解驱动-->
    <mvc:annotation-driven />
```
