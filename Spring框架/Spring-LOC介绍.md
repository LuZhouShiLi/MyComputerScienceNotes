# Spring-LOC介绍


## 概念

![图 1](../images/7b63cf5679d1513c9f1a155307f583b238c669b5c123d8439bc17cce78ff2e50.png)  


## 体系结构

![图 2](../images/4f9641b76522605db691a49ed035a8fe6cd979e57d6a6d539f01f109c971a8c2.png)  


## loc介绍

![图 3](../images/05d76f9dad24bba031101122a42bb6be91ee2946af47c565fc8b216c789ea92c.png)  

## loc简单案例


![图 4](../images/f821d7c608a05590cbf508ab23dd20595c47e6b6ed5c8c62567205842e46a390.png)  


### 导入spring坐标

**将下面的依赖添加到pom.xml中，spring版本**

```xml
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-context</artifactId>
            <version>5.1.9.RELEASE</version>
        </dependency>

```

### 添加实现类

* 创建接口


```JAVA
package com.itheima.service;

public interface UserService {
    public void save();
}

```

* 创建实现类

```java
package com.itheima.service.impl;

import com.itheima.service.UserService;

public class UserServiceImpl implements UserService {
    @Override
    public void save() {
        System.out.println("测试spring框架");
    }
}


```

### 创建SpringContext.xml

```
https://docs.spring.io/spring-framework/docs/5.1.9.RELEASE/spring-framework-reference/core.html#spring-core

```
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
</beans>

```

### 创建spring控制的资源

**id是接口名称，class是实现类路径**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl"/>


</beans>

```

### 编写主方法

```java
import com.itheima.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class UserApp {
    public static void main(String[] args) {
        // 加载配置文件
        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");

        // 获取资源
        UserService userService = (UserService) ctx.getBean("userService");// 强制转换接口

        userService.save();//
    }
}


```


## bean的配置

![图 1](../images/266f9811b69642c8ae0e89b089a06676972e9085840c4825746d1f6118e8aa47.png)  


```java
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
    <bean id = "userService" name = "userService1,userService2" class = "com.itheima.service.impl.UserServiceImpl"/>

</beans>

```


## bean属性-scope


![图 2](../images/00d41994bb2728a3922afcabba5b41fa6d4e87909b7abd0ca8f6ca16191dd7dc.png)  

**主要用来控制创建的对象是不是单例的**

**比如singleton创建的对象就是单例的**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
    <bean id = "userService" scope = "singleton" name = "userService1,userService2" class = "com.itheima.service.impl.UserServiceImpl"/>

</beans>

```


```java
import com.itheima.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class UserApp {
    public static void main(String[] args) {
        // 加载配置文件
        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");

        // 获取资源
        UserService userService3 = (UserService) ctx.getBean("userService");// 强制转换接口
        UserService userService1 = (UserService) ctx.getBean("userService");// 强制转换接口
        UserService userService2 = (UserService) ctx.getBean("userService");// 强制转换接口

        System.out.println(userService2 == userService1);// 创建的是单例对象

//        userService.save();//
    }
}


```


## bean的声明周期

![图 4](../images/84926d771071ce7fb4685b5cb61aa98056e38df7f41987b4be4c3c4a66e6f80d.png)  


```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
    <bean id = "userService" scope = "singleton" init-method="init" destroy-method="destroy" name = "userService1,userService2" class = "com.itheima.service.impl.UserServiceImpl"/>

</beans>

```

```java
import com.itheima.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class UserApp {
    public static void main(String[] args) {
        // 加载配置文件
        ClassPathXmlApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");

        // 获取资源
        UserService userService3 = (UserService) ctx.getBean("userService");// 强制转换接口
        UserService userService1 = (UserService) ctx.getBean("userService");// 强制转换接口
        UserService userService2 = (UserService) ctx.getBean("userService");// 强制转换接口

//        System.out.println(userService2 == userService1);// 创建的是单例对象
        ctx.close();

//        userService.save();//
    }
}


