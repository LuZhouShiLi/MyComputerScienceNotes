# C++语言学习笔记Day1-C++概述

## 一、概述

&emsp;C++语言在C语言的基础上添加了面向对象编程和泛型编程的支持。C++继承了C语言高效，简介，快速和可移植的传统。

C++融合了三种不同的编程方式：
* C语言代表的过程性语言
* C++在C语言基础上添加的类代表的面向对象语言
* C++模板支持的泛型编程

**C语言和C++语言的关系：**

**C++语言是在C语言的基础上添加了面向对象，模板等现代程序设计语言的特性而发展起来的。两者无论是从语法规则，还是从运算符的数量和使用上，都非常相似**

## 二、第一个程序hello world

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

int main()
{
	cout << "hello world" << endl;// 标准的输出流对象

	// endl 是刷新缓冲区并换行

	return EXIT_SUCCESS;
}
```

## 三、面向对象的三大特征

### 3.1 封装

&emsp;把客观的事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏

&emsp;类将成员变量和成员函数封装在类的内部，根据需要设置访问权限，通过成员函数管理内部状态

### 3.2 继承

&emsp;继承所表达的是类之间相关的关系，这种关系使得对象可以继承另外一类对象的特征和能力。

&emsp;继承的作用：避免公用代码的重复开发，减少代码和数据冗余

### 3.3 多态

&emsp;多态性可以简单地概括为“一个接口，多种方法”，字面意思为多种形态，程序在运行时才决定调用的函数，它是面向对象编程领域的核心概念


## 四、命名空间

&emsp;创建名字是程序设计过程中一项基本活动，当一个项目很大时，它会不可避免地包含大量的名字，C++允许我们对名字的产生和名字的可见性进行控制

&emsp;我们之前在学习C语言可以通过static关键字来使得名字只在本编译单元内可见，在c++中我们将通过一种命名空间来控制对名字的访问

### 4.1 C++命名空间(namespace)

&emsp;在C++中，名称(name)可以是符号常量、变量、函数结构、枚举、类和对象等，工程越大，名称互相冲突可能性越大，另外使用多个厂商的类库，也可能导致名称冲突，为了避免这种情况，在大规模程序的设计中，以及在程序员使用各种各样的C++库时，这些标识符的命名发生冲突，标准C++引入关键字namespace(命名空间/名字空间/名称空间),可以更好地控制标识符的作用域。

```cpp
namespace A{
	// A就是空间的名字
	int a;
	void func()
	{

	}

}

// 命名空间嵌套空间
namespace Maker
{
	int a;
	namespace B;
	{
		int b;
	}
}

```

注意：

* 命名空间只能定义在全局
* 命名空间可以嵌套命名空间
* 命名空间是开放的，随时可以加入新成员，但是新成员只能在加入之后使用

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

int ma = 10;// 定义一个全局变量

namespace Maker
{
	int c = 30;
}

namespace Maker1
{
	int a;
	namespace B
	{
		int b = 40;
	}
}

int main()
{
	int ma = 20;

	// 就近原则
	cout << "ma = " << ma << endl;// 打印20 就近打印
	cout << "::ma=" << ::ma << endl;// 打印10 打印全局变量  ：：前面啥都不写 表示访问全局
	cout << Maker::c << endl;// 表示访问Maker作用域中的c变量

	// 访问嵌套空间中的变量
	cout << Maker1::B::b << endl;

	return EXIT_SUCCESS;
}

```

**匿名命名空间，类似于static int d = 50**

```cpp
namespace
{
	int d = 50;
}

```

**命名空间可以取别名**

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

int ma = 10;// 定义一个全局变量

namespace Maker
{
	int c = 30;
}

namespace Maker1
{
	int a;
	namespace B
	{
		int b = 40;
	}
}

void test01()
{
	namespace nameMaker = Maker;// 命名空间可以取别名
	cout << nameMaker::c << endl;// 测试是否成功

}

int main()
{
	int ma = 20;

	// 就近原则
	cout << "ma = " << ma << endl;// 打印20 就近打印
	cout << "::ma=" << ::ma << endl;// 打印10 打印全局变量  ：：前面啥都不写 表示访问全局
	cout << Maker::c << endl;// 表示访问Maker作用域中的c变量

	// 访问嵌套空间中的变量
	cout << Maker1::B::b << endl;

	return EXIT_SUCCESS;
}

```

**分文件编写代码时，如果.h中有两个命名空间，但是里面的成员函数或者成员变量同名时，在.cpp中实现函数时，需要加上命名空间**

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

#include"test.h"

int ma = 10;// 定义一个全局变量

namespace Maker
{
	int c = 30;
}

namespace Maker1
{
	int a;
	namespace B
	{
		int b = 40;
	}
}

void test01()
{
	namespace nameMaker = Maker;// 命名空间可以取别名
	cout << nameMaker::c << endl;// 测试是否成功

}

int main()
{
	int ma = 20;

	// 就近原则
	cout << "ma = " << ma << endl;// 打印20 就近打印
	cout << "::ma=" << ::ma << endl;// 打印10 打印全局变量  ：：前面啥都不写 表示访问全局
	cout << Maker::c << endl;// 表示访问Maker作用域中的c变量

	// 访问嵌套空间中的变量
	cout << Maker1::B::b << endl;

	myMaker1::func();// 调用函数


	return EXIT_SUCCESS;
}

```

```cpp
#pragma once

#include<iostream>
using namespace std;

// 不同命名空间的函数声明

namespace myMaker1
{
	void func();
}

namespace myMaker2
{
	void func();
}


```

```cpp
#include"test.h"

void myMaker1::func()
{
	cout << "cunc" << endl;// 调用第一个命名空间的函数
}

void myMaker2::func()
{
	cout << "cunc" << endl;// 调用第一个命名空间的函数
}
```

