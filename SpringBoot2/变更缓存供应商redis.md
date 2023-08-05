# 变更缓存供应商redis

## 简单使用

* 添加pom文件依赖

```java
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>
```


* 添加配置

```java

spring.cache.type=redis
spring.redis.host=localhost
spring.redis.port=6379
```

同时需要启动redis服务

redis-server.exe redis.windows.conf

如果出现启动失败：

```
redis-cli.exe

　　shutdown

　　exit

```





