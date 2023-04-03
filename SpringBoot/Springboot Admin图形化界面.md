# SpringBoot  Admin 图形化界面


## 简单介绍

![图 1](../images/296ad2badf1c7be43d2eba562df127b2e31e2c8e50ee2e8f8fea2e4af9d15b7a.png)  


![图 2](../images/d2cf7202a8aa5cc4ec4946680ebcebb257c2687f8f42c60286dc552e8007e20e.png)  


## 创建spring-admin-server模块

**勾选spring web和admin server两个依赖**

![图 3](../images/85d8f62b58153301145d7f4a74035159540c797347f6d81acadaa6cf00ff1bb7.png)  

**服务端添加注解EnableAdminServer**

```java
package com.itheima.springadminserver;

import de.codecentric.boot.admin.server.config.EnableAdminServer;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;


@EnableAdminServer
@SpringBootApplication
public class SpringAdminServerApplication {

    public static void main(String[] args) {
        SpringApplication.run(SpringAdminServerApplication.class, args);
    }

}

```


## 创建spring-admin-client模块

![图 4](../images/aad743f748deb0e6107d34336d75c90fbc3535c935fe4440170d0d224d8df56b.png)  

在application.properties文件中指定服务器地址


```xml

# 指定admin.server地址
spring.boot.admin.client.url=http://localhost:9000

# 健康信息检查
management.endpoint.health.show-details=always

# 开启所有的配置
management.endpoints.web.exposure.include=*
```


## 启动


**启动server 之后启动client,地址栏输入localhost:端口号**

![图 5](../images/2694efe3305a371606d803d153b8e23bfe2e296eb365bf721ada61178d527908.png)  

