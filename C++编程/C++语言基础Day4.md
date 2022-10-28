# C++语言基础-函数的默认参数与函数的占位参数

## 一、函数的默认参数

```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int myFunc(int a, int b = 0)
{
	return a + b;
}

void test01()
{
	// 函数的默认参数的作用
	// 当函数内部要用到形参的某一个值 但是偶尔要用到其他值
	// 增加函数的灵活性
	cout << myFunc(1, 2) << endl;
	cout << myFunc(1) << endl;// 可以之传入一个参数 另一个参数是默认参数b = 0
}

int main()
{

	test01();
	return EXIT_SUCCESS;
}

```

注意事项：

* 函数的默认参数后面的参数必须都是默认参数

```cpp
int myFunc2(int a,int b = 0,int c = 2,int d = 3) // err
```


* 函数的声明和实现不能同时有函数的默认参数

```cpp
// 正确的写法
void myFunc3(int a,int b);// 函数的声明
void myFunc3(int a,int b = 0)
{

}
```


## 二、函数的占位参数

```cpp
// 函数的占位参数，占位参数在后面运算符重载时区分前加加还是后加加
void func(int a, int = 10)
{
	// 占位参数也有默认值
}

void test02()
{
	func(10);
}
```

## 三、占位参数和默认参数的混搭
```cpp
// 占位参数和默认参数的混搭
void func2(int = 10, int a = 30)
{

}

void test03()
{
	func2();
	func2(10);
	func2(10, 20);
}


```

