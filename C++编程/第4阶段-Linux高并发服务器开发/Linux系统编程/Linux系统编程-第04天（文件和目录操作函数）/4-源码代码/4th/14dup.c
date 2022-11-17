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
    int newfd = -1;

    //1. 打开文件
    fd = open("txt", O_RDWR | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }

    //2. 复制文件描述符
    //newfd = dup(fd);
    newfd = 10;
    //如果newfd文件描述符已经与其它文件关联, 那么先close, 然后在使用该数字
    newfd = dup2(fd, newfd);
    if (-1 == newfd)
    {
        perror("dup"); 
        return 1;
    }

    printf("fd : %d  newfd: %d\n", fd, newfd);
    
    //3. 关闭文件
    close(fd);
    close(newfd);

    return 0;
}
