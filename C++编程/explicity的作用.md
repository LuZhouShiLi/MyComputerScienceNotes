# explicit关键字的作用

* explicit 关键字只能放在构造函数前面 构造函数只有一个参数或者其他参数有默认值时
  
* 防止编译器优化 Maker m = 10; 这种格式

```cpp
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

class Maker {

public:
	// explicit 关键字只能放在构造函数前面 构造函数只有一个参数或者其他参数有默认值时
	// 防止编译器优化 Maker m = 10; 这种格式
	explicit Maker(int a)
	{
		id = a;
	}


private:
	int id;



};


int main()
{
	//Maker m = 1;//err
	return EXIT_SUCCESS;
}

```
