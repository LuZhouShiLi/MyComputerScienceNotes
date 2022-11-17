#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



#if 0
/* Standard file descriptors.  */
#define	STDIN_FILENO	0	/* Standard input.  */
#define	STDOUT_FILENO	1	/* Standard output.  */
#define	STDERR_FILENO	2	/* Standard error output.  */
#endif

int main(void)
{
    int fd = -1; 

    //1. 打开文件
    fd = open("txt", O_RDWR | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }


    printf("fd = %d\n", fd);
    printf("打开文件成功....\n");

    //2. 关闭文件 释放资源
    close(fd);

    return 0;
}