```

## bean-静态工厂与实例工厂创建

![图 5](../images/d62f6bf4c846dbe3915abbb0041fe179f545f2414931d05a171ac30449ef6816.png)  


### 创建静态工厂

```java
package com.itheima.service;
import com.itheima.service.impl.UserServiceImpl;

// 创建静态工厂类
public class UserServiceFactory {

    // 多态  父类指向子类对象
    public static UserService  getService(){
        return new UserServiceImpl();// 返回一个实现类 对象
    }
}


```

**更改配置文件**

```java
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
    <bean id = "userService"  class = "com.itheima.service.UserServiceFactory" factory-method="getService"/>

</beans>
```

**现在这种资源的创建与调用 走的是工厂类的创建**


### 创建实例 工厂

**更改配置文件**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
<!--    <bean id = "userService"  class = "com.itheima.service.UserServiceFactory" factory-method="getService"/>-->
<!--     实例化工厂对象-->
    <bean id = "factoryBean" class = "com.itheima.service.UserServiceFactory"/>
    <bean id = "userService" factory-bean="factoryBean"  factory-method="getService" />

</beans>

```


```java
package com.itheima.service;
import com.itheima.service.impl.UserServiceImpl;

// 创建静态工厂类
public class UserServiceFactory {

    // 多态  父类指向子类对象
    // 实例工厂对象 去掉static
    public UserService  getService(){
        System.out.println("实例工厂创建出来的对象");
        return new UserServiceImpl();// 返回一个实现类 对象
    }
}


```

## DI-依赖注入


![图 6](../images/78d9b9956403b0525d110ea47d5cf77238da261de84708617978888ab7a85615.png)  


### set注入

![图 7](../images/9e0bf472c3f30dd4ef48e918f2259c4657fda073725c0acccbf7039353d9f32e.png)  


#### 注入引用类型资源

* UserDao接口
```java
package com.itheima.dao;

public interface UserDao {
    public void save();
}


```

* UserDao接口实现类

```java
package com.itheima.dao.impl;

import com.itheima.dao.UserDao;

public class UserDaoImpl implements UserDao {
    @Override
    public void save() {
        System.out.println("set注入");
    }
}


```

* UserServiceImpl

```java
package com.itheima.service.impl;

import com.itheima.dao.UserDao;
import com.itheima.service.UserService;

public class UserServiceImpl implements UserService {

    private UserDao userDao;

    // 使用set注入
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    // 初始化函数
    public void init(){
        System.out.println("init...");
    }

    public void destroy(){
        System.out.println("销毁bean...");
    }

    @Override
    public void save() {
        System.out.println("使用userDao调用操作");
        userDao.save();// 使用set注入的资源
    }
}

```

* applicationContext.xml


```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">
<!--    创建spring控制的资源-->
<!--    <bean id = "userService"  class = "com.itheima.service.UserServiceFactory" />-->
<!--     实例化工厂对象-->
<!--    <bean id = "factoryBean" class = "com.itheima.service.UserServiceFactory"/>-->
<!--    -->
<!--    <bean id = "userService" factory-bean="factoryBean"  factory-method="getService" />-->

    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl">
<!--        将要注入的引用类型的变量通过property属性进行注入  对应的name是要注入的变量  ref 是注入资源的Id-->
        <property name="userDao" ref="userDao"/>
    </bean>

<!--    将要注入的资源声明为bean-->
    <bean id = "userDao" class = "com.itheima.dao.impl.UserDaoImpl"/>

</beans>

```

#### 非引用类型资源的注入

* 还是需要创建set方法获取 对象
```java
package com.itheima.service.impl;

import com.itheima.dao.UserDao;
import com.itheima.service.UserService;

public class UserServiceImpl implements UserService {

    private UserDao userDao;

    private int num;

    public void setNum(int num) {
        this.num = num;
    }

    // 使用set注入
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    // 初始化函数
    public void init(){
        System.out.println("init...");
    }

    public void destroy(){
        System.out.println("销毁bean...");
    }

    @Override
    public void save() {
        System.out.println("使用userDao调用操作");
        userDao.save();// 使用set注入的资源
    }
}


```


* applicationContext.xml

