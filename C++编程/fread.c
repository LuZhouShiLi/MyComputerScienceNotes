#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "type.h"
#include<string.h>

int main()
{
    STD num[3];

    // 全部初始化为0
    memset(num,0,sizeof(num));
    FILE* fp = fopen("./fwrite.txt","r");

    if(fp ==  NULL)
    {
        perror("文件打开失败");
        return -1;
    }

    int count = 0;


    for(int i = 0; i < 3; i++)
    {
        count = fread(&num[i],1,sizeof(STD),fp);// 每次读取一块数据 每块数据是一个结构体大小
        // count返回20
        printf("count = %d\n",count);
        printf("%d %s\n",num[i].id,num[i].name);// 查看写入结果
    }



    return 0;
}
