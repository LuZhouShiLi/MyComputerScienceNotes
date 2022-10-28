#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    FILE* fp = NULL;
    fp = fopen("./fprintf.txt","r");

    if(fp ==  NULL)
    {
        perror("文件打开失败");
        return -1;
    }
    
    int year = 0,month = 0 ,day = 0;
    fscanf(fp,"%d:%d:%d",&year,&month,&day);// 将文件中的内容按照格式写入变量中
    printf("%d %d %d\n",year,month,day);
    return 0;
}




