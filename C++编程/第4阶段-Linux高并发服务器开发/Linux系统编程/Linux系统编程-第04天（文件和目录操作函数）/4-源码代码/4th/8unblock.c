#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 128



int main(void)
{
    int fd = -1;
    int ret = -1;

    char buf[SIZE];

    //1. 打开一个终端设备  该设备默认是阻塞的
    //fd = open("/dev/tty", O_RDWR);
    fd = open("/dev/tty", O_RDWR | O_NONBLOCK);
    if (-1 == fd)
    {
        perror("open"); 
        goto err0;
    }

    //2. 读设备
    memset(buf, 0, SIZE);
    ret = read(fd, buf, SIZE);
    if (ret <= 0)
    {
        perror("read"); 
    }

    printf("buf:%s\n", buf);

    //3. 关闭文件
    close(fd);

    return 0;
err0:
    return 1;
}
