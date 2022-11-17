#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 128

//从文件中读数据
int main(void)
{
    int fd = -1;
    int ret = -1;

    char buf[SIZE];

    //1. 打开文件  只读的方式
    fd = open("txt", O_RDONLY);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }
    printf("open successfully fd = %d\n", fd);

    //2. 读文件
    memset(buf, 0, SIZE);
    //从文件中最多读取SIZE个字节保存到buf中
    ret = read(fd, buf, SIZE);
    if (-1 == ret)
    {
        perror("read"); 
        close(fd);
        return 1;
    }

    printf("buf: %s\n", buf);

    //3. 关闭文件
    close(fd);
    return 0;
}
