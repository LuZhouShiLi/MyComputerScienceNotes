# MongoDB简单快速入门


## 简单介绍

&emsp;MongoDB是一个开源、高性能、无模式的文档型数据库。NoSQL数据库产品中的一种，是最想关系型数据库的非关系型数据库

## 应用场景

![图 1](../images/7e94070dda5a0b1c191c782219bde2db1f27dd8082afb20dfab062f9ffb2ef18.png)  


## 安装与启动

&emsp;直接将安装的压缩包进行解压，然后在创建一个data文件夹，在data文件夹下面创建一个子文件夹db

![图 2](../images/3ac52848916b90969ab5aea33faced99dac4eece169223ae122319870d41832e.png)  


**启动服务端 创建数据库**
**mongod --dbpath=..\data\db**

进入bin目录下面 cmd回车
![图 3](../images/9b32942d369e86ccdad774de5354c011a280314365b0722fd5258a01234f1490.png)  

![图 4](../images/98d99b67276ca873f014c010ccd470725b36f8948461496af5e0e67be51b7790.png)  


**启动客户端，直接使用mongo 默认服务器地址和端口号**

![图 5](../images/8898ce8da30be189a1303ed99365283960ff222a20ce3f2702753ba1d96954b3.png)  


**但是命令行操作不够直观，也不是很方便，直接使用客户端软件操作robot3d**

**创建一个新的连接**

![图 6](../images/efda486f3b61eed737b2c2180c83ded46eabb610467084a1c24708061c31ff34.png)  


## 基础操作

* 创建一个表book
  ![图 7](../images/61669776d245fb2cc9524f219cc28a4bd0744d2129e26ec61c1965323ac5266e.png)  


* 新增一个数据

```

db.book.save({"name":"springboot"})

```

* 查询表中的所有数据

```
db.getCollection('book').find({})

```

![图 8](../images/2ff3fedf8d5f248c05e88ce426d33fddbad3ddefde63c7befa54b1c8495868f4.png)  


* 待条件的查询

```java
db.book.find({name:"springboot"})

```

* 更新操作

```
db.book.update({name:"springboot"},{$set:{name:"springboot2222"}})

```

![图 9](../images/7e78f7c8770f84e16d944d0deb512875b181d60158628db0176bca83e01bb2b2.png)  


## SpringBoot整合MongoDB


* 创建工程，记得勾选依赖

![图 10](../images/b960bb017e11f2ff2b9fc33241db1f7e21b325533587bf52425ef38b15cb28f3.png)  

* 添加相关配置内容 连接创建的数据库

```
spring:
  data:
    mongodb:
      uri: mongodb://localhost/itheima

```

* 在测试类中进行测试

```java
package com.example;

import com.example.domain.Book;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.mongodb.core.MongoTemplate;

import java.util.List;

@SpringBootTest
class Mongo1ApplicationTests {

    @Autowired
    private MongoTemplate mongoTemplate;

    @Test
    void contextLoads() {
        Book book = new Book();
        book.setId(2);
        book.setName("dcnjuasdbc");
        book.setType("dcnjuasdbc");
        book.setDescription("dcnjuasdbc");

//         使用mongoDB的API 存储数据
        mongoTemplate.save(book);
    }
    
    @Test
    void find(){
        List<Book> all = mongoTemplate.findAll(Book.class);
        System.out.println(all);

    }
}
```





