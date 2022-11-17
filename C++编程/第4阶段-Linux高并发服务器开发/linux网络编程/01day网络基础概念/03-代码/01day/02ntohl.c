/* ************************************************************************
 *       Filename:  02ntohl.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月21日 15时54分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
	unsigned char buf[4]={1,1,168,192};
	int num = *(int *)buf;
	int sum = ntohl(num);
	unsigned char *p = (unsigned char *)&sum;
	printf("%d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3));
	return 0;
}


