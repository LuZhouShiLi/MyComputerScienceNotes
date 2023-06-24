# C++调用C语言

## 简单使用

* C++函数在汇编的时候，会给函数起别名，C语言的不会，这时候，如果C++来调用C语言的函数，C++回去找取别名的函数，但是C语言没有起别名，这时候会出错

**简单来说，就是告诉C++编译器，找下面的函数,要以C语言的方式进行寻找**

test.h
```cpp
#pragma once

#include<stdio.h>

#ifdef __cplusplus
extern "C"
#endif
{

	void func();

#ifdef __cplusplus
}
#endif



```

test.c

```cpp
#include "test.h"

void func() {
	printf("func");
}

```
main.cpp

```cpp
#include <iostream>
# define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include "test.h"


int main() {
	// 普通引用
	
	func();
	system("pause");
	return EXIT_SUCCESS;
}
```