```java
package com.itheima.service.impl;

import com.itheima.dao.UserDao;
import com.itheima.service.UserService;

public class UserServiceImpl implements UserService {

    private UserDao userDao;

    private int num;

    public void setNum(int num) {
        this.num = num;
    }

    // 使用set注入
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    // 初始化函数
    public void init(){
        System.out.println("init...");
    }

    public void destroy(){
        System.out.println("销毁bean...");
    }

    @Override
    public void save() {
        System.out.println("使用userDao调用操作" + num);
        userDao.save();// 使用set注入的资源
    }
}


```


### 构造方法注入资源

![图 8](../images/9701bbfdba4246a834868877362d4256a0a5cdcea561e2506963c91419c0a429.png)  


```xml
<!--        构造方法注入资源-->
<!--    将要注入的资源封装成bean-->
    <bean id = "userDao" class = "com.itheima.dao.impl.UserDaoImpl"/>

    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl">
        <constructor-arg ref = "userDao"/>
    </bean>
```

## 读取properties文件信息

**使用读取到的数据给bean属性赋值**

![图 12](../images/adfd92acf44da85d9f41969cde3cc4b5cda550ff3e6e547a1c4f36008c8154c6.png)  


### 原始的set注入方法

```xml
<!--    将要注入的资源封装成Bean-->
    <bean id = "userDao" class = "com.itheima.dao.impl.UserDaoImpl"/>
    <bean id = "bookDao" class = "com.itheima.dao.impl.BookDaoImpl"/>

<!--    ref 是注入资源的id属性  name是变量名-->
    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl">
        <property name="userDao" ref = "userDao"/>
        <property name="bookDao" ref = "bookDao"/>
    </bean>

```

### 读取配置文件进行注入资源

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:p="http://www.springframework.org/schema/p"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context
        https://www.springframework.org/schema/context/spring-context.xsd">

    <!--   加载配置文件-->
    <context:property-placeholder location="classpath:data.properties"/>

<!--    将要注入的资源封装成Bean-->
<!--    同时userDao 和bookDao中有些属性也需要外部注入资源  读取properties中的两个变量名  赋值给value-->
    <bean id = "userDao" class = "com.itheima.dao.impl.UserDaoImpl">
        <property name="userName" value = "${username}"/>
        <property name="password" value = "${pwd}"/>
    </bean>


    <bean id = "bookDao" class = "com.itheima.dao.impl.BookDaoImpl"/>

<!--    ref 是注入资源的id属性 主要是针对引用类型资源  如果是非引用 直接value  name是变量名-->
    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl">
        <property name="userDao" ref = "userDao"/>
        <property name="bookDao" ref = "bookDao"/>
    </bean>
</beans>

