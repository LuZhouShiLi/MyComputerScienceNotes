#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "type.h"
#include<string.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("fseek.txt","w");
    if(fp == NULL)
    {
        perror("文件打开失败");
        return -1;
    }
    fputs("ghelldgchsuacdguascg",fp);// 写入字符串
    fseek(fp,0,SEEK_SET);// 从文件开头移动0个字节  也就是将光标移动到文件内开头
    // 移动光标之后 再次写入字符串
    fputs("seek",fp);

    // 将光标相对于文件末尾移动五个字符
    fseek(fp,-5,SEEK_END);
    fputs("seek",fp);// 接着写入数据

    fclose(fp);// 关闭文件
    return 0;
}





