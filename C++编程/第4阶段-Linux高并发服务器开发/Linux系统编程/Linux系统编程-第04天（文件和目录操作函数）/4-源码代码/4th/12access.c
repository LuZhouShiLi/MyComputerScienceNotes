#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (2 != argc)
    {
        printf("usage: ./a.out filename\n"); 
        return 1;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]); 
    }

    //判断文件是否存在
    if (access(argv[1], F_OK) == 0)
    {
        printf("文件存在...\n"); 
    }
    else
    {
        printf("文件不存在....\n"); 
    }

    //判断文件是否有读的权限
    if (access(argv[1], R_OK) == 0)
    {
        printf("可以读\n"); 
    }
    else
    {
        printf("不可以读\n"); 
    }

    return 0;
}
