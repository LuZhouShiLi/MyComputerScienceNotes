# SpringBoot配置

## 配置文件分类

<!-- 内容分为 自动配置 还有用户自定义的内容 -->

![图 1](../images/b2ce79777f940a0f32d52d33ffa6094fa356035d48d41fd4bbff5ea345ff4281.png)  

![图 2](../images/fb4418b2f7f0e24c66f0d775065b0a49684d4fc5a507b594d62d84916780af9b.png)  

## YAML基本语法

![图 3](../images/7726df39f2c28fd8c28249dd52bb4014693282e68cfd5d381faf2bc12bdba71b.png)  

![图 4](../images/0e7db01b72663b585936156a695c673c3673988a93391e2d43cb3277871a87d7.png)  

数据格式

![图 5](../images/61c86183938cd9babc68b941ea6dbb1e125b386d452cef435ffed4e071158cac.png)  

## 读取配置文件的内容


* @Value


**注入properties文件中的单个的值**

```java
package com.itheima.controller;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// 定义controller层
@RestController
public class HelloController {

    // 注入数组资源
    @Value("${address[0]")
    private String address1;// 注入数组资源


//     注入对象的属性
    @Value("${person.name")
    private String name2;

    @RequestMapping("/hello3")
//    @RequestMapping("/hello2")
    public String hello3(){
        System.out.println(name2);// 打印name
        System.out.println(address1);
        return "hello Spring boot1112222222222";
    }

    // 使用注解 将properties文件将资源导入
    @Value("${name}")
    private String name;

    @RequestMapping("/hello2")
    public String hello2(){
        System.out.println(name);// 打印name
        return "hello Spring boot111";
    }

    // 定义 资源访问路径
    @RequestMapping("/hello")
    public String hello(){
        return "hello Spring boot";
    }
}
```



* Environment

```java
package com.itheima.controller;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.env.Environment;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// 定义controller层
@RestController
public class HelloController {


    @Autowired
    private Environment env;// 注入环境资源

    // 注入数组资源
    @Value("${address[0]")
    private String address1;// 注入数组资源


//     注入对象的属性
    @Value("${person.name")
    private String name2;

    @RequestMapping("/hello3")
//    @RequestMapping("/hello2")
    public String hello3(){
        System.out.println(name2);// 打印name
        System.out.println(address1);

        System.out.println("------------------------------");

        System.out.println(env.getProperty("person.name"));
        System.out.println(env.getProperty("address[0]"));


        return "hello Spring boot1112222222222";
    }

    // 使用注解 将properties文件将资源导入
    @Value("${name}")
    private String name;

    @RequestMapping("/hello2")
    public String hello2(){
        System.out.println(name);// 打印name
        return "hello Spring boot111";
    }

    // 定义 资源访问路径
    @RequestMapping("/hello")
    public String hello(){
        return "hello Spring boot";
    }
}


```


* @ConfigurationProperties

**使用该注解提供pojo类的资源注入**
Person类

```
package com.itheima;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;


// 注入name  age属性
// 自定义bean资源组件
@Component
@ConfigurationProperties(prefix = "person")
public class Person {

    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}


```


Controller


```java
package com.itheima.controller;
import com.itheima.Person;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.env.Environment;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// 定义controller层
@RestController
public class HelloController {
    @Autowired
    private Person person;// 注入Person资源  使用properties资源  创建person对象

    @Autowired
    private Environment env;// 注入环境资源

    // 注入数组资源
    @Value("${address[0]")
    private String address1;// 注入数组资源


//     注入对象的属性
    @Value("${person.name")
    private String name2;

    @RequestMapping("/hello3")
//    @RequestMapping("/hello2")
    public String hello3(){
        System.out.println(name2);// 打印name
        System.out.println(address1);

        System.out.println("------------------------------");

        System.out.println(env.getProperty("person.name"));
        System.out.println(env.getProperty("address[0]"));


        System.out.println("---------------------------------");
        System.out.println(person);


        return "hello Spring boot1112222222222";
    }

    // 使用注解 将properties文件将资源导入
    @Value("${name}")
    private String name;

    @RequestMapping("/hello2")
    public String hello2(){
        System.out.println(name);// 打印name
        return "hello Spring boot111";
    }

    // 定义 资源访问路径
    @RequestMapping("/hello")
    public String hello(){
        return "hello Spring boot";
    }
}


```

## Profile文件配置

![图 6](../images/fec7c5c62b565bf02b15ede9f21f38d3ad9482b3ec769e4b3e3924f11e976999.png)  

**创建另一个properties文件，里面填写端口号**

![图 7](../images/1deac0eb276a033f4030459ebcf69f238e6a9a64fd96fd945369037a4d072c9a.png)  

**在application.properties文件中引入该properties文件**

![图 8](../images/0ff043926ac1a28ab6d9e38fd6f1c6933cb65efb0b09f6486509becf621bd95d.png)  


## 内部配置的加载顺序

![图 9](../images/fe2ad226dfe61c58ee907ffd15dedc459b18e55c9dde3cdd8c6a9987dbebe9b7.png)  





