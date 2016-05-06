// SocketServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <winsock2.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	/*初始化DLL*/
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);


	SOCKET server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(8888);
	bind(server_socket, (SOCKADDR*)&server_addr, sizeof(SOCKADDR));
	cout<<"listenning..."<<endl;
	listen(server_socket, 20);

	SOCKADDR client_addr;
    int nSize = sizeof(SOCKADDR);
    SOCKET client_socket = accept(server_socket, (SOCKADDR*)&client_addr, &nSize);

	cout<<"connect"<<endl;
	closesocket(client_socket);
	closesocket(server_socket);

	WSACleanup();
	system("pause");

	return 0;
}

