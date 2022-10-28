#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

struct stu
{
    int id;
    int age;
    char name[128];
};


int main()
{
    struct stu a;
    struct stu *p = &a;// p没有初始化的话 是一个野指针  随机指向内存

    // 或者申请堆区空间
    struct stu *q = (struct stu *)malloc(sizeof(struct stu));// 申请一块sizeof(struct stu)大小的内存空间 然后q指针指向它

    p->id = 1;
    p->age = 22;
    strcpy(p->name,"ubuntu");// 赋值

    q->id = 10;
    q->age = 11;
    strcpy(q->name,"uuuuuu");

    printf("%d %d %s\n",p->id,p->age,p->name);
    printf("%d %d %s\n",q->id,q->age,q->name);
    return 0;
}