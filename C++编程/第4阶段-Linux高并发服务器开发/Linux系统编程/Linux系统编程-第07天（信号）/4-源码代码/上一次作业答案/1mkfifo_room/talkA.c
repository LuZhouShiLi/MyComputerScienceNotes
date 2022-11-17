#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 128

//读管道内容
int main(void)
{
    int ret = -1;
    int fdr = -1;
    int fdw = -1;

    pid_t pid = -1;
    
    char buf[SIZE];

    //1. 判断指定有名管道是否存在
    ret = access("fifo1", F_OK);
    if (-1 == ret)
    {
        printf("管道不存在， 创建对应有名管道\n"); 
        //创建一个有名管道
        ret = mkfifo("fifo1", 0644);
        if (-1 == ret)
        {
            perror("mkfifo"); 
            goto err0;
        }
    }

    ret = access("fifo2", F_OK);
    if (-1 == ret)
    {
        printf("管道不存在， 创建对应有名管道\n"); 
        //创建一个有名管道
        ret = mkfifo("fifo2", 0644);
        if (-1 == ret)
        {
            perror("mkfifo"); 
            goto err0;
        }
    }

 
    //2. 以只读的方式打开管道fifo1
    fdr = open("fifo1", O_RDONLY); 
    if (-1 == fdr)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo1 for reading ok....\n");


    //3. 以只写的方式打开管道fifo2
    fdw = open("fifo2", O_WRONLY); 
    if (-1 == fdw)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo2 for writing ok....\n");


    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork"); 
        goto err1;
    }

    //子进程 读
    if (0 == pid)
    {

        //读  读fifo1
        while(1)
        {
            //4. 读管道的数据
            memset(buf, 0, SIZE);
            ret = read(fdr, buf, SIZE);    
            if (ret <= 0)
            {
                perror("read"); 
                break;
            }
            printf("\033[31mbuf: %s\033[0m\n", buf);  //VT
        }

        exit(0);    
    }

    //父进程 写
    //写fifo2
    while(1)
    {
        //5. 写管道信息
        memset(buf, 0, SIZE);
        //从标准输入获取数据
        fgets(buf, SIZE, stdin);
        buf[strlen(buf) - 1] = 0;

        ret = write(fdw, buf, strlen(buf));
        if (-1 == ret)
        {
            perror("write"); 
            break;
        }
    }

    //6. 关闭文件
    close(fdr);
    close(fdw);

    return 0;
err1:
    close(fdr);
    close(fdw);
err0:
    return 1;
}
