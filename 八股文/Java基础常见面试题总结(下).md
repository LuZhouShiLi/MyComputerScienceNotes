# Java基础常见面试题总结(下)

## Exception 和 Error 有什么区别？

* Exception :程序本身可以处理的异常，可以通过 catch 来进行捕获。Exception 又可以分为 Checked Exception (受检查异常，必须处理) 和 Unchecked Exception (不受检查异常，可以不处理)。
* Error：Error 属于程序无法处理的错误 ，我们没办法通过 catch 来进行捕获不建议通过catch捕获 。例如 Java 虚拟机运行错误（Virtual MachineError）、虚拟机内存不够错误(OutOfMemoryError)、类定义错误（NoClassDefFoundError）等 。这些异常发生时，Java 虚拟机（JVM）一般会选择线程终止


## Checked Exception 和 Unchecked Exception 有什么区别？


* Checked Exception 即 受检查异常 ，Java 代码在编译过程中，如果受检查异常没有被 catch或者throws 关键字处理的话，就没办法通过编译。
* 除了RuntimeException及其子类以外，其他的Exception类及其子类都属于受检查异常 。常见的受检查异常有：IO 相关的异常、ClassNotFoundException、SQLException...
* Unchecked Exception 即 不受检查异常 ，Java 代码在编译过程中 ，我们即使不处理不受检查异常也可以正常通过编译

## Throwable 类常用方法有哪些？

* String getMessage(): 返回异常发生时的简要描述String toString(): 返回异常发生时的详细信息String getLocalizedMessage(): 返回异常对象的本地化信息。
* 使用 Throwable 的子类覆盖这个方法，可以生成本地化信息。
* 如果子类没有覆盖该方法，则该方法返回的信息与 getMessage()返回的结果相同void printStackTrace(): 在控制台上打印 Throwable 对象封装的异常信息


## try-catch-finally 如何使用？


* try块：用于捕获异常。其后可接零个或多个 catch 块，如果没有 catch 块，则必须跟一个 finally 块。
* catch块：用于处理 try 捕获到的异常。
* finally 块：无论是否捕获或处理异常，finally 块里的语句都会被执行。当在 try 块或 catch 块中遇到 return 语句时，finally 语句块将在方法返回之前被执行。

* 不要在 finally 语句块中使用 return! 当 try 语句和 finally 语句中都有 return 语句时，try 语句块中的 return 语句会被忽略。这是因为 try 语句中的 return 返回值会先被暂存在一个本地变量中，当执行到 finally 语句中的 return 之后，这个本地变量的值就变为了 finally 语句中的 return 返回值。

## 泛型

### 什么是泛型？有什么作用？


* Java 泛型（Generics） 是 JDK 5 中引入的一个新特性。使用泛型参数，可以增强代码的可读性以及稳定性。

* 编译器可以对泛型参数进行检测，并且通过泛型参数可以指定传入的对象类型。比如 ArrayList<Person> persons = new ArrayList<Person>() 这行代码就指明了该 ArrayList 对象只能传入 Person 对象，如果传入其他类型的对象就会报错。


### 泛型的使用方式有哪几种？


* 泛型一般有三种使用方式:泛型类、泛型接口、泛型方法。

1.泛型类：

```java
//此处T可以随便写为任意标识，常见的如T、E、K、V等形式的参数常用于表示泛型
//在实例化泛型类时，必须指定T的具体类型
public class Generic<T>{

    private T key;

    public Generic(T key) {
        this.key = key;
    }

    public T getKey(){
        return key;
    }
}


Generic<Integer> genericInteger = new Generic<Integer>(123456);

```

2.泛型接口：


```java
public interface Generator<T> {
    public T method();
}

```

实现泛型接口，不指定类型：
```java
class GeneratorImpl<T> implements Generator<T>{
    @Override
    public T method() {
        return null;
    }
}

```
实现泛型接口，指定类型：

```java

class GeneratorImpl<T> implements Generator<String>{
    @Override
    public String method() {
        return "hello";
    }
}

```


3.泛型方法：

```java
   public static < E > void printArray( E[] inputArray )
   {
         for ( E element : inputArray ){
            System.out.printf( "%s ", element );
         }
         System.out.println();
    }


```

### 项目中哪里用到了泛型？


* 自定义接口通用返回结果 CommonResult<T> 通过参数 T 可根据具体的返回类型动态指定结果的数据类型
* 定义 Excel 处理类 ExcelUtil<T> 用于动态指定 Excel 导出的数据类型
* 构建集合工具类（参考 Collections 中的 sort, binarySearch 方法）


## 反射

### 何谓反射？

* 如果说大家研究过框架的底层原理或者咱们自己写过框架的话，一定对反射这个概念不陌生。反射之所以被称为框架的灵魂，主要是因为它赋予了我们在运行时分析类以及执行类中方法的能力。通过反射你可以获取任意一个类的所有属性和方法，你还可以调用这些方法和属性。



### 反射的优缺点？

反射可以让我们的代码更加灵活、为各种框架提供开箱即用的功能提供了便利。

不过，反射让我们在运行时有了分析操作类的能力的同时，也增加了安全问题，比如可以无视泛型参数的安全检查（泛型参数的安全检查发生在编译时）。另外，反射的性能也要稍差点，不过，对于框架来说实际是影响不大的。



### 反射的应用场景？

* 像咱们平时大部分时候都是在写业务代码，很少会接触到直接使用反射机制的场景。但是！这并不代表反射没有用。相反，正是因为反射，你才能这么轻松地使用各种框架。像 Spring/Spring Boot、MyBatis 等等框架中都大量使用了反射机制


* 这些框架中也大量使用了动态代理，而动态代理的实现也依赖反射
* 像 Java 中的一大利器 注解 的实现也用到了反射
  * 为什么你使用 Spring 的时候 ，一个@Component注解就声明了一个类为 Spring Bean 呢？
  * 为什么你通过一个 @Value注解就读取到配置文件中的值呢？究竟是怎么起作用的呢？这些都是因为你可以基于反射分析类，然后获取到类/属性/方法/方法的参数上的注解。你获取到注解之后，就可以做进一步的处理。

## 注解


### 何谓注解？

* Annotation （注解） 是 Java5 开始引入的新特性，可以看作是一种特殊的注释，主要用于修饰类、方法或者变量，提供某些信息供程序在编译或者运行时使用。

* 注解本质是一个继承了Annotation 的特殊接口：
* JDK 提供了很多内置的注解（比如 @Override、@Deprecated），同时，我们还可以自定义注解

### 注解的解析方法有哪几种？

* 注解只有被解析之后才会生效，常见的解析方法有两种：
* 编译期直接扫描：编译器在编译 Java 代码的时候扫描对应的注解并处理，比如某个方法使用@Override 注解，编译器在编译的时候就会检测当前的方法是否重写了父类对应的方法。运行期通过反射处理：像框架中自带的注解(比如 Spring 框架的 @Value、@Component)都是通过反射来进行处理的。










