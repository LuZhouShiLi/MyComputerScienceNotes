/* ************************************************************************
 *       Filename:  02_inet_pton.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月21日 16时28分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>

#include <arpa/inet.h>
int main(int argc, char *argv[])
{

	char buf[]="192.168.1.4";
	unsigned int num=0;
	inet_pton(AF_INET,buf,&num);
	unsigned char * p = (unsigned char *)&num;
	printf("%d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3));
	char ip[16]="";
	printf("%s\n",inet_ntop(AF_INET,&num,ip,16));
	return 0;
}


