# C语言基础Day3-程序结构

## 一、概述

&emsp;C语言支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构

* 顺序结构：程序按照顺序执行，不发生跳转
* 选择结构：依据是否满足条件，有选择的执行相应功能
* 循环结构：依据条件是否满足，循环多次执行某段代码

## 二、选择结构


![图 2](../../images/454a14c1dd0f5cb907a81d1cea79819b9fce856105bd66c935803ea0c3df3997.png)  

![图 3](../../images/05826e17f115894d085c2981bda5f3a5ed6a35754f2c9428e8fd3228d15bcb4b.png)  

![图 4](../../images/24f5c90bad2fe917ec6d1314767f6207eb4baf397feed0bbff3519d53ce25f7b.png)  

## 三、三目运算符

```cpp
	int a = 10;
	int b = 20;
	int c = 0;

	// 求出a b之中的最大值
	c = a > b ? a : b;
	printf("%d\n",c);

```

## 四、switch语句

```cpp
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	int num;
	int a = 0;
	scanf("%d",&num);
	a = num % 4;// 0  1 2 3
	switch (a)// () 里面的判断条件只能是整数
	{
		case 0:
			printf("输出0\n");
			break;
		case 1:
			printf("输出1\n");
			break;
		case 2:
			printf("输出2\n");
			break;
		default:
			printf("输出3\n");
			break;
	}


	return 0;
}

```


**我们需要注意的是，switch中可以是字符，因为字符被认定是ASCII值，也就是整数**


## 五、while循环结构

![图 5](../../images/351582bd59797dafeb8c5c0b18bb0158d58a294148e77574433cfc7dd6af8bc2.png)  

```cpp
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	int i = 1;
	int sum = 0;

	while (i <= 100)
	{
		sum = sum + i;
		i++;
	}

	printf("sum = %d\n",sum);
	return 0;
}

```

```cpp
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	int i = 1;
	int sum = 0;

	do{
		sum += i;
		i++;
	}while(i <= 100);

	printf("sum = %d\n",sum);
	return 0;
}


```

## 六、for循环结构

```cpp
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{

	int sum = 0;

	for(int i = 1; i <= 100; i++)
	{
		sum += i;
	}

	printf("sum = %d\n",sum);
	return 0;
}


```

## 七、跳转语句

* break
  在switch条件语句和循环语句中都可以使用break语句：
  * 当它出现在switch条件语句中时，作用是终止某个case并跳出switch结构
  * 当它出现在循环语句中，作用是跳出当前内循环语句，执行后面的代码
  * 当他出现在嵌套循环语句中，跳出最近的内循环语句，执行后面的代码

* continue
  * 跳出本次循环


