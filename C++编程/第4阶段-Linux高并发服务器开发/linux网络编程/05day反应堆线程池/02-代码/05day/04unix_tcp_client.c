/* ************************************************************************
 *       Filename:  04unix_tcp_client.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月27日 17时35分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <stddef.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	unlink("sock.c");
	//创建unix流式套接字
	int cfd = socket(AF_UNIX,SOCK_STREAM,0);
	//如果不绑定,就是隐式绑定
	struct sockaddr_un myaddr;
	myaddr.sun_family = AF_UNIX;
	strcpy(myaddr.sun_path,"sock.c");
	int len = offsetof(struct sockaddr_un,sun_path)+strlen("sock.c");
	if(bind(cfd,(struct sockaddr*)&myaddr,len)< 0)
	{
		perror("");
		return 0;
	}
	//连接
	struct sockaddr_un seraddr;
	seraddr.sun_family = AF_UNIX;
	strcpy(seraddr.sun_path,"sock.s");
	connect(cfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	//读写
	while(1)
	{
		char buf[1500]="";
		int n = read(STDIN_FILENO,buf,sizeof(buf));
		send(cfd,buf,n,0);
		memset(buf,0,sizeof(buf));
		n = recv(cfd,buf,sizeof(buf),0);
		if(n <=0 )
		{
		
			printf("err or server close\n");
			break;
		
		}
		else
		{
			printf("%s\n",buf);
		
		}
	
	
	}
	//关闭
	close(cfd);
	return 0;
}


