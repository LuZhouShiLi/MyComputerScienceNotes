#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

//ps aux | grep "bash"
int main(void)
{
    int ret = -1;
    int fd[2] = {0};

    pid_t pid = -1;

    //创建无名管道
    ret = pipe(fd);
    if (-1 == ret)
    {
        perror("pipe"); 
        goto err0;
    }

    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork"); 
        goto err0;
    }

    //子进程  ps aux
    if (0 == pid)
    {
        //关闭读端 
        close(fd[0]); 
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        exit(0); 
    }
    else
    {
        //父进程  grep bash
        //关闭写端
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        //先等待子进程结束
        //wait(NULL);
        execl("/bin/grep", "grep", "bash", "--color=auto", NULL);
    }

    return 0;
err0:
    return 1;
}
