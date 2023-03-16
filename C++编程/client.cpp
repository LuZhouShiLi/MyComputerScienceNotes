#include<iostream>
#include "windows.h"
#include "process.h"
#include <string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

void Receive(void* param)
{
	while (1)
	{
		//�ͻ��˽������Է�����������
		SOCKET clientSocket = *(SOCKET*)(param);
		char  recvbuf[2048] = {};		//���ջ�����
		if (recv(clientSocket, recvbuf, 2048, 0) == SOCKET_ERROR)
		{
			cout << "���ݽ���ʧ��" << endl;
		}
		else
			cout << "����������˵:" << recvbuf << endl;
	}
}

void Send(void* param)
{
	while (1)
	{
		//�ͻ��˷������ݸ�������
		SOCKET clientSocket = *(SOCKET*)(param);
		char sendbuf[2048] = {};		//���ͻ�����
		cin.getline(sendbuf, 2048);
		if (send(clientSocket, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			cout << "������Ϣʧ�ܣ�";
		}
		else
			cout << "���Լ���˵��" << sendbuf << endl;
	}
}

int main()
{
	cout << "-----------�ͻ���-----------" << endl;
	WSADATA  wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		cout << "�׽��ֳ�ʼ��ʧ��!" << endl;
	}
	SOCKET clientSocket;
	if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
	{
		cout << "�׽��ִ���ʧ��!" << endl;
	}
	struct sockaddr_in SeverAddress;		//��������ַ Ҳ���Ǽ���Ҫ���ӵ�Ŀ���ַ
	memset(&SeverAddress, 0, sizeof(sockaddr_in));
	SeverAddress.sin_family = AF_INET;
	SeverAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //127.0.0.1��ʾ����ip��ַ
	SeverAddress.sin_port = htons(60000);//�趨�˿ں�

	//��ʼ����
	if (connect(clientSocket, (sockaddr*)&SeverAddress, sizeof(SeverAddress)) == SOCKET_ERROR)
	{
		cout << "�ͻ��ˣ��ͷ���������ʧ�ܣ�" << endl;
		return 0;
	}
	else
		cout << "����������ӳɹ���" << endl;

	//�����������߳�
	_beginthread(Receive, 0, &clientSocket);
	_beginthread(Send, 0, &clientSocket);

	Sleep(INFINITE);	//�����������һ�ּ����������߳�ִ�����˳�����ʹ������������
	//	�ر�socket
	if (clientSocket != INVALID_SOCKET) {
		closesocket(clientSocket);
		clientSocket = INVALID_SOCKET;
	}

	//	��ֹ
	WSACleanup();
	cout << "�ͻ����˳���" << endl;
	return 0;
}
