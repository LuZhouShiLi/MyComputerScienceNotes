/* ************************************************************************
 *       Filename:  01htonl.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月21日 15时42分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	char buf[4]={192,168,1,2};
	int num = *(int *)buf;
	int sum = htonl(num);
	unsigned char *p = &sum;

	printf("%d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3));

	unsigned short a = 0x0102;
	unsigned short b = htons(a);

	printf("%x\n",b);

	return 0;
}


