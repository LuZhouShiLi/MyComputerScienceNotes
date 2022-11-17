#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//文件描述符复制
int main(void)
{
    int fd = -1;
    int ret = -1;

    //1. 打开文件 Ctrl + P
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }


    //2. 获取文件状态标志
    ret = fcntl(fd, F_GETFL);
    if (-1 == ret)
    {
        perror("fcntl"); 
        return 1;
    }

    if (ret & O_NONBLOCK)
    {
        printf("设置为非阻塞...\n"); 
    }
    else
    {
        printf("设置为阻塞...\n"); 
    }


    //设置为非阻塞
    ret |= O_NONBLOCK;
    ret = fcntl(fd, F_SETFL, ret);
    if (-1 == ret)
    {
        perror("fcntl"); 
        return 1;
    }

    //2. 获取文件状态标志
    ret = fcntl(fd, F_GETFL);
    if (-1 == ret)
    {
        perror("fcntl"); 
        return 1;
    }

    if (ret & O_NONBLOCK)
    {
        printf("设置为非阻塞...\n"); 
    }
    else
    {
        printf("设置为阻塞...\n"); 
    }



        
    //3. 关闭文件
    close(fd);

    return 0;
}
