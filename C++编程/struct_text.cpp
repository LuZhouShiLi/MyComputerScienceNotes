#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// 关键字 struct 代表这个是一个结构体类型
// stu 代表结构体的名字
// 整个结构体的类型是 struct stu

// 结构体类型struct stu{} 中是结构体的成员 一个有三个成员，每一个成员的类型可以是任意的类型
// 注意：定义结构体的时候 struct stu只是一个类型  一个模板 没有内存空间 不可以给结构体成员赋值 

struct stu
{
    int id;
    int age;
    char name[128];
}a,b;// 需要加上分号  定义类型时 同时定义了两个结构体变量 同struct stu a,b 

struct heima_stu
{
    /* data */
    struct stu s;// 嵌套结构体
    char subject[128];
};


int main()
{
    // // 定义一个结构体数组  结构体数组有五个元素 每一个元素都是struct stu类型
    // struct stu num[5] = {{1,20,"lucy"},{2,21,"bub"},{3,22,"peter"},{4,22,"maker"},{5,26,"ubuntu"}};

    // // 打印结构体的元素
    // for(int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    // {
    //     printf("%d %d %s\n",num[i].id,num[i].age,num[i].name);
    // }

    struct heima_stu xxf;

    xxf.s.id = 1;
    xxf.s.age = 22;
    strcpy(xxf.s.name,"hello");
    strcpy(xxf.subject,"C++");

    printf("%d %d %s %s\n",xxf.s.id,xxf.s.age,xxf.s.name,xxf.subject);

    return 0;
}
