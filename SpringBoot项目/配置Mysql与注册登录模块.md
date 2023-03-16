# 配置Mysql与注册登录模块

## 应用服务模型

![图 1](../images/c948134aadc39a0483ec3a0ad7eecd329fc71e09f81e0bcd92afe1b5014bfc75.png)  


SpringBoot是一个运行在后端的程序，若干客户端会不断请求springboot 然后springboot会根据请求和数据库进行交互。


## IDEA 连接数据库

### 点击IDEA右侧的database 选择mysql数据库

![图 2](../images/80b1f3ffd2d3ff04328a4ed8bc46c52184deb9947f310010def7d52d0d9b2acc.png)  

* 这里我填写了用户名和密码 以及数据库名称  记得勾选默认架构
![图 3](../images/7cc5bb3ef075f56cb14484e68ce31d505576b8ec80ef3a0648dbaff1fc3a7d1b.png)  

* 点击连接测试 需要下载驱动 点击下载

![图 4](../images/d9761ae84d0eafa9ccc1e5d181c5e52ffea92bcb56306e4d60a3e480b7f607ee.png)  

* 点击连接测试 连接成功

![图 5](../images/529b41ca987ba81862ba111c7cfac3e826c6faeccc5989b93e6eeb61baba2cbe.png)  


![图 7](../images/d0e3b1a2271b0758df2fbec013448e658598c567621a7e4b312108611e7361cc.png)  

### 更新数据

点击表格数据 更改数据 回车  点击上面绿色箭头 上传数据至数据库
![图 8](../images/fea05afa5317f8380c5bf69b790bc3ed15300910fbf0005b92d0087ab4016424.png)  


可以看到后台数据库已经更新

![图 9](../images/296246047d44e355e54eaf1aaf43d7356c45765e8a9d47b2ae7dce5e94cb9e2b.png)  

## SpringBoot配置数据库依赖

### Maven

仓库地址```https://mvnrepository.com/```

### 安装JDBC依赖

```js
Spring Boot Starter JDBC
```

复制以下内容,将依赖粘贴到pom.xml中

![图 10](../images/f7e08e9f378cbc13840ab8076091179255b8221fb0215537fa8ccb3d13979689.png)  


![图 11](../images/9fbbb7b5167e1f92d69da2555aecb54984f73a8aa9690c5bae67594608e99280.png)  

### lombok

![图 12](../images/0e125219b6f303426b0e5e58b77c293acae14c8e770ada925bef69da67934d4d.png)  


### MySQL Connector/J


![图 13](../images/cecd93fc5f9183fe2d72df3b524c45396cffd0c0ed817c38e4658caebfe27638.png)  


### MyBatis Plus 

![图 14](../images/3aa7d464378fd0ebd52084a8e1c63b7b6637f08f53eb0c657f5c4e206374ad13.png)  


### mybatis-plus-generator

![图 15](../images/e8e948b892cce8757039d6c7110cda3f79b79b0cf7c277caf0abfffd1ef220cf.png)  

### 解决依赖爆红问题


点击右侧Maven重新加载 

![图 16](../images/eaf3023c7d0bbf8aba35d444ca27f348fb4508d5dd900dff60b83b7549ac7173.png)  

### 添加数据库配置

这里的kob是数据库名称

```js
spring.datasource.username=root
spring.datasource.password=123456
spring.datasource.url=jdbc:mysql://localhost:3306/kob?serverTimezone=Asia/Shanghai&useUnicode=true&characterEncoding=utf-8
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
```


### SpringBoot中的常用模块

* pojo层：将数据库中的表格对影成java中的class
* mapper层 将pojo层的class操作映射成sql语句
* service层：写具体的业务  组合使用mapper中的操作
* controller层：负责请求转发  接受页面传过来的参数，传给Service处理，接到返回值，再传给页面


### pojo层的user表格

```java
package com.kob.backedn2.pojo;

// 数据库一张表对应一个类  @data 将常用的get set方法 添加进去
//@NoArgsConstructor  无参构造函数
//@AllArgsConstructor  有参构造函数
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class User {
    private Integer id;
    private String username;
    private String password;
}

```

