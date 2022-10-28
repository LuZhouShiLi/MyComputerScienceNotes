# 一文详解Cpp工程调用python文件

## 一、概述

&emsp;最近做一个项目，使用C++语言进行编写，但是里面有很多的算法代码都是python语言编写的，如果将这些py文件重新使用C++编写的话会花费很多精力，所以使用C++来调用这些python脚本，使用C++、python进行混合编程

python提供了一套API,我们可以很好的在C++程序中调用这些python模块，但是使用之前需要在VS中配置好相关库

## 二、配置方法

### 2.1 新建一个C++工程

&emsp;首先新建一个C++工程，然后将其调到release,x64
![图 1](../images/fe1ba79e590d0143077fd59a53c83b75aed83090fb5ec160ab0372a161ecce29.png)  

我们选择，C++控制台应用程序，然后调整成release,x64

![图 2](../images/b77d81f4a956e6828e07edb7dcc15d6a1d7409b9ba979e52dcfe7a940708a86c.png)  


### 2.2 添加相关python库和路径

* 鼠标右键：属性
![图 3](../images/97936cb5263aaa80d3140785b71c218e6f019bce5ecb763c9861fb7dc65338bc.png)  

* 在包含目录和库目录中添加相关路径（你安装的python路径）
![图 4](../images/dea043e474d52bf9231d780f8eae8b762170043bd471fd86a35531bd07b7292e.png)  

* 添加附加包含目录：./include
![图 5](../images/d5b7b1bd3b3d7a3df7eb6d33c25d35685c614f1b4f34c07592f30bfc7fe185c0.png)  

* 附加依赖项
![图 6](../images/1d556a7d940f49ecf50836f83054251219a724020d7974592e445053e12f96a8.png)  

**以上这些操作都是为了C++代码可以引入Python.h的头文件**

### 2.3 复制包路径

将下面文件夹（python库）直接复制到C++编译的exe文件目录下，（如果没有，先运行程序，生成exe）,我这里的路径在：

```
D:\Project\Cpp_Project\TestCppPython2\x64\Release\TestCppPython2.exe
```
要复制的文件夹路径：

![图 7](../images/aec1830ad287c5140767890df9eb70ac983d50c42dcaf1cbc4f158afa3be70a1.png)  


赋值之后的情况：
![图 8](../images/3a41e15eebe0068c83380a53a2a894d0e473d8cbc1ae8bb41a2a8517e005e003.png)  

## 三、代码

```python
#include<iostream>
#include<Python.h>
using namespace std;

int main()
{
	// 初始化python接口
	Py_Initialize();

	if (!Py_IsInitialized())
	{
		// 判断python是否调用Python解释器  解释器初始化失败 
		cout << "Python init fail" << endl;
		return 0;
	}

	// 初始化python系统文件路径 保证可以访问到py文件
	PyRun_SimpleString("import sys");// 运行python语句
	PyRun_SimpleString("sys.path.append('./script')");

	// 调用python文件名 不需要写后缀 
	PyObject* pModule = PyImport_ImportModule("sayhello");

	if (pModule == NULL)
	{
		// 如果找不到该文件 
		cout << "module not found" << endl;
		return 1;
	}

	// 调用函数  没有参数
	PyObject* pFunc = PyObject_GetAttrString(pModule,"say");// 加载py文件中的函数


	if (!pFunc || !PyCallable_Check(pFunc))
	{
		// 判断一下指针pFunc是否为空  并且判断函数是否可调用
		cout << "not found function add_num" << endl;
		return 0;
	}

	PyObject_CallObject(pFunc,NULL);// 调用指定py文件中的函数

	// 结束python接口初始化
	Py_Finalize();
	return 0;

}

```


sayhello.py
```python
def say():
    print("hello")

```

**相关操作，请参考（感谢这位博主）：https://zhuanlan.zhihu.com/p/450318119**

**这里被调用的sayhello.py文件必须放在x64/release文件夹下面，也就是和你生成的exe同目录下**

![图 9](../images/01b54ba106e2843063a9528110710626e4184c60cfd65a1d9dcf9003e05ed42d.png)  

最后的结果：
![图 10](../images/f86341da3b735dadeb61bcb0a1d171078b4c4b56742ede0e200c90f882bfbcc7.png)  
