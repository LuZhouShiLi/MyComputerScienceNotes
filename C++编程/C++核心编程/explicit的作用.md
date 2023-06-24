# 动态对象创建


## new和delete简单使用

* C语言不会调用构造和析构函数
* C++申请堆区空间和释放堆区空间使用new和delete关键字

```cpp
# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "test.h"
using namespace std;



class Maker {
public:
	Maker(int id, int age) {

		cout << "有参构造函数" << endl;
		mId = id;
		mAge = age;
	}

	int getId() {
		return mId;
	}

	int getAge() {
		return mAge;
	}

	~Maker() {
		cout << "释放" << endl;
	}
	
private:
	int mId;
	int mAge;
};

class Student {
public:
	Student(const char* name, int Age) {
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		age = Age;
	}

	// 深拷贝  拷贝构造函数  也就是先申请空间  然后拷贝
	Student(const Student& stu) {
		cout << "自己拷贝的构造函数" << endl;
		// 申请空间
		pName = (char*)malloc(strlen(stu.pName) + 1);
		// 拷贝数据
		strcpy(pName, stu.pName);
		age = stu.age;
	}

	~Student() {
		cout << "析构函数" << endl;

		if (pName != NULL) {

			free(pName);
			pName = NULL;

		}
	}

private:
	char* pName;
	int age;
};

void test() {
	Maker m1(1, 11);
	Maker m2(m1);

	cout << "m1 " << m1.getId() << endl;
	cout << "m2 " << m2.getAge() << endl;

}

void test01() {
	Maker* m = new Maker(1,1);// 申请空间  调用构造函数
	delete m;// 释放空间

}
int main() {
	// 封装
	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}

```

## 申请和释放数组空间

```cpp
// 创建数组
void test02() {
	// 申请基础数据类型的数组
	int* pInt = new int[10];
	for (int i = 0; i < 10; i++) {
		pInt[i] = i + 1;
	}
}
```