```

## import导入配置文件


**当团队协作的时候,xml文件过多可以配置多个xml文件，最后进行导入**

![图 13](../images/c32dd9daa39505439fa8d3520cd96202ecca360c3b91e623a7bb0db17f47b544.png)  

### applicationContext.xml

**该配置文件需要使用userDao和bookDao的资源**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:p="http://www.springframework.org/schema/p"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context
        https://www.springframework.org/schema/context/spring-context.xsd">

    <!--   加载配置文件-->
    <context:property-placeholder location="classpath:data.properties"/>

<!--    将要注入的资源封装成Bean-->
<!--    同时userDao 和bookDao中有些属性也需要外部注入资源  读取properties中的两个变量名  赋值给value-->
<!--    <bean id = "userDao" class = "com.itheima.dao.impl.UserDaoImpl">-->
<!--        <property name="userName" value = "${username}"/>-->
<!--        <property name="password" value = "${pwd}"/>-->
<!--    </bean>-->

<!--    <bean id = "bookDao" class = "com.itheima.dao.impl.BookDaoImpl"/>-->

<!--&lt;!&ndash;    ref 是注入资源的id属性 主要是针对引用类型资源  如果是非引用 直接value  name是变量名&ndash;&gt;-->
<!--    <bean id = "userService" class = "com.itheima.service.impl.UserServiceImpl">-->
<!--        <property name="userDao" ref = "userDao"/>-->
<!--        <property name="bookDao" ref = "bookDao"/>-->
<!--    </bean>-->

<!--    将其余的配置文件导入进来-->
        <import resource="applicationContext-user.xml"/>
        <import resource="applicationContext-book.xml"/>


<!--    &lt;!&ndash;2.加载配置文件&ndash;&gt;-->
<!--    <context:property-placeholder location="classpath:*.properties"/>-->

<!--    <bean id="userDao" class="com.itheima.dao.impl.UserDaoImpl">-->
<!--        <property name="userName" value="${username}"/>-->
<!--        <property name="password" value="${pwd}"/>-->
<!--    </bean>-->

<!--    <bean id="bookDao" class="com.itheima.dao.impl.BookDaoImpl"/>-->

<!--    <bean id="userService" class="com.itheima.service.impl.UserServiceImpl">-->
<!--        <property name="userDao" ref="userDao"/>-->
<!--        <property name="bookDao" ref="bookDao"/>-->
<!--    </bean>-->

<!--    <import resource="applicationContext-user.xml"/>-->
<!--    <import resource="applicationContext-book2.xml"/>-->
<!--    <import resource="applicationContext-book.xml"/>-->

<!--    <bean id="bookDao" class="com.itheima.dao.impl.BookDaoImpl">-->
<!--        <property name="num" value="3"/>-->
<!--    </bean>-->


<!--    <bean id="dataSource" class="com.alibaba.druid.pool.DruidDataSource">-->
<!--        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>-->
<!--        <property name="url" value="jdbc:mysql://localhost:3306/spring_db"/>-->
<!--        <property name="username" value="root"/>-->
<!--        <property name="password" value="itheima"/>-->
<!--    </bean>-->


</beans>

```


### ### applicationContext-user.xml


```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:p="http://www.springframework.org/schema/p"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context
        https://www.springframework.org/schema/context/spring-context.xsd">

    <bean id="userDao" class="com.itheima.dao.impl.UserDaoImpl">
        <property name="userName" value="${username}"/>
        <property name="password" value="${pwd}"/>
    </bean>

    <bean id="userService" class="com.itheima.service.impl.UserServiceImpl">
        <property name="userDao" ref="userDao"/>
    </bean>

</beans>
```

### ### applicationContext-book.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:p="http://www.springframework.org/schema/p"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context
        https://www.springframework.org/schema/context/spring-context.xsd">

    <bean id="bookDao" class="com.itheima.dao.impl.BookDaoImpl">
<!--        name是变量名  value属性直接注入-->
        <property name="num" value="1"/>
    </bean>
    <bean id="userService" class="com.itheima.service.impl.UserServiceImpl">
        <property name="bookDao" ref="bookDao"/>
    </bean>
</beans>

```

## 第三方bean配置

**阿里数据源druid**


### 首先在pom.xml 导入依赖

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.itheima</groupId>
    <artifactId>Spring_day01_04_实用开发相关配置</artifactId>
    <version>1.0-SNAPSHOT</version>

    <dependencies>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-context</artifactId>
            <version>5.1.9.RELEASE</version>
        </dependency>
        <dependency>
            <groupId>com.alibaba</groupId>
            <artifactId>druid</artifactId>
            <version>1.1.16</version>
        </dependency>

<!--        <dependency>-->
<!--            <groupId>com.alibaba</groupId>-->
<!--            <artifactId>druid</artifactId>-->
<!--            <version>1.1.16</version>-->
<!--        </dependency>-->
    </dependencies>
</project>

```

### applicationContext.xml中配置资源

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:p="http://www.springframework.org/schema/p"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context
        https://www.springframework.org/schema/context/spring-context.xsd">

    <!--   加载配置文件-->
    <!-- <context:property-placeholder location="classpath:data.properties"/> -->

    <bean id = "dataSource" class = "com.alibaba.druid.pool.DruidDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value = "jdbc:mysql://localhost:3306/kob"/>
        <property name="username" value="root"/>
        <property name="password" value="123456"/>
    </bean>

</beans>

```




