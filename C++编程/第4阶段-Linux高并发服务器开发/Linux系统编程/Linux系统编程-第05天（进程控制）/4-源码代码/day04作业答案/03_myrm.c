#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int rm(const char* path)
{
    struct stat stat_buf;
    int ret = stat(path, &stat_buf); //获取文件属性
    if(ret < 0)
    {
        perror("stat");
        return -1;
    }
	
	// 判断path是个文件还是目录
    // 如果是文件，直接unlink然后返回
    if(!S_ISDIR(stat_buf.st_mode))
    {
        unlink(path);
        return 0;
    }
 
    char buf[1024];
    DIR* dir = opendir(path); //打开目录
    if(dir == NULL)
	{
		perror("opendir");
	    return -1;	
	}
 
    struct dirent* entry = NULL;
	// 如果path是目录，遍历目录中的所有目录项
    while( (entry = readdir(dir)) != NULL )
    {
        sprintf(buf, "%s/%s", path, entry->d_name); //必须先放前面
		
        if(entry->d_type == DT_REG || entry->d_type == DT_LNK)
        {//如果是普通文件，或链接文件，则删除
            unlink(buf);
        }
		
        if(entry->d_type == DT_DIR)
        {//如果是目录
            // 忽略.和..目录
            if(strcmp(entry->d_name, ".") == 0 ||strcmp( entry->d_name, "..") == 0)
            {
                continue;
            }
			
            rm(buf); //递归删除
        }
    }
 
    closedir(dir);
    rmdir(path); //删除目录
	
    return 0;
}
 
int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        printf("usage: %s [pathname]\n", argv[0]);
        return 0;
    }
	
    rm(argv[1]);
	
    return 0;   
}


