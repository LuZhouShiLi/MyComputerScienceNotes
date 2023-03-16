# 相关的API介绍

## 加载核心配置文件 Resources

![图 1](../../images/d0f11d11916c7acff594c1860e4d59848b8f6d3335cfac9034cbcd45dbacb88f.png)  

```java
        // 加载核心配置文件  里面包含连接数据库的相关配置
        InputStream is = Resources.getResourceAsStream("MyBatisConfig.xml");// 获取配置文件的输入流对象
        
        // 原始的加载配置文件的方法
        InputStream resourceAsStream = Test01.class.getClassLoader().getResourceAsStream("MyBatisConfig.xml");

```

## 获取工厂对象的API-SqlSessionFactoryBuilder

![图 2](../../images/cdc814a2c969207efd48216c0869afbf5d12856cf0293170cb2abbe54232bea3.png)  

## 获取SqlSession对象

![图 3](../../images/5456478e222e9c5859363cf181e891c64cfb2a54534068fb3da352835e31da45.png)  

## SqlSession中的方法

![图 4](../../images/ccb41e3f2d4ac6d7d382ba8089424eb563078d0db604f67dfa25a08628515075.png)  

![图 5](../../images/4411ee182ee9666b28fc3ead4ee1dd74cafd9b45e969b2cd9251f58df476405c.png)  


