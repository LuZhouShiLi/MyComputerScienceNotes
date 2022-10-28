# 一文搞定C++语言引用用法

## 一、引用概述

&emsp;引用是C++对C的重要扩展，在C、C++中指针的作用基本都是一样的，但是C++增加了另外一种给函数传递地址的途径，这就是按照引用传递（pass-by-reference），他也存在于其他一些编程语言中，并不是C++的发明

* 变量名实质上是一段连续内存空间的别名，是一个标号（门牌号）
* 程序中通过变量来申请并且命名内存空间
* 通过变量的名字可以使用存储空间

**C++中新增了引用的概念，引用可以作为一个已经定义变量的别名**

* 引用和C语言指针一样的功能，并且是语法更加简洁
* 引用是给空间取别名

案例
```cpp
#include<iostream>
using namespace std;

void test01()
{
	int a = 10;
	int &b = a;// 给a的空间取别名  不是取地址操作

	b = 100;
	cout << a << endl;
}

// 传引用
void func(int& a)
{
	a = 200;
}

void test02()
{
	int a = 10;
	func(a);// 传引用
	cout << "a = " << a << endl;
}

int main()
{
	test01();
	test02();

	return EXIT_SUCCESS;
}
```

## 二、引用的注意

* int &b = a;// 这里的&不是取地址操作符，是引用的标记作用
* 引用创建时，必须初始化。// int &p;// error
* 引用一旦初始化就不可以改变它的指向
* 引用必须引用一块合法的内存空间

## 三、数组的引用

```cpp
#include<iostream>
using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5};

	// 第一种方法
	// 定义数组类型
	typedef int(MY_ARR)[5];// 数组类型

	// 建立引用
	MY_ARR &arref = arr;// 建立引用 类似于 int &b = a;

	// 第二种方法
	// 直接定义引用
	int(&arref2)[5] = arr;
	// 第三种方法
	typedef int(&MY_ARR3)[5];// 建立引用数组类型
	MY_ARR3 arref3 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arref[i]<<endl;
	}
	return EXIT_SUCCESS;
}
```

```cpp
#include<iostream>
using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5};

	// 第一种方法
	// 定义数组类型
	typedef int(MY_ARR)[5];// 数组类型

	// 建立引用
	MY_ARR &arref = arr;// 建立引用 类似于 int &b = a;

	// 第二种方法
	// 直接定义引用
	int(&arref2)[5] = arr;


	// 第三种方法
	typedef int(&MY_ARR3)[5];// 建立引用数组类型
	MY_ARR3 arref3 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arref[i]<<endl;
	}

	for (int i = 0; i < 5; i++)
	{
		arref2[i] += 100;
		cout << arref2[i] << endl;
	}

	return EXIT_SUCCESS;
}

```

## 四、引用的本质

**引用的本质在C++内部实现是一个常指针**

**C++编译器在编译过程中使用常指针作为引用的内部实现，因此引用所占用的空间大小与指针相同，只是这个过程是编译器内部实现，用户不可见**

## 五、尽量用const代替define

**const和#define区别总结**

* const有类型，可以进行编译器类型安全检查，#define没有类型，不可以进行类型检查

#deinfe 不检查数据类型
```cpp
#include<iostream>
using namespace std;
#define MA 128 // 没有定义数据类型

void func(short a)
{
	cout << "func(short a)" << endl;
}

void func(int a)
{
	cout << "func(int a)" << endl;
}

int main()
{
	func(MA);// 调用第二个函数

	return EXIT_SUCCESS;
}


int main01()
{
	int arr[] = {1,2,3,4,5};

	// 第一种方法
	// 定义数组类型
	typedef int(MY_ARR)[5];// 数组类型

	// 建立引用
	MY_ARR &arref = arr;// 建立引用 类似于 int &b = a;

	// 第二种方法
	// 直接定义引用
	int(&arref2)[5] = arr;


	// 第三种方法
	typedef int(&MY_ARR3)[5];// 建立引用数组类型
	MY_ARR3 arref3 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arref[i]<<endl;
	}

	for (int i = 0; i < 5; i++)
	{
		arref2[i] += 100;
		cout << arref2[i] << endl;
	}

	return EXIT_SUCCESS;
}

```

