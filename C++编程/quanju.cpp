# include<stdio.h>
# include<stdlib.h>

int num32;// 全局变量 作用域整个工程

void fun1()
{
    num32 = 10;
}

int main()
{
    printf("%d\n",num32);
    fun1();
    printf("%d\n",num32);
    system("pause");
    return 0;
}


