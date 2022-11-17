/* ************************************************************************
 *       Filename:  01_upd_server.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月27日 16时19分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//创建套接字
	int fd = socket(AF_INET,SOCK_DGRAM,0);
	//绑定
	struct sockaddr_in myaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(9000);
	//inet_pton
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int ret = bind(fd,(struct sockaddr*)&myaddr,sizeof(myaddr));
	if(ret < 0)
	{
		perror("");
		return 0;
	}
	//读写
	char buf[1500]="";
	struct sockaddr_in cliaddr;
	socklen_t len = sizeof(cliaddr);

	struct sockaddr_in dstaddr;
	dstaddr.sin_family = AF_INET;
	dstaddr.sin_port = htons(8888);
	dstaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int n=0;
	while(1)
	{
		n = read(STDIN_FILENO,buf,sizeof(buf));	
		sendto(fd,buf,n,0,(struct sockaddr *)&dstaddr,sizeof(dstaddr));
		memset(buf,0,sizeof(buf));
		 n = recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
		if(n < 0)
		{
			perror("");
		}
		else{
			printf("%s\n",buf);
		
		}
	}
	//关闭
	close(fd);
	return 0;
}


