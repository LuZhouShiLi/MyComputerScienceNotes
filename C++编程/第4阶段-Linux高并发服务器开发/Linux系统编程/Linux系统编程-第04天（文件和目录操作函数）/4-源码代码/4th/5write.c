#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int fd = -1;
    int ret = -1;

    //1. 打开文件
    //fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    //fd = open("txt", O_WRONLY | O_CREAT , 0644);
    fd = open("txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        goto err0;
    }

    printf("fd = %d\n", fd);

    //2. 写文件
    ret = write(fd, "ABCDEFG", 7); 
    if (ret < 7)
    {
        perror("write"); 
    }

    //3. 关闭文件
    close(fd);

    return 0;
err0:
    return 1;
}
