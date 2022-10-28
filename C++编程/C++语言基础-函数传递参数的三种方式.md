# C++语言基础-函数传递参数的三种方式

## 一、值传递

```cpp
// 值传递
// 值传递仅仅会复制一份数据  然后交换的是复制后的那份数据 原来的数据并没有交换
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

```

## 二、指针传递

**交换的是内存空间**

```cpp
// 指针传递
void swap2(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

```


## 三、引用传递

**交换的是内存空间**

```cpp
// 引用传递
void swap3(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

```
