#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 128

//文件的简单拷贝 不支持二进制
int main(void)
{
    int fdr = -1;
    int fdw = -1;
    int ret = -1;

    char buf[SIZE];

    //1. 以只读的方式打开第一个文件
    fdr = open("passwd", O_RDONLY);
    if (-1 == fdr)
    {
        perror("open"); 
        goto err0;
    }

    //2. 以只写的方式打开第二个文件
    fdw = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (-1 == fdw)
    {
        perror("open"); 
        goto err1;
    }

    //3. 循环拷贝数据
    while(1)
    {
        //从第一个文件中读取数据
        memset(buf, 0, SIZE);
        ret = read(fdr, buf, SIZE); 
        if (ret <= 0)
        {
            perror("read");
            break; 
        }
    
        //将读取的数据写入到第二个文件中
        ret = write(fdw, buf, ret); 
        if (ret <= 0)
        {
            break; 
        }
    }

    //4. 关闭两个文件描述符
    close(fdr);
    close(fdw);

    return 0;
err1:
    close(fdr);
err0:
    return 1;
}
