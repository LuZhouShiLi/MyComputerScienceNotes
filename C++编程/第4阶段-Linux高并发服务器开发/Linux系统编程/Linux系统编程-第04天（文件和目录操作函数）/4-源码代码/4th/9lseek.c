#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 128

//以十六进制的方式查看文件内容
//deng@itcast:~/share/4th$ od -x txt

int main(void)
{
    int fd = -1;
    int ret = -1;

    //1. 打开文件
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        goto err1;
    }

    //在文件开头写七个字符
    write(fd, "ABCDEFG",  7);

    //将文件偏移30个字节
    ret = lseek(fd, 1024 * 1024, SEEK_END);
    if (-1 == ret)
    {
        perror("lseek"); 
        goto err2;
    }

    write(fd, "123456789", 9);

    //获取文件的大小
    printf("file: %ld\n", lseek(fd, 0, SEEK_END));

    //关闭文件
    close(fd);

    return 0;
err2:
    close(fd);
err1:
    return 1;
}

