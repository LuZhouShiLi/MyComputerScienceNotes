#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

void *fun(char **q)
{
    // 堆区地址是可以被返回的 因为函数结束 堆区地址不会被释放

    // 传入的是&p 相当于*q  然后*q被重新赋予新的地址 最后返回q

    *q = (char *)malloc(sizeof(char) * 100);// 申请一块内存空间
    return q;
}

int main()
{
    char *p  = NULL; 
    fun(&p);
    strcpy(p,"hello");
    printf("%s ",p);
    free(p);
    return 0;
}