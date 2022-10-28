#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int a = 10;
    // 将a赋值0
    memset(&a,0,sizeof(a));// 计算a的字节 将每一个字节都赋值为0
    printf("a = %d\n",a);

    char buf[10] = "";//空字符数组
    strcpy(buf,"hello");// 拷贝字符串  参数是字符串地址
    memset(buf,0,sizeof(buf));// 将字符数组全部清空 0
    printf("%s\n",buf);

    // 将前九个字符置为a
    memset(buf,'a',sizeof(buf) - 1);
    printf("%s\n",buf);

    return 0;
}


