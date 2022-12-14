# C语言基础Day3-运算符

## 一、运算符

* 算术运算符：用于处理四则运算
* 赋值运算符：用于将表达式的值赋给变量
* 比较运算符：用于表达式的比较，并返回一个真值或者假值
* 逻辑运算符：用于根据表达式的值返回真值或者假值
* 位运算符：用于处理数据的位运算
* sizeof运算符：用于求字节数长度

```cpp
	int a = 10;
	int b = 20;

	// 两个整数相除，如果要得到小数，必须有一个是double类型或者float类型（强制类型转换）
	double f = a * 1.0 / b;// a * 1.0 将转换成double类型
	printf("%lf\n",f);
```

使用取余运算符求出一个数字的个位、十位、百位：

```cpp
int num = 1234;
	int a = num % 10;// 个位
	int b = num / 10 % 10;// 十位
	int c = num / 100 % 10;// 百位
	int d = num / 1000 % 10;// 千位

	printf("%d %d %d %d\n",a,b,c,d);

```

## 二、自加或者自减运算符

* a++ ++在后，先使用 在a = a + 1
* ++a ++在前，先a = a+1,在使用

## 三、短路求值

* A || B A或者B只要有一个是真，整个表达式就是真，那么如果A是真，B表达式就不执行
* A && B A和B必须同时为真，总的结果就是真，如果A是假的，那么整个表达式就是假的，B表达式就不执行

## 四、运算符优先级

![图 1](../../images/843f8786535bc6ff4ae52d985f0339d800cca9ab39d55e684ec716792e836898.png)  
![图 2](../../images/32ccf3bc2d9c422bfb5c6bd7a293636cc1b3d0366f4648e7a2487c5b60a3629a.png)  
![![图 2](../../images/32ccf3bc2d9c422bfb5c6bd7a293636cc1b3d0366f4648e7a2487c5b60a3629a.png)  
 1](../../images/e5046c843d1e60a51eadd36d32cb1138cf2525209d197f8451a853149ba8d078.png)  
![图 4](../../images/bdb6a2e02afae43e352121d64a52fe34893fb0cdb7d0b916dc3a65d68808eaa2.png)  
![图 5](../../images/1f01f2fff5f9458c8f9c8dce483d7b4a66a35e3f2ac017d22bcfb50bc63f99ec.png)  

```cpp
	int a1 = 1;
	int b1 = 2;
	int e = (a1++, b1++, a1 + b1, 10, 200, a1 + b1);// 逗号运算符  最终的结果是最后一个表达式的结果
	printf("%d\n",e);

```


## 五、类型转换

&emsp;数据有不同的类型，不同类型数据之间进行混合运算时必定会涉及到类型的转换问题。

转换的方法有两种：
* 自动转换（隐式转换）：遵循一定的规则，由编译系统自动完成
* 强制类型转换：把表达式的运算结果强制转换成所需的数据类型


类型转换的原则：占用字节数少的类型，向占用内存字节数多的类型转换，以保证精度不降低。

```cpp
	int a = 3;
	double b = a;// 隐式转换

	// 类型的转换  所需要的类型和给的类型不匹配 需要转换
	// 强制转换 （需要转的类型）原来的数据类型
	printf("%d\n",(int)3.1456);

```

&emsp;强制类型转换指的是使用强制类型转换符，将一个变量或者表达式转换成所需要的类型，（类型说明符）表达式


**强制转化的宗旨：数据不丢失，小的转大的**

![图 1](../../images/a613c2a6dc67501e7e04f9f8a861b7e14593fca18dbd341859afda81a60c05c3.png)  

**有符号的可以转无符号的，多一位**





