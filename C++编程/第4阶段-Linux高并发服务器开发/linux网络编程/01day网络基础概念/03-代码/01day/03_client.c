/* ************************************************************************
 *       Filename:  03_client.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月21日 16时59分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
	//创建套接字
	int sock_fd;
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	//连接服务器
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	inet_pton(AF_INET,"192.168.21.29",&addr.sin_addr.s_addr);
	connect(sock_fd,(struct sockaddr *)&addr,sizeof(addr));
	//读写数据
	char buf[1024]="";
	while(1)
	{
		int n = read(STDIN_FILENO,buf,sizeof(buf));
		write(sock_fd,buf,n);//发送数据给服务器
		n = read(sock_fd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,n);
		printf("\n");
	
	}1

	
	
//关闭
	close(sock_fd);

	return 0;
}


