# Java代理模式


**代理模式就是使用代理对象来代替对真实对象的访问，这样就可以在不修改原目标对象的前提下，提供额外的功能操作，扩展目标对象的功能**


## 三种角色

* 真实类：就是被代理类，委托类，用来真正完成业务服务功能
* 代理类：将自身的请求用真实类对应的功能来实现，代理类对象并不真正实现业务功能
* Subject:定义真实类和代理类都应该实现的接口


**简单的来说，代理模式的主要作用就是扩展目标对象的功能，比如在目标对象的某个方法执行前后你可以增加一些额外的操作，并且不用修改方法的源代码**

**通过代理类这个中间层，很好地隐藏和保护委托类的对象，能有效屏蔽外界对委托类的直接访问，也可以在委托类加上额外的操作**

## 静态代理

&emsp;Java代理模式是一种设计模式，它为其他对象提供一个代理来控制对这个对象的访问，代理模式在Java开发中广泛使用，尤其是远程方法调用RMI，事务管理，延迟初始化等场景，代理模式主要分为静态代理和动态代理两种形式

* 静态代理在编译时就已经确定了代理类和目标对象的关系。
* 使用静态代理，需要为每一个被代理的类手动创建一个代理类，代理类需要实现与目标对象相同的接口，并在内部维护一个目标对象的引用，通过代理类对目标对象方法进行增强，首先额外的功能
* 步骤：
  * 定义接口：确定目标对象和代理对象共同遵循的接口
  * 实现接口：目标对象实现接口的方法
  * 创建代理类：代理类同样实现该接口，并在内部维护一个对象实际目标对象的引用，通过构造方法传入目标对象，代理类在实现接口方法的时候，可以在调用目标对象的方法前后添加额外的处理逻辑

## 静态代理的实现方式

1）定义一个接口（Subject）

2）创建一个委托类（Real Subject）实现这个接口

3）创建一个代理类（Proxy）同样实现这个接口

4) 将委托类注入进代理类Proxy,在代理类的方法中调用Real Subject 中的对应方法，这样的话就可以通过代理类屏蔽对目标对象的访问，并且可以在目标方法执行前后做自己想做的事情

* 静态代理中，我们对目标对象的每一个方法的增强都是手动完成的，不够灵活
* 从JVM层面来说，静态代理在编译的时候，将接口，委托类代理类这些文件都变成字节码文件


## 静态代理实例


* interface
```java
public interface SmsService {
    String send(String message);
}

```


* 委托类  实现该接口
```java

public class SmsServiceImpl implements SmsService {
    public String send(String message) {
        System.out.println("send message:" + message);
        return message;
    }
}
```

* 创建一个代理类Proxy 同样实现该接口
* 将委托类Real Subject 注入进入代理类Proxy，在代理类的方法中调用Real Subject 中的对应方法 ，这样就可以通过代理类屏蔽对目标对象的访问，并且可以在目标方法执行前后做一些自己想做的事情，


```java
public class SmsProxy implements SmsService {
    
    // 将委托类注入进代理类
    private final SmsService smsService;
​
    public SmsProxy(SmsService smsService) {
        this.smsService = smsService;
    }
​
    @Override
    public String send(String message) {
        // 调用委托类方法之前，我们可以添加自己的操作
        System.out.println("before method send()");
        // 调用委托类方法
        smsService.send(message); 
        // 调用委托类方法之后，我们同样可以添加自己的操作
        System.out.println("after method send()");
        return null;
    }
}

```

* 如何使用被增强的send方法: 首先初始化SmsServiceImpl委托类对象 然后初始化注入代理类对象中，之后调用方法

```java
 public class Main {
    public static void main(String[] args) {
        SmsService smsService = new SmsServiceImpl();
        SmsProxy smsProxy = new SmsProxy(smsService);
        smsProxy.send("Java");
    }
}

```


* 弊端：
  * 新增一个委托类，实现了SmsService接口，如果我们想要对这个委托类进行增强，就需要重写一个代理类，然后注入这个新的委托类，不够灵活



## 动态代理


### 概述

**静态代理中，委托类不同，导致代理类不同，那么将委托类的方法抽取出来，封装成一个通用的处理类**

