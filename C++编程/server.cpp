#include <iostream>  
#include "windows.h"
#include "process.h"
#include <string>
using namespace std;
#pragma comment(lib, "WS2_32.lib")

void Receive(void* param)		//接受数据的线程函数
{
	while (1)
	{
		//服务器接受数据
		SOCKET revClientSocket = *(SOCKET*)(param);
		char recvbuf[2048] = {};		//接收缓冲区
		if (recv(revClientSocket, recvbuf, 2048, 0) == SOCKET_ERROR)
		{
			cout << "数据接受失败！" << endl;
		}
		else
			cout << "【客户端】说：" << recvbuf << endl;
	}
}

void Send(void* param)		//发送数据的线程函数
{
	while (1)
	{
		//服务器发送数据
		SOCKET revClientSocket = *(SOCKET*)(param);
		char sendbuf[2048] = {};		//发送缓冲区
		cin.getline(sendbuf, 2048);
		if (send(revClientSocket, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			cout << "发送消息失败！" << endl;
		}
		else
			cout << "【自己】说：" << sendbuf << endl;
	}
}

int main()
{
	cout << "-----------服务器-----------" << endl;

	//套接字初始化
	WSADATA wsaData;	//这个结构被用来存储被WSAStartup函数调用后返回的 Windows Sockets 数据。
	WORD sockVersion = MAKEWORD(2, 2);	//windows网络编程库的版本号信息
	if (WSAStartup(sockVersion, &wsaData) != 0) //WSAStartup函数是在程序中初始化并加载Windows网络
	{
		cout << "套接字初始化失败!" << endl;
		return 0;
	}

	//创建服务器套接字
	SOCKET SeverSocket;
	if ((SeverSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
	{
		cout << "套接字创建失败！" << endl;
		return 0;
	}
	struct sockaddr_in SeverAddress;		//一个绑定地址:有IP地址,有端口号,有协议族
	memset(&SeverAddress, 0, sizeof(sockaddr_in)); //初始化结构体
	SeverAddress.sin_family = AF_INET;
	SeverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//填入本机IP地址 
	SeverAddress.sin_port = htons(60000);//设定端口号

	//绑定套接字     指定绑定的IP地址和端口号
	if (bind(SeverSocket, (sockaddr*)&SeverAddress, sizeof(SeverAddress)) == SOCKET_ERROR)
	{
		cout << "套接字绑定失败！" << endl;
		return 0;
	}

	//服务器监听	
	if (listen(SeverSocket, SOMAXCONN) == SOCKET_ERROR) //监听的第二个参数就是:能存放多少个客户端请求,到并发编程的时候很有用
	{
		cout << "监听失败！" << endl;
		return 0;
	}
	else
		cout << "服务器正在监听：" << endl;

	//服务器接受连接请求
	sockaddr_in revClientAddress;	//套接字的地址，端口
	SOCKET revClientSocket = INVALID_SOCKET;		//用来接收客户端连接
	//memset(&revClientAddress, 0, sizeof(revClientAddress));
	int addlen = sizeof(revClientAddress);
	if ((revClientSocket = accept(SeverSocket, (sockaddr*)&revClientAddress, &addlen)) == INVALID_SOCKET)
	{
		cout << "接受客户端连接失败！" << endl;
		return 0;
	}
	else
		cout << "接受客户端连接成功！" << endl;

	//创建两个子线程
	_beginthread(Receive, 0, &revClientSocket);
	_beginthread(Send, 0, &revClientSocket);

	while (1) {}  //为了避免主线程退出使子线程被迫消亡，使主线程进入循环

	//关闭socket
	closesocket(revClientSocket);
	closesocket(SeverSocket);

	//终止
	WSACleanup();
	cout << "服务器停止！" << endl;
	return 0;
}
