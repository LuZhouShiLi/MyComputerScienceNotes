# SpringBoot运维使用篇

## 打包

**将程序打包成jar包，然后使用 java -jar 程序包名  运行程序**

**打包的jar包一般放在服务器上运行**


![图 2](../images/42bb7ebe50fe8874458dd7b990cbc67807943ba16d6a7d358ab56dcd9ef781fb.png)  

**打包之前先进行clean操作，然后执行Install操作**


* mvn package
* java -jar springboot.jar

## windows端口被占用

![图 3](../images/001bc74032b86683551cf1f8bd901193ce3f72aff5310f73ea8a407ea75bcc99.png)  


## 运行Jar包指定配置属性

**指定端口临时属性：java -jar xxx.jar --server.port=8080**

**命令行的配置属性覆盖文件中的配置属性**

![图 4](../images/d98553585aa3ce0afa097bc31feb794df074e621a6f72a4881e3c9b030096148.png)  



## 可以在主程序入口添加属性

![图 5](../images/0f2507d6d1846e227ee749aeffb16b2b6b9615c141435fe49ad8460f8cfa923c.png)  

```java
package com.itheima;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.Arrays;

@SpringBootApplication
public class SSMPApplication {

    public static void main(String[] args) {
        // args是运行自行配置的参数
        String[] arg = new String[1];
        arg[0] = "--server.port=8080";
//        System.out.println(Arrays.toString(args));

        SpringApplication.run(SSMPApplication.class, arg);
    }

}
```


## 配置文件优先级

**在resources下面添加config文件夹，下面添加yml配置文件，改yml配置文件的优先级高于原先的配置文件**

**config下面的yml文件是用来项目上线进行使用的，当打包成jar包之后，运行的端口是改配置文件下面的端口**

![图 6](../images/bb992bc7849b669dd9a0b8b87d1c2c425b8437fb1a9814f98163637f3f0f6af8.png)  



