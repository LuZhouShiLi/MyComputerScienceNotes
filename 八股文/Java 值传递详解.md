# Java 值传递详解

## 形参&实参

* 实参（实际参数，Arguments）：用于传递给函数/方法的参数，必须有确定的值。
* 形参（形式参数，Parameters）：用于定义函数/方法，接收实参，不需要有确定的值。

## 值传递&引用传递


* 值传递：方法接收的是实参值的拷贝，会创建副本。
* 引用传递：方法接收的直接是实参所引用的对象在堆中的地址，不会创建副本，对形参的修改将影响到实参

## 为什么 Java 只有值传递？


### 传递基本应用参数类型

```java
public static void main(String[] args) {
    int num1 = 10;
    int num2 = 20;
    swap(num1, num2);
    System.out.println("num1 = " + num1);
    System.out.println("num2 = " + num2);
}

public static void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    System.out.println("a = " + a);
    System.out.println("b = " + b);
}


```

&emsp;在 swap() 方法中，a、b 的值进行交换，并不会影响到 num1、num2。因为，a、b 的值，只是从 num1、num2 的复制过来的。也就是说，a、b 相当于 num1、num2 的副本，副本的内容无论怎么修改，都不会影响到原件本身。




### 传递引用类型参数 1

**change 方法的参数拷贝的是 arr （实参）的地址，因此，它和 arr 指向的是同一个数组对象。这也就说明了为什么方法内部对形参的修改会影响到实参**

```java

  public static void main(String[] args) {
      int[] arr = { 1, 2, 3, 4, 5 };
      System.out.println(arr[0]);
      change(arr);
      System.out.println(arr[0]);
  }

  public static void change(int[] array) {
      // 将数组的第一个元素变为0
      array[0] = 0;
  }

```

### 传递引用类型参数 2


```java
public class Person {
    private String name;
   // 省略构造函数、Getter&Setter方法
}

public static void main(String[] args) {
    Person xiaoZhang = new Person("小张");
    Person xiaoLi = new Person("小李");
    swap(xiaoZhang, xiaoLi);
    System.out.println("xiaoZhang:" + xiaoZhang.getName());
    System.out.println("xiaoLi:" + xiaoLi.getName());
}

public static void swap(Person person1, Person person2) {
    Person temp = person1;
    person1 = person2;
    person2 = temp;
    System.out.println("person1:" + person1.getName());
    System.out.println("person2:" + person2.getName());
}


```


&emsp;swap 方法的参数 person1 和 person2 只是拷贝的实参 xiaoZhang 和 xiaoLi 的地址。因此， person1 和 person2 的互换只是拷贝的两个地址的互换罢了，并不会影响到实参 xiaoZhang 和 xiaoLi



## 总结


Java 中将实参传递给方法（或函数）的方式是 值传递：*
* 如果参数是基本类型的话，很简单，传递的就是基本类型的字面量值的拷贝，会创建副本。
* 如果参数是引用类型，传递的就是实参所引用的对象在堆中地址值的拷贝，同样也会创建副本。


