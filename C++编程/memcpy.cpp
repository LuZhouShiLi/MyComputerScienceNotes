#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
    // char str1[128] = "";
    // char str2[128] = "abc\0dsa\0ad";
    // memcpy(str1,str2,10 * sizeof(char));// 拷贝十个字节

    // strncpy(str1,str2,10 * sizeof(char));// 遇到\0 停止拷贝

    // for(int i = 0; i < 10; i++)
    // {
    //     printf("%d ",str1[i]);// 打印ASCII值
    // }

    char num1[] = {1,2,0,4,5,6,7};
    char num2[] = {1,2,0,6,5,6,7};

    // printf("%d\n",memcmp(num1,num2,7 * sizeof(char)));// 打印-1

    printf("%d\n",strncmp(num1,num2,7 * sizeof(char)));// 打印0 遇到\0就停止  这里是ASCII值

    char s1[] = "abc\0ss";
    char s2[] = "abc\0aa";
    printf("%d\n",strncmp(s1,s2,6 * sizeof(char)));//打印0


    return 0;
}