# 监听器

## 概述

![图 1](../images/8c96d4cc766c6bacf60839d4480a953256aca0477c577d53b5e10a5b64d2fd45.png)  

![图 2](../images/e55aec741661d4254cd88c4f358dc7849a23086b3a3a790de35edd0b417a7a17.png)  


## 监听对象的监听器

![图 3](../images/8ea0f320fa486687f7053c39e360537fe049acea488d5f7f2ce26f6037830e4e.png)  

![图 4](../images/2421e09c6adec8c1cf82746ce19ac916d062851ffa5918493e7540df21a0ca1f.png)  

![图 5](../images/7b4c08dcb7be786c2bf1aabf5e618e26e6ccfb62caa6c10a3ae693a2e926c808.png)  

## 监听域对象属性变化的监听器

![图 7](../images/6a390d79cc10c37dc19c83af0447a2ecd9aec14aaaa803b318b454ecb82ab6e8.png)  

![图 8](../images/1d1bd77b465405b022b4ab34641290f14aae4fe4ba901ba3163ede4a519bf54a.png)  

![图 9](../images/ddd2fd2c7385792e3160165bbd2a3c49e38811026f121a8bcd88c69d78e4c918.png)  

## 监听会话的感知型监听器

![图 10](../images/d1759f7068a8a1d96df69f003a40d10f5871afc9a4fd15a8c344f93a16ed3845.png)  

![图 11](../images/c1d88e1f46e80a009e83a46b0c626fe2efdd18784bd2c5d364245d777ded28f0.png)  

## 监听器的使用

* ServletContextListener
```java
package com.hfut.filter;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

@WebListener
public class ServletContextListenerDemo implements ServletContextListener {
    @Override
    public void contextInitialized(ServletContextEvent servletContextEvent) {
        // servletContext对象被创建的时候 执行该方法
        System.out.println("ServletContext对象被创建");

        // 获取对象  使用事件对象获取事件
        ServletContext servletContext = servletContextEvent.getServletContext();
        System.out.println(servletContext);
    }

    @Override
    public void contextDestroyed(ServletContextEvent servletContextEvent) {
        System.out.println("监听到对象的销毁");
    }
}
```

* ServletContextAttributeListener

```java
package com.hfut.filter;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextAttributeEvent;
import javax.servlet.ServletContextAttributeListener;
import javax.servlet.annotation.WebListener;

@WebListener
public class ServletContextAttributeListenerDemo implements ServletContextAttributeListener {
    @Override
    public void attributeAdded(ServletContextAttributeEvent servletContextAttributeEvent) {
        System.out.println("监听到属性的添加");
        
        // 获取应用域对象
        ServletContext servletContext = servletContextAttributeEvent.getServletContext();
        // 获取属性值
        Object username = servletContext.getAttribute("username");
        System.out.println(username);


    }

    @Override
    public void attributeRemoved(ServletContextAttributeEvent servletContextAttributeEvent) {

    }

    @Override
    public void attributeReplaced(ServletContextAttributeEvent servletContextAttributeEvent) {
        System.out.println("监听到树型的替换");

        // 获取应用域对象
        ServletContext servletContext = servletContextAttributeEvent.getServletContext();
        // 获取属性值
        Object username = servletContext.getAttribute("username");
        System.out.println(username);
    }
}
```


