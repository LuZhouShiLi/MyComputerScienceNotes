#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

struct t
{
    int a;
};

struct tea
{
    /* data */
    int id;
    char *p;
    struct t *b;
};

int main()
{
    struct tea *tmp = (struct tea *)malloc(sizeof(struct tea));

    tmp->id = 100;// 可以直接赋值
    tmp->p = (char *)malloc(100);// 需要开辟一块空间 在进行赋值 否则是野指针
    strcpy(tmp->p,"kkkk");


    // 下面的写法是错误的
    // tmp->b->a = 100;// 因为tmp->b是地址 所以使用->来访问a
    // 因为tmp->b 是指针  没有开辟堆空间 b是野指针 不能直接赋值b所指向的空间
    tmp->b = (struct t *)malloc(sizeof(struct t));
    tmp->b->a = 1000;
    
    return 0;
}