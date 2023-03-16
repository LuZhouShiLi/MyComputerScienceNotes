#include <iostream>  
#include "windows.h"
#include "process.h"
#include <string>
using namespace std;
#pragma comment(lib, "WS2_32.lib")

void Receive(void* param)		//�������ݵ��̺߳���
{
	while (1)
	{
		//��������������
		SOCKET revClientSocket = *(SOCKET*)(param);
		char recvbuf[2048] = {};		//���ջ�����
		if (recv(revClientSocket, recvbuf, 2048, 0) == SOCKET_ERROR)
		{
			cout << "���ݽ���ʧ�ܣ�" << endl;
		}
		else
			cout << "���ͻ��ˡ�˵��" << recvbuf << endl;
	}
}

void Send(void* param)		//�������ݵ��̺߳���
{
	while (1)
	{
		//��������������
		SOCKET revClientSocket = *(SOCKET*)(param);
		char sendbuf[2048] = {};		//���ͻ�����
		cin.getline(sendbuf, 2048);
		if (send(revClientSocket, sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			cout << "������Ϣʧ�ܣ�" << endl;
		}
		else
			cout << "���Լ���˵��" << sendbuf << endl;
	}
}

int main()
{
	cout << "-----------������-----------" << endl;

	//�׽��ֳ�ʼ��
	WSADATA wsaData;	//����ṹ�������洢��WSAStartup�������ú󷵻ص� Windows Sockets ���ݡ�
	WORD sockVersion = MAKEWORD(2, 2);	//windows�����̿�İ汾����Ϣ
	if (WSAStartup(sockVersion, &wsaData) != 0) //WSAStartup�������ڳ����г�ʼ��������Windows����
	{
		cout << "�׽��ֳ�ʼ��ʧ��!" << endl;
		return 0;
	}

	//�����������׽���
	SOCKET SeverSocket;
	if ((SeverSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
	{
		cout << "�׽��ִ���ʧ�ܣ�" << endl;
		return 0;
	}
	struct sockaddr_in SeverAddress;		//һ���󶨵�ַ:��IP��ַ,�ж˿ں�,��Э����
	memset(&SeverAddress, 0, sizeof(sockaddr_in)); //��ʼ���ṹ��
	SeverAddress.sin_family = AF_INET;
	SeverAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//���뱾��IP��ַ 
	SeverAddress.sin_port = htons(60000);//�趨�˿ں�

	//���׽���     ָ���󶨵�IP��ַ�Ͷ˿ں�
	if (bind(SeverSocket, (sockaddr*)&SeverAddress, sizeof(SeverAddress)) == SOCKET_ERROR)
	{
		cout << "�׽��ְ�ʧ�ܣ�" << endl;
		return 0;
	}

	//����������	
	if (listen(SeverSocket, SOMAXCONN) == SOCKET_ERROR) //�����ĵڶ�����������:�ܴ�Ŷ��ٸ��ͻ�������,��������̵�ʱ�������
	{
		cout << "����ʧ�ܣ�" << endl;
		return 0;
	}
	else
		cout << "���������ڼ�����" << endl;

	//������������������
	sockaddr_in revClientAddress;	//�׽��ֵĵ�ַ���˿�
	SOCKET revClientSocket = INVALID_SOCKET;		//�������տͻ�������
	//memset(&revClientAddress, 0, sizeof(revClientAddress));
	int addlen = sizeof(revClientAddress);
	if ((revClientSocket = accept(SeverSocket, (sockaddr*)&revClientAddress, &addlen)) == INVALID_SOCKET)
	{
		cout << "���ܿͻ�������ʧ�ܣ�" << endl;
		return 0;
	}
	else
		cout << "���ܿͻ������ӳɹ���" << endl;

	//�����������߳�
	_beginthread(Receive, 0, &revClientSocket);
	_beginthread(Send, 0, &revClientSocket);

	while (1) {}  //Ϊ�˱������߳��˳�ʹ���̱߳���������ʹ���߳̽���ѭ��

	//�ر�socket
	closesocket(revClientSocket);
	closesocket(SeverSocket);

	//��ֹ
	WSACleanup();
	cout << "������ֹͣ��" << endl;
	return 0;
}
