/* ************************************************************************
 *       Filename:  02_process_tcp_server.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年02月22日 15时42分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/


#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "wrap.h"
void free_process(int sig)
{
	pid_t pid;
	while(1)
	{
		pid = waitpid(-1,NULL,WNOHANG);
		if(pid <=0 )//小于0 子进程全部退出了 =0没有进程没有退出
		{
			break;
		}
		else
		{
			printf("child pid =%d\n",pid);
		}
	}



}
int main(int argc, char *argv[])
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGCHLD);
	sigprocmask(SIG_BLOCK,&set,NULL);
	//创建套接字,绑定
	int lfd = tcp4bind(8008,NULL);
	//监
	Listen(lfd,128);
	//提取
	//回射
	struct sockaddr_in cliaddr;
	socklen_t len = sizeof(cliaddr);
	while(1)
	{
		char ip[16]="";
		//提取连接,
		int cfd = Accept(lfd,(struct sockaddr *)&cliaddr,&len);
		printf("new client ip=%s port=%d\n",inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,ip,16),
				ntohs(cliaddr.sin_port));
		//fork创建子进程
		pid_t pid;
		pid = fork();
		if(pid < 0)
		{
			perror("");
			exit(0);
		}
		else if(pid == 0)//子进程
		{
			//关闭lfd
			close(lfd);
			while(1)
			{
			char buf[1024]="";

			int n = read(cfd,buf,sizeof(buf));
			if(n < 0)
			{
				perror("");
				close(cfd);
				exit(0);
			}
			else if(n == 0)//对方关闭j
			{
				printf("client close\n");
				close(cfd);
				exit(0);
			
			}
			else
			{
				printf("%s\n",buf);
				write(cfd,buf,n);
			//	exit(0);	
			}
			}
		
		}
		else//父进程
		{
			close(cfd);
			//回收
			//注册信号回调
			struct sigaction act;
			act.sa_flags =0;
			act.sa_handler = free_process;
			sigemptyset(&act.sa_mask);
			sigaction(SIGCHLD,&act,NULL);
			sigprocmask(SIG_UNBLOCK,&set,NULL);
		
		}
	}
	//关闭



	return 0;
}


