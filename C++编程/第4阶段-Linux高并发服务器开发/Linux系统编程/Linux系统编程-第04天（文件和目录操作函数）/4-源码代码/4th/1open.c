#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(void)
{
    int fd = -1;

    //1.以只读方式打开一个文件  如果文件不存在就报错
    //fd = open("txt", O_RDONLY);
    //2.以只写的方式打开一个文件 如果文件不存在就报错
    //fd = open("txt", O_WRONLY);
    //3.以只写的方式打开一个文件 如果文件不存在就创建, 如果文件存在就直接打开
    //fd = open("txt", O_WRONLY | O_CREAT, 0644);
    //4.以只读的方式打开一个文件 如果文件不存在就创建
    //fd = open("txt", O_RDONLY | O_CREAT, 0644);
    //5.以读写的方式打开文件 如果文件存在就报错, 如果文件不存在就创建
    //fd = open("txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    //6.以读写的方式打开一个文件 如果文件不存在就创建 如果文件存在就清零
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }


    printf("打开文件成功....\n");


    return 0;
}
