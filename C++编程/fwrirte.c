#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "type.h"

int main()
{
    FILE *fp = NULL;
    fp = fopen("fwrite.txt","w");
    if(fp ==NULL)
    {
        perror("文件打开失败");
        return -1;
    }

    // 定义一个结构体数组
    STD num[3] = {{1,"lucy"},{2,"bob"},{3,"peter"}};

    // 返回值：写入总的文件字节数
    int count = fwrite(num,1,sizeof(num),fp);// 传入块数据大小一个字节   sizeof(num)
    // 表示每块数据的字节数

    printf("%d",count);// 一个结构体有20个字节 总共有六十个字节

}

