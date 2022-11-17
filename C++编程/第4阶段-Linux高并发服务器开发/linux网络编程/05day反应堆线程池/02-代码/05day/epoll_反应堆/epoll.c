#include <stdio.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include "wrap.h"
int main(int argc, char const *argv[])
{
	//创建套接字,绑定
	int lfd = tcp4bind(8000,NULL);
	//监听
	listen(lfd,128);
	//创建树
	int epfd = epoll_create(1);
	struct epoll_event ev,evs[1024];
	ev.data.fd = lfd;
	ev.events = EPOLLIN;//监听读事件
	//将ev上树
	epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&ev);
	while(1)
	{
		int nready = epoll_wait(epfd,evs,1024,-1);
		if(nready < 0)
			perr_exit("err");
		else if(nready == 0)
			continue;
		else if(nready > 0 )
		{
			for(int i=0;i<nready;i++)
			{
				if(evs[i].data.fd == lfd && evs[i].events & EPOLLIN)//如果是lfd变化,并且是读事件
				{
						struct sockaddr_in cliaddr;
						char buf_ip[16]="";
						socklen_t len  = sizeof(cliaddr);
						int cfd = Accept(lfd,(struct sockaddr *)&cliaddr,&len);
						printf("client ip=%s port=%d\n",inet_ntop(AF_INET,
						&cliaddr.sin_addr.s_addr,buf_ip,sizeof(buf_ip)),
						ntohs(cliaddr.sin_port));
						ev.data.fd = cfd;//cfd上树
						ev.events = EPOLLIN;//监听读事件
						epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);//将cfd上树

				}
				else if(evs[i].events & EPOLLIN)//普通的读事件
				{
					char buf[1024]="";
					int n = Read(evs[i].data.fd , buf,sizeof(buf));
					if(n <= 0 )
					{
						close(evs[i].data.fd);//关闭cfd
						epoll_ctl(epfd,EPOLL_CTL_DEL,evs[i].data.fd,&evs[i]);//将cfd上树
						printf("client close\n");
					}
					else
					{
						printf("%s\n",buf );
						Write(evs[i].data.fd ,buf,n);

					}


				}


			}



		}


	}
	close(lfd);
	return 0;
}