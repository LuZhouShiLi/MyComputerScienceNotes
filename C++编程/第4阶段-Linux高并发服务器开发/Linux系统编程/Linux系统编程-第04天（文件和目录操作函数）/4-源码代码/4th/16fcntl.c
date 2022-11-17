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

    //1. 打开文件 Ctrl + P
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }

    //2. 复制文件描述符 寻找一个大于或者等于10的最小的可以用文件描述符返回
    newfd = fcntl(fd, F_DUPFD, 10);
    if (-1 == newfd)
    {
        perror("fcntl"); 
        return 1;
    }
    printf("fd : %d  newfd: %d\n", fd, newfd);

    write(fd, "123456789", 9);
    write(newfd, "ABCDEFGHI", 9);

    
    //3. 关闭文件
    close(fd);
    close(newfd);

    return 0;
}
