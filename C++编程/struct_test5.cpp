#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>

struct c13
{
    int id;
    char name[128];
    /* data */
};

// 传入数组名 其实就是传入地址
void set_num(struct c13 *p,int n)
{
    for(int i = 0; i < n; i++)
    {
    //    (*(p + i)).id = i + 10;
    // 或者写成
        p[i].id = 10 + i;

        char buf[128] = "";// 初始化一个空的字符串
        sprintf(buf,"%d%d%d",i,i,i);

        strcpy(p[i].name,buf);//拷贝字符串

    }
}

int main()
{
    struct c13 num[3];

    // 结构体内容清0
    memset(num,0,sizeof(num));// 所有字节内容都清0

    set_num(num,sizeof(num) / sizeof(num[0]));// 数组名作为参数传入函数 其实就是传入数组地址  指针类型

    for(int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        printf("%d %s\n",num[i].id,num[i].name);
    }


    return 0;
}