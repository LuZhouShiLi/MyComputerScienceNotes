# C++常函数和常对象学习笔记


## 一、友元的概述

&emsp;类的主要特点之一是数据隐藏，也就是类的私有成员没办法在类的外部访问，但是有时候需要在类的外部访问类的私有成员

&emsp;解决方法是使用友元函数，**C++允许友元函数访问类的私有成员**，**程序员可以把一个全局函数、某一个类中的成员函数、甚至整个类声明为友元**

## 二、友元的语法

* friend关键字只出现在声明处
* 其他类、类成员函数、全局函数都可以声明为友元
* **友元函数不是类的成员，没有this指针**
* **友元函数可以访问对象任意成员属性，包括私有属性**

全局友元函数示例：
```cpp

#include<iostream>
using namespace std;

class Maker {


	// 声明这个全局函数为该类的友元函数  但是不作为该类的成员函数
	friend void Good(Maker& m);

public:
	Maker()
	{
		keting = "客厅";
		woshi = "卧室";
	}


public:
	string keting;

private:
	string woshi;
};

void Good(Maker& m)
{
	cout << "好朋友访问" << m.keting << endl;
	cout << "好朋友访问" << m.woshi << endl;
}

void test01()
{
	Maker m;
	Good(m);
}

int main()
{
	test01();
	return EXIT_SUCCESS;
}

```


## 三、友元类

### 3.1 通过传入参数来访问类的私有成员

**如果A类需要调用B类的私有成员，那么就需要在B类将A类声明为他的友元类：friend class A**

```cpp
#include<iostream>
using namespace std;

class Maker {


	// 声明这个全局函数为该类的友元函数  但是不作为该类的成员函数
	friend void Good(Maker& m);
	friend class GoodF;// 声明GoodF是友元类

public:
	Maker()
	{
		keting = "客厅";
		woshi = "卧室";
	}


public:
	string keting;

private:
	string woshi;
};

class GoodF {

public:
	void func(Maker& bd)
	{
		cout << "访问：" << bd.keting << endl;
		cout << "访问：" << bd.woshi << endl;// 访问类的私有成员
	}

};

void Good(Maker& m)
{
	cout << "好朋友访问" << m.keting << endl;
	cout << "好朋友访问" << m.woshi << endl;
}

void test01()
{
	Maker m;
	Good(m);
}

void test02()
{
	Maker m;
	GoodF f;
	f.func(m);
}

int main()
{
	test02();
	return EXIT_SUCCESS;
}

```


### 3.2 通过类内指针来访问类的私有成员

```cpp
#include<iostream>
#include<string>
using namespace std;

class Maker {

	friend class GoodF2;// 声明为友元类

public:
	Maker()
	{
		keting = "客厅";
		woshi = "卧室";
	}


public:
	string keting;

private:
	string woshi;
};

class GoodF2 {
public:
	GoodF2()
	{
		p = new Maker;// 申请堆区空间
	}

	// 通过对象指针 访问私有成员
	void func()
	{
		cout << "访问：" << p->keting << endl;
		cout << "访问：" << p->woshi << endl;// 访问类的私有成员
	}

	// 拷贝构造  防止浅复制
	GoodF2(const GoodF2& f2)
	{
		// 申请空间
        p = new Maker;// 已经初始化
	}

	~GoodF2()
	{
		if (p != NULL)
		{
			// 释放空间
			delete p;
		}
	}

public:
	Maker* p;

};
void test02()
{
	GoodF2 f;
	f.func();

	GoodF2 f2 = f;// 调用拷贝构造
}

int main()
{
	test02();
	return EXIT_SUCCESS;
}

```

## 四、类的友元成员函数

类的成员函数成为另一个类的友元函数,不建议，直接将该类声明为另一个类的友元

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

// 编译器知道类的声明  不知道类的结构

class Building;// 声明Building 

class Building
{
	// 声明该类为Building 的友元类
	//friend class GoodF;

	// 声明GoodGay类的成员函数func成为Building类的友元函数
	friend void GoodF::func(Building &bud);

public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;

private:
	string woshi;
};


class GoodF
{
public:
	void func(Building& bd);
	
};

// 实现 加上作用域
void GoodF::func(Building& bd)
{
	cout << bd.keting << endl;
	cout << bd.woshi << endl;// 会报错
}

void test01()
{
	Building b;
	GoodF f;
	f.func(b);
}


int main()
{

	test01();

	return EXIT_SUCCESS;
}

```

## 五、友元类的注意

* 友元关系不能被继承
* 友元关系是单向的，类A是类B的朋友，但是类B不一定是类A的朋友
* 友元关系不具有传递性，类B是类A的朋友，类C是类B的朋友，但是类C不一定是类A的朋友



