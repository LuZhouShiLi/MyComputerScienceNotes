#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("demo.txt","w");

    if(fp ==  NULL)
    {
        perror("文件打开失败");
        return -1;
    }

    char buf[1024];

    for(int i = 0; i < 1024; i++)
    {
        memset(buf,'1',sizeof(buf));// 所有字节全部写成1
        fwrite(buf,1,sizeof(buf),fp);// 将buf按照一个字节大小的数据块写入fp中
        // 每一次总共有sizeof(buf)个数据块被写入fp
        printf("i = %d\n",i);// 
    }

    while(1);

    return 0;
}

