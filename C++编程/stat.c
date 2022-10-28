#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    struct stat buf;  // 初始化一个 struct stat 结构体 
    int ret = 0;
    ret = stat("fwrite.txt",&buf);// 第二个参数填写结构体地址
    // 将文件的状态信息写入buf中
    if(ret < 0)
    {
        printf("file not found\n");
    }
    printf("%d\n",buf.st_size);// 打印文件的大小  60个字节
    return 0;
}


