#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// 定义联合体  三种类型共用同一块内存空间
union mi
{
    short b;
    char buf[2];
};

int main()
{
    union mi tmp;
    tmp.b = 0x0102;//赋值 01 高地址 02 低地址

    if(tmp.buf[0] == 0x01)
    {
        printf("big\n");// tmp.buf[0] 一定存的是低地址  低地址存储的是01
    }
    else
    {
        printf("little\n");// 小端
    }

    printf("%d\n",sizeof(tmp));// 四个字节
    return 0;
}