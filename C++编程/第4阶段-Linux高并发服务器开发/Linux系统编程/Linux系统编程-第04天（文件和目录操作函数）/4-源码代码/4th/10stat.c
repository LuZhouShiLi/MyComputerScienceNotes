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

#endif

//查看文件信息命令
//deng@itcast:~/share/4th$ stat txt

//获取文件相关信息
int main(void)
{
    int ret = -1;

    struct stat buf;

    memset(&buf, 0, sizeof(buf));
    //获取文件相关信息
    ret = stat("txt", &buf);
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


    return 0;
}
