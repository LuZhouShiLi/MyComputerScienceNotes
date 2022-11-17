#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#if 0
struct stat {
    dev_t     st_dev;         /* ID of device containing file */
    ino_t     st_ino;         /* inode number */
    mode_t    st_mode;        /* protection */
    nlink_t   st_nlink;       /* number of hard links */
    uid_t     st_uid;         /* user ID of owner */
    gid_t     st_gid;         /* group ID of owner */
    dev_t     st_rdev;        /* device ID (if special file) */
    off_t     st_size;        /* total size, in bytes */
    blksize_t st_blksize;     /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;      /* number of 512B blocks allocated */

    /* Since Linux 2.6, the kernel supports nanosecond
     *                   precision for the following timestamp fields.
     *                                     For the details before Linux 2.6, see NOTES. */

    struct timespec st_atim;  /* time of last access */
    struct timespec st_mtim;  /* time of last modification */
    struct timespec st_ctim;  /* time of last status change */

#define st_atime st_atim.tv_sec      /* Backward compatibility */
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};

S_IFMT     0170000   bit mask for the file type bit field

S_IFSOCK   0140000   socket
S_IFLNK    0120000   symbolic link
S_IFREG    0100000   regular file
S_IFBLK    0060000   block device
S_IFDIR    0040000   directory
S_IFCHR    0020000   character device
S_IFIFO    0010000   FIFO


#endif

//查看文件信息命令
//deng@itcast:~/share/4th$ stat txt

//获取文件相关信息
int main(int argc, char **argv)
{
    int ret = -1;

    struct stat buf;

    if (2 != argc)
    {
        printf("usage: ./a.out filename\n"); 
        return 1;
    }

    memset(&buf, 0, sizeof(buf));
    //获取文件相关信息
    ret = stat(argv[1], &buf);
    if (-1 == ret)
    {
        perror("stat"); 
        return 1;
    }

    printf("st_dev: %lu\n", buf.st_dev);
    printf("st_ino: %lu\n", buf.st_ino);
    printf("st_nlink: %lu\n", buf.st_nlink);
    printf("st_uid: %d\n", buf.st_uid);
    printf("st_gid: %d\n", buf.st_gid);
    printf("st_rdev:%lu\n", buf.st_rdev);
    printf("st_size: %ld\n", buf.st_size);
    printf("st_blksize: %ld\n", buf.st_blksize);
    printf("st_blocks: %ld\n", buf.st_blocks);

#if 0
    switch((buf.st_mode & S_IFMT))
    {
        case S_IFSOCK:   
            printf("socket\n");
            break;
        case S_IFLNK :   
            printf("symbolic link\n");
            break;
        case S_IFREG :   
            printf("regular file\n");
            break;
        case S_IFBLK :   
            printf("block device\n");
            break;
        case S_IFDIR :   
            printf("directory\n");
            break;
        case S_IFCHR :   
            printf("character device\n");
            break;
        case S_IFIFO :   
            printf("FIFO\n");
            break;
        defalt:
            printf("未知类型....\n");
    }
#else

    if (S_ISREG(buf.st_mode) ) 
        printf("is it a regular file \n"); 
    if (S_ISDIR(buf.st_mode) ) 
        printf("directory            \n");   
    if (S_ISCHR(buf.st_mode) ) 
        printf("character device     \n");   
    if (S_ISBLK(buf.st_mode) ) 
        printf("block device         \n"); 
    if (S_ISFIFO(buf.st_mode)) 
        printf("FIFO (named pipe)    \n");   
    if (S_ISLNK(buf.st_mode) ) 
        printf("symbolic link        \n");    
    if (S_ISSOCK(buf.st_mode)) 
        printf("socket               \n");   


#endif

    //判断文件所属者权限
    if (buf.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");

    buf.st_mode & S_IWUSR ? printf("w") : printf("-");
    buf.st_mode & S_IXUSR ? printf("x") : printf("-");

    //判断文件所属组权限
    buf.st_mode & S_IRGRP ? printf("r") : printf("-");
    buf.st_mode & S_IWGRP ? printf("w") : printf("-");
    buf.st_mode & S_IXGRP ? printf("x") : printf("-");

    //判断文件其它权限
    buf.st_mode & S_IROTH ? printf("r") : printf("-");
    buf.st_mode & S_IWOTH ? printf("w") : printf("-");
    buf.st_mode & S_IXOTH ? printf("x") : printf("-");



    printf("\n");





    return 0;
}
