#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int u32;

struct tt{
    int id;
    int age;
};

typedef struct tt TT;// 取别名

int main()
{

    int a = 10;
    u32 b = 1;
    printf("%d %d",sizeof(a),sizeof(b));

    TT tmp;
    tmp.id = 10;
    tmp.age = 1;

    printf("%d %d",tmp.id,tmp.age);

}