/* ************************************************************************
 *       Filename:  03unix_tcp_server.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月27日 17时14分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
	unlink("sock.s");
	//创建unix流式套接
	int lfd = socket(AF_UNIX,SOCK_STREAM,0);
	//绑定
	struct sockaddr_un myaddr;
	myaddr.sun_family = AF_UNIX;
	strcpy(myaddr.sun_path ,"sock.s");
	int len = offsetof(struct sockaddr_un,sun_path)+strlen(myaddr.sun_path);
	bind(lfd,(struct sockaddr *)&myaddr,len);
	//监听
	listen(lfd,128);
	
	//提取
	struct sockaddr_un cliaddr;
	socklen_t len_c = sizeof(cliaddr);
	int cfd = accept(lfd,(struct sockaddr*)&cliaddr,&len_c);

	printf("new cilent file = %s\n",cliaddr.sun_path);
	//读写
	char buf[1500]="";
	while(1)
	{
		int n = recv(cfd,buf,sizeof(buf),0);
		if(n <= 0)
		{
			printf("err or client close\n");
			break;
		}
		else
		{
			printf("%s\n",buf);
			send(cfd,buf,n,0);
		
		}
	
	}
	//关闭
	close(cfd);
	close(lfd);
	return 0;
}