### 4.2 using编译指令

&emsp;using编译指令使整个命名空间标识符可用，**后面使用该标识符就不需要在使用命名空间标识符**

```cpp

namespace A
{
	int a = 10;
	int b = 20;
	int c = 30;
}

void test02()
{
	using A::a; // 使用using 进行声明 后面就不需要加上命名空间标识符
	cout << a << endl; 

}

int main()
{
	test01();
	return EXIT_SUCCESS;
}

```

```cpp

void test03()
{
	// using 编译指令，让某一个命名空间中的标识符都可以直接使用
	using namespace A;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main()
{
	/*test01();*/

	test03();



	return EXIT_SUCCESS;
}
```


## 五、结构体的加强

* C中定义结构体变量需要加上struct关键字，c++不需要
* C中的结构体只能定义成员变量，不可以定义成员函数，c++既可以定义成员变量，也可以定义成员函数

```cpp

struct Maker2
{
	int a;

	// 结构体内可以写函数
	void func()
	{
		cout << "func" << endl;
	}
};

void test04()
{
	Maker2 a2;
	a2.func();
}

int main()
{
	/*test01();*/

	test04();



	return EXIT_SUCCESS;
}

```

## 六、更加严格的类型转换检查

```cpp
char *p = (char *)malloc(64);// malloc 返回void *

// 这种方式不能进行隐士转换，必须进行显示转换

```

## 七、三目运算符

```cpp
int a = 10;
int b = 20;

*(a > b ? &a : &b) = 100;
printf("%d",b);

```

**C语言的三目运算符返回的是右边的值，C++语言的三目运算符返回的是左值，是空间地址，放在赋值操作符左边的是左值，放在右边的是右值**

## 八、const修饰的变量

### 8.1 C语言中的const变量
```c
#include<stdio.h>
#include<stdlib.h>

const int a = 100;// 定义一个全局变量 非栈区

void test()
{
	// a = 200 全局的const不可以直接修改
	int* p = (int*)&a;// 获取地址然后 转换成int * 指针类型
	*p = 100;// 全局的const不可以间接修改
	printf("%d\n",a);
}

int main()
{
	const int b = 20;// 栈区
	int *p = (int*)&b;
	*p = 200;// 栈区的ocnst 可以间接修改
	printf("%d\n",b);

	// 使用别的文件的全局const修饰的变量 需要声明
	extern const int c;
	printf("%d",c);

	return EXIT_SUCCESS;
}

```

**总结：**
* C语言的const修饰的变量都有空间
* C语言的const修饰的全局变量具有外部链接属性

### 8.2 C++语言修饰的变量

常量折叠
```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

const int aa = 100;// 没有分配内存下


int main()
{
	
	cout << "aa = " << aa << endl;// 在编译阶段  编译器：cout<<"aa = "<< 10 << endl;
	const int bb = 20;// 定义一个栈区变量 
	int* p = (int*)&bb;
	*p = 200;// 实际上 间接修改已经成功
	cout << "bb = " << bb << endl;// C++编译器翻译成cout<< "bb = "<<20<<endl;

	cout << "*p" << *p << endl;
	cout << "bb指向的地址" << &bb << endl;
	cout << "p指向的地址" << p << endl;
	return EXIT_SUCCESS;
}
```
**添加volatile 防止编译器优化**

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告
const int aa = 100;// 没有分配内存

int main()
{
	
	cout << "aa = " << aa << endl;// 在编译阶段  编译器：cout<<"aa = "<< 10 << endl;
	volatile const int bb = 20;// 定义一个栈区变量  添加volatile 不让编译器进行优化
	int* p = (int*)&bb;// 有空间
	*p = 200;// 实际上 间接修改已经成功
	cout << "bb = " << bb << endl;// C++编译器翻译成cout<< "bb = "<<20<<endl;
	cout << "*p = " << *p << endl;
	cout << "bb指向的地址" << (int)&bb << endl;
	cout << "p指向的地址" << (int)p << endl;
	return EXIT_SUCCESS;
}
```

总结：

**C++语言的const修饰的变量有时候有空间，有时没有空间（发生常量折叠，且没有对变量进行取地址操作）**

```cpp
const int ccc = 100;
```
```cpp
// 报错
extern const int ccc;// C++ 语言const修饰的全局变量没有外部链接属性  C语言具有
cout << ccc << endl;
```

**C++语言const修饰的全局变量仅仅具有内部链接属性**

**但是声明的时候添加extern 就变为外部链接属性**

```cpp
extern const int ccc = 100;
```


## 九、C++编译器不能优化的情况

```cpp
#include<iostream>// 引入头文件
using namespace std;// 标准命名空间
#define _CRT_SECURE_NO_WARNINGS  // 过滤警告

void test()
{
	int a = 10;
	const int b = a;// 如果用变量给const修饰的局部变量赋值，那么编译器不会进行优化
	int* p = (int*)&b;
	*p = 100;
	cout << "b = " << b << endl;// 这里直接打印100  
	// 如果写成const int b = 10;// 输出的时候编译器优化 输出10


	cout << "*p = " << *p << endl;
}

struct Maker
{
	Maker()
	{
		a = 100;
	}
	int a;
};

void test02()
{
	const Maker ma;
	cout << ma.a << endl;
	Maker* p = (Maker*)&ma;
	p->a = 200;
	cout << ma.a << endl;// 自定义数据类型不可以优化
}

int main()
{
	test02();
	return EXIT_SUCCESS;
}
```

**总结：**

* 不能优化自定义数据类型
* 如果用变量给const修饰的局部变量赋值，那么编译器就不能优化

