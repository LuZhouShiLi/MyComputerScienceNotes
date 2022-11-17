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

    //1. 打开文件
    fd = open("passwd", O_RDONLY);    
    if (-1 == fd)
    {
        perror("open"); 
        goto err0;
    }

    printf("打开文件ok... fd: %d\n", fd);

    //2. 循环读取数据
    while(1)
    {
        memset(buf, 0, SIZE);
        //每一次从文件中读取最多SIZE个字节
        ret = read(fd, buf, SIZE - 1); 
        if (ret < 0)
        {
            perror("read");
            break; 
        }
    
        printf("%s", buf);
    
        //读到文件结尾
        if (ret < SIZE - 1)
        {
            break; 
        }
    }

    //3. 关闭文件
    close(fd);

    return 0;
err0:
    return 1;
}