const 可以自定义数据类型
```cpp
#include<iostream>
using namespace std;
#define MA 128 // 没有定义数据类型
const short ma = 128;

void func(short a)
{
	cout << "func(short a)" << endl;
}

void func(int a)
{
	cout << "func(int a)" << endl;
}

int main()
{
	func(ma);// 调用第一个函数

	return EXIT_SUCCESS;
}
```


* const有作用域而#define不重视作用域，默认定义处到文件结尾，如果定义在指定作用域下有效的常量，那么#define就不能用。


## 五、指针的引用

案例

```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

void test01()
{
	char string[] = "翠花";
	char* p = string;
	char* &p1 = p;// 指针的引用
	cout << p1 << endl;
}

int main()
{
	test01();

	return EXIT_SUCCESS;
}
```
**指针的引用就是给指针变量这块空间取别名**


**C语言使用二重指针**
```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void test01()
{
	char string[] = "翠花";
	char* p = string;
	char* &p1 = p;// 指针的引用
	cout << p1 << endl;
}

// 被调函数
void func(char** tmp)
{
	char* p;
	p = (char*)malloc(64);// 申请一块内存空间
	memset(p,0,64);// 全部初始化为0
	strcpy(p,"笑话");// 赋值字符串
	*tmp = p;// 将地址赋值给*tmp
}

// 主调函数
void test02()
{
	char* mp = NULL;
	func(&mp);
	cout << mp << endl;
}

int main()
{
	//test01();
	test02();
	return EXIT_SUCCESS;
}
```


**C++语言使用指针的引用**

```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void test01()
{
	char string[] = "翠花";
	char* p = string;
	char* &p1 = p;// 指针的引用
	cout << p1 << endl;
}

// 被调函数
void func(char* &tmp)
{
	char* p;
	p = (char*)malloc(64);// 申请一块内存空间
	memset(p,0,64);// 全部初始化为0
	strcpy(p,"快乐");// 赋值字符串
	tmp = p;// 将地址赋值给*tmp
}

// 主调函数
void test02()
{
	char* mp = NULL;
	func(mp);// 直接传入指针即可 tmp作为mp的别名
	

	// mp传入之后 相当于 char* &tmp = mp  也就是定义了一个char* 类型的引用，作为指针mp的别名

	cout << mp << endl;
}

int main()
{
	//test01();
	test02();

	return EXIT_SUCCESS;
}

```

## 六、C/C++的区别

* C语言的结构体不能写函数，C++可以
* 结构体定义变量时，C++不需要加上struct关键字
* 更加严格的类型检查
* const修饰的变量，C++有时候没有内存，C语言的都有内存
* 三目运算符返回的值不一样
* 引用和C语言的指针功能一样

## 七、引用的使用场景

### 7.1 引用作为函数参数

```cpp
void func(int& a, int& b)
{
	// 引用作为函数参数
	int sum = a + b;
	cout << "sum = " << sum << endl;
}

void test03()
{
	int a = 1;
	int b = 2;
	func(a,b);
}

int main()
{
	//test01();
	test03();
	return EXIT_SUCCESS;
}
```

### 7.2 引用作为函数的返回值

```cpp

int& func3()
{
	static int b = 10;// 定义在静态区  不定义在栈区  内存空间不会随着函数调用结束而销毁
	return b;
}

void test06()
{
	func3() = 100;// 如果函数当左值 那么该函数必须返回引用
	cout << "func3() = " << func3() << endl;
}

int main()
{
	//test01();
	test06();
	return EXIT_SUCCESS;
}
```

## 八、常量的引用

常量引用的定义格式：
```cpp
const Type& ref = val;
```

常量引用注意：

```cpp
* 字面意思不能赋给引用，但是可以赋给const引用
* const 修饰的引用不能被修改
```

```cpp
int main()
{
	// 普通引用
	int a = 10;
	int& ref = a;
	ref = 20;
	// int &ref2 = 10;// 不能给字面量取别名  error
	const int& ref3 = 10;// 但是可以给给字面量取const修饰的引用
	 ref3 = 100;// const修饰的引用不可以被修改 err

	return EXIT_SUCCESS;
}
```

**上述代码，编译器会做如下处理：int tmp = 10,const int &ref3 = tmp;**




