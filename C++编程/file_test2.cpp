#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    FILE *fp = fopen("./a.txt","r");

    if(fp == NULL)
    {
        perror("打开文件失败");
        return -1;
    }

    char buf[1024] = "";
    fgets(buf,sizeof(buf),fp);// 将文件中的内容读取到buf

    printf("%s",buf);

    
    return 0;
}