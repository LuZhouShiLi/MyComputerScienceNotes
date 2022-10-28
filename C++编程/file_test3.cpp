#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// 拷贝文件案例
int main()
{
    FILE *src = fopen("./a.txt","r");// 只读方式打开一个文件
    if(src == NULL)
    {
        perror("打开失败");
        return -1;
    }

    // 打开dist 创建新的文件
    FILE *dst = fopen("./c.txt","w");

    if(dst == NULL)
    {
        perror("创建失败");
        return -1;
    }
    char ch = 0;
    while(1)
    {
        // 读取src一个字符
        ch = fgetc(src);
        if(feof(src))
        {
            // feof(src) 的结果不是0 说明src读取完毕
            break;
        }
        // 写道dst文件中
        fputc(ch,dst);
    }
    fclose(src);
    fclose(dst);

    return 0;
}


