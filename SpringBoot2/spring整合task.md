# spring整合task


## 简单使用

* 开启定时任务功能 @EnableScheduling

```java
package com.ustc;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication

//开启定时任务功能  
@EnableScheduling
public class Quick3Application {

    public static void main(String[] args) {
        SpringApplication.run(Quick3Application.class, args);
    }

}


```


* 编写任务类  添加注解@Scheduled  每一秒执行定时任务

```java
package com.ustc.quartz;

import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@Component
public class MyTask {
    
    @Scheduled(cron = "0/1 * * * * ?")
    public void print(){
        System.out.println("打印定时任务");
    }
}


```