**那么在代理类和委托类之间就多了一个处理类的角色，这个角色是对代理类调用委托类方法的这个动作进行统一的调用，也就是通过InvocationHandler来统一处理代理类调用委托类方法这个操作**

**从JVM角度来说，动态代理是在运行的时候生成.class字节码文件，并且加载到JVM中**

### JDK动态代理机制


* 定义一个接口Subject
* 创建一个委托类: Real Subject 实现这个接口
* 创建一个处理类并且实现InvocationHandler 接口 重写invoke方法  利用反射机制调用委托类的方法 并且自定义一些处理逻辑，并将委托类注入处理类

* Subject 接口

```java

public interface SmsService {
    String send(String message);
}
```


* 委托类 Real Subject
```java

public class SmsServiceImpl implements SmsService {
    public String send(String message) {
        System.out.println("send message:" + message);
        return message;
    }
}
```

* 创建一个处理类并且实现InvocationHandler接口  重写其invoke方法 （在invoke方法使用反射机制调用委托类的方法 自定义一些处理逻辑） 将委托类注入处理类


```java

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
​
public class DebugInvocationHandler implements InvocationHandler {
    
    // 将委托类注入处理类（这里我们用 Object 代替，方便扩展）
    private final Object target;
​
    public DebugInvocationHandler(Object target) {
        this.target = target;
    }
    
    // 重写 invoke 方法
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws InvocationTargetException, IllegalAccessException {
        //调用方法之前，我们可以添加自己的操作
        System.out.println("before method " + method.getName());
        Object result = method.invoke(target, args);
        //调用方法之后，我们同样可以添加自己的操作
        System.out.println("after method " + method.getName());
        return result;
    }
}
```


* 创建一个代理对象Proxy的工厂类：通过Proxy.newProxyInstance() 创建委托类对象的代理对象
* 第一个参数是 类加载器  用于定义动态生成的代理类，通常是目标对象（被代理的实例）的累加载器，类加载器的作用是将.class文件加载到JVM中，转换为Class对象
* 第二个参数接口数组： 代理类需要实现的接口列表，通过getInterfaces获取目标对象实现的接口
* DebugInvocationHandler是自定义的调用处理程序，拦截对代理对象的所有方法调用 转发给目标对象 同时允许在调用目标方法前后执行自定义逻辑
```java
 public class JdkProxyFactory {
    public static Object getProxy(Object target) {
        return Proxy.newProxyInstance(
                target.getClass().getClassLoader(),
                target.getClass().getInterfaces(),
                new DebugInvocationHandler(target)
        );
    }
}

```

* 实际使用
```java
SmsService smsService = (SmsService) JdkProxyFactory.getProxy(new SmsServiceImpl());
smsService.send("Java");

```


* 与静态代理，动态代理在运行的时候动态生成代理类和对象
* Java提供了两种动态代理：基于接口的动态代理和基于类的动态代理
* 基于接口的动态代理：
  * 创建一个实现了InvocationHandler接口的处理器类：该处理器类关联了真实对象，实现了invoke方法，invoke方法中封装了对真实对象方法的调用
  * 通过Proxy.newProxyInstance方法动态创建代理对象：这个方法需要加载真实对象的类加载器、真实对象实现的接口及上一步创建的处理器对象，返回一个实现了指定接口的代理实例
* 基于类的动态代理：
  * CGLIB（Code Generation Library）是一个第三方代码生成库，通过继承的方式实现动态代理，因此不需要接口。它在运行时动态生成被代理对象的子类，并在子类中重写父类方法，通过方法拦截技术插入增强代码


## 静态代理的步骤

* 定义一个接口：确定代理和真实对象的共同行为
* 实现该接口创建真实对象：具体实现接口的功能
* 创建一个代理类也实现这个接口：用来包装真实对象，同时在调用真实对象的方法前后，可以添加自己的操作
* 在代理类中维护一个真实对象的引用，通过构造方法传入真实对象
* 调用接口的方法，实际上执行的是代理类的方法

## 动态代理的步骤

* 定义一个或者多个接口以及实现类
* 创建一个实现InvocationHandler接口的类，他必须实现invoke方法
* 通过调用Proxy.newProxyInstance 方法 创建动态代理对象：
  * 类加载器（可以从已经加载的对象中获取）
  * 代理需要实现的接口列表（至少需要实现一个接口）
  * InvocationHandler 实例




