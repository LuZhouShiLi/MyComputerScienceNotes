# C++语言基础Day3-内联函数

## 一、预处理宏定义的缺陷

&emsp;预处理宏存在问题的关键是我们可能认为预处理器的行为和编译器的行为是一样的。当然也是由于宏函数调用和函数调用在外表看起来是一样的，因为也容易被混淆，但是其中也会存在一些微妙的问题出现。

问题案例1：
```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define ADD(x,y) x + y 

void test()
{
	int ref = ADD(10,20) * 2;// 编译器翻译成 10 + 20 * 2
	cout << "ref = " << ref << endl;
}

int main()
{
	test();

	return EXIT_SUCCESS;
}
```


**使用内联函数可以解决该问题**
```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define ADD(x,y) x + y 

// 在普通函数前面加上Inline是像编译器申请成为内联函数
inline int Add(int x, int y)
{
	return x + y;
}


void test()
{
	//int ref = ADD(10,20) * 2;// 编译器翻译成 10 + 20 * 2
	//cout << "ref = " << ref << endl;

	int ref2 = Add(10, 20) * 2;
	cout << "ref2 = " << ref2 << endl;
}

int main()
{
	test();

	return EXIT_SUCCESS;
}

```


问题案例2：
```cpp
#define COMAPD(x,y) ((x) < (y)?(x):(y))

// 宏定义缺陷
void test02()
{
	int a = 1;
	int b = 3;

	// 编译器翻译成：(++a) < (b) ?(++a):(b)  
	cout << "comapd(x,y) = " << COMAPD(++a, b) << endl;// 输出3
}


int main()
{
	test02();

	return EXIT_SUCCESS;
}
```


**使用内联函数可以解决该问题**
```cpp
inline int func(int x, int y)
{
	return x < y ? x : y;
}

// 宏定义缺陷
void test02()
{
	int a = 1;
	int b = 3;

	// 编译器翻译成：(++a) < (b) ?(++a):(b)  
	//cout << "comapd(x,y) = " << COMAPD(++a, b) << endl;// 输出3

	cout << "结果是：" << func(++a, b) << endl;
}

int main()
{
	test02();

	return EXIT_SUCCESS;
}

```

## 二、什么情况不会成为内联函数

* 存在过多的条件判断语句
* 函数体过大
* 对函数进行取地址操作
* 不能存在任何形式的循环语句

## 三、内联函数的好处

* 有宏函数的效率，没有宏函数的缺点
* 类的成员函数默认加上inline

## 四、编译器对内联函数进行何种处理

&emsp;对于任何类型的函数，编译器会将函数类型（包括函数名字，参数类型，返回值类型）放入到符号表中，同样的，当编译器看到内联函数，并且对内联函数体进行分析没有发现错误时，也会将内联函数放入到符号表中。

&emsp;当调用一个内联函数的时候，编译器首先确保传入的参数类型是正确匹配的，或者入伏哦类型不正确匹配，但是可以将其转换为正确类型，并且返回值在目标表达式匹配正确类型或者可以转换为目标类型，内联函数就会直接替换函数调用，这就消除了函数调用的开销。加入内联函数是成员函数，对象this指针也会被放入合适的位置。

