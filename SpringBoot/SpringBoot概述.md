# SpringBoot概述以及快速入门

## Spring缺点

![图 1](../images/f17c03fb838c37cc8094d877c76fa83e0abb9488b9def2fb3ea1c1ee2622788b.png)  

## SpringBoot功能概述

![图 2](../images/a5e8ad0dfe9e534abdeeab8efe107bb39e9cd056d0a1850629df9223dcb88a66.png)  

## 快速入门

![图 3](../images/0329f545b61fbd5515fb59389e15a35b7c5028d5a9544ba29c499c7f24e13f80.png)  

### 创建springboot工程-MAVEN

![图 4](../images/253f36143efcb6634a72acb962ebed17a0639f16f91ce82ea6b6afa9f1ba2dc1.png)  

![图 5](../images/81fe1fe741a114335b83358904f6f72c931e8609fee61377f47eb8447a63fdf0.png)  

### 导入springboot起步依赖

```xml
<!--    springboot工程需要继承的父工程-->
    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.7.10</version>
        <relativePath/> <!-- lookup parent from repository -->
    </parent>

```


```xml
<!--        web开发的起步依赖-->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

```

### 编写controller

```java
package com.itheima.controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// 定义controller层
@RestController
public class HelloController {
    // 定义 资源访问路径
    @RequestMapping("/hello")
    public String hello(){
        return "hello Spring boot";
    }
}
```


### 编写引导类-项目入口


```java
package com.itheima;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

// springboot项目的入口
@SpringBootApplication
public class DemoSpring1Application {

    public static void main(String[] args) {
        SpringApplication.run(DemoSpring1Application.class, args);
    }

}

```

![图 6](../images/2388682c53aa07a24a14e89546bd717ea69d6d61f51199a52ec8677a4d97b013.png)  


![图 7](../images/2978bed262b04fdbac639072e4f1c0f120a77b1d1ab76da9a7544fe71c61cf08.png)  



