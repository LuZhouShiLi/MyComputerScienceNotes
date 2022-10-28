#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num = 0;
// 不同的作用域可以重名  变量一般优先使用最近的重名变量

int main()
{
    int num =10;
    printf("num1 = %d\n",num);// 打印10  打印最近的num
    {
        int num = 100;
    }
    printf("num2 = %d\n",num);// 打印10 代码块中的num是局部变量 销毁了
    system("pause");
    return 0;
}
