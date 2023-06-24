# this指针


## 初步使用

**this指针永远指向当前对象**

```cpp
class Maker {
public:
	// 静态成员变量的生命周期是整个程序 作用域在类内部
	static int a;

	Maker() {
		b = 100;
	}


	static void seTa(int aa) {
		a = aa;
		cout << "aa" << aa << endl;
	}

	// 使用this指针调用对象的成员变量
	void func() {
		cout << this->b << endl;
	}

private:
	int b;
};


```

* 每一个对象都有一个隐藏的this指针，但是不属于对象 都是编译器添加
* 编译器会把this指针传入成员函数内部
* this指针指向对象的存储空间，但是不指向静态成员

## 作用
* 构造函数
* 返回对象本身
```cpp


class Maker2 {
public:
	Maker2(int id){
		this->id = id;
	}

	// 返回对象本身
	Maker2& getMa() {
		return *this;
	}

private:
	int id;
};
```

