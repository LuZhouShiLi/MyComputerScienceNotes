#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (3 != argc)
    {
        printf("usage: ./a.out filename1 filename2\n"); 
        return 1;
    }

    //创建一个符号链接
    if (-1 == symlink(argv[1], argv[2]))
    {
        perror("symlink"); 
        return 1;
    }


    return 0;
}
