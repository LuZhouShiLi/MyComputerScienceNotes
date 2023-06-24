# 一文快速入门redis

## 简单介绍

![图 1](../images/0bc2cb3a6a27a8472c990abb3053431ab94a6a861a2bf68d01c834ddb9007313.png)  



## 启动redis

**使用命令redis-server.exe redis.windows.conf**

![图 2](../images/95ae92883ea440979cc2a974c8f1e25533b1218337d309c762a6c95aed9c7cb9.png)  


&emsp;连接redis服务，redis-cli,设置Key值  然后取出key值，

![图 4](../images/9c1d06651f8078e2763b5baed8257e954b925c20d5546c8c8e3b7ddecf8d1353.png)  


**redis清屏是clear**


&emsp;哈希存储结构，一个key对应多个key 然后每一个key对应一个value

![图 5](../images/017b9019100defdd9df9ffb17962c2b78dae76f376bf58cc84198b27c78ac000.png)  

## SpringBoot整合redis

**勾选依赖配置**
![图 6](../images/11d9fee06ff55e64d1b29963dfbadb96bec90bfbf5ad593585491d04e5410bab.png)  

**导入yml配置**

```
spring:
  redis:
    host: localhost
    port: 6379

```


**测试代码.记得注入redisTemplate**

```java

package com.ustc;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.ValueOperations;

@SpringBootTest
class Redis1ApplicationTests {

    @Autowired
    // 操纵redis
    private RedisTemplate redisTemplate;

    @Test
    void contextLoads() {
        System.out.println("fvcnsdjufhviuds");
    }
    
    @Test
    void set(){
//        存储一个值
        ValueOperations ops = redisTemplate.opsForValue();
        ops.set("age",11);
    }

    @Test
    void get(){
//        取出这个值
        ValueOperations ops = redisTemplate.opsForValue();
        Object age = ops.get("age");
        System.out.println(age);

    }

    

}

```

**测试hashSet**

```java
   @Test
    void hset(){
        HashOperations ops = redisTemplate.opsForHash();
        ops.put("info","b","bb");
    }
    

    @Test
    void hget(){
        HashOperations ops = redisTemplate.opsForHash();
        Object val = ops.get("info", "b");
        System.out.println(val);
    }


```

## 使用它StringReidsTemplate

**RedisTemplate 以对象作为key和value 内部对数据进行序列化**

```java
package com.ustc;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.data.redis.core.ValueOperations;

@SpringBootTest
public class Test1 {
    @Autowired
    private StringRedisTemplate stringRedisTemplate;

    @Test
    void get(){
        ValueOperations<String, String> ops = stringRedisTemplate.opsForValue();
        String name = ops.get("name");
        System.out.println(name);


    }
}


```






