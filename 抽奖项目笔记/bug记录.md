# 更换JDK


## 问题记录


```java
java: java.lang.IllegalAccessError: class lombok.javac.apt.LombokProcessor (in unnamed module @0x3278991b) cannot access class com.sun.tools.javac.processing.JavacProcessingEnvironment (in module jdk.compiler) because module jdk.compiler does not export com.sun.tools.javac.processing to unnamed module


```


## 问题原因



```java
lombok版本和jdk版本不匹配
```


## 解决办法-换掉JDK版本  换成1.8

**Ctrl + Alt + Shift + S快捷键打开Project Structure**

![图 0](../images/36072181f6ca1f4c5383bfc50be06cd351573d8a5b83986b81d620cde3da247d.png)  


