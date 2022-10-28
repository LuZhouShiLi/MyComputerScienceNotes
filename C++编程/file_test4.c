#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNNINGS

int main()
{
    int year = 2018;
    int month = 10;
    int day = 27;

    char buf[1024] = "";
    FILE *fp = NULL;
    fp = fopen("./fprintf.txt","w");

    if(!fp)
    {
        perror("文件打开失败");
        return -1;
    }
    // 先将字符串按照指定格式写入buf中
    sprintf(buf,"%04d:%02d:%02d\n",year,month,day);

    // 或者写成
    fprintf(fp,"%04d:%02d:%02d\n",year,month,day);// 直接将字符串按照指定格式写入文件中


    // 将格式化字符串写入文件中
   
    fputs(buf,fp);

    fclose(fp);
    return 0;
}


