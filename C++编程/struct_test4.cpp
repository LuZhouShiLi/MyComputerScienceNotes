#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

struct stu
{
    char name[50];
    int age;
};

// 函数参数是结构体普通变量
void set_stu(struct stu *tmp)
{
    strcpy(tmp->name,"mike");
    tmp->age = 10l;
}

int main()
{
    struct  stu s = {0};
    
    set_stu(&s);// 地址传递  函数中通过指针 操作s的内存空间
    printf("%s %d\n",s.name,s.age);
    
    return 0;
}