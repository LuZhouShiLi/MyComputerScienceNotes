#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{   
    // 打开一个文件 成功返回FILE结构体地址 失败返回NULL
    FILE *fp = fopen("./a.txt","w");
    if(fp == NULL)
    {
        perror("没有这个文件");// 该函数用来打印错误信息
        return -1;
    }
    
    char buf[] = "hello";

    int i = 0;
    while(buf[i] != '\0')
    {
        fputc(buf[i],fp);
        i++;
    }

    fclose(fp);

    return 0;
}



