#include<stdio.h>
#include<conio.h>
#include<winsock2.h>
#pragma comment(lib, "wsock32.lib")

int main()
{
	WSADATA wsa;
	SOCKET server;
	SOCKET client;
	SOCKADDR_IN ServerAddr;
	SOCKADDR_IN ClientAddr;
	int port = 12345;
	int len;
	//khai bao phien ban winsock
	WSAStartup(MAKEWORD(2,2), &wsa);
	//khoi tao socket server
	server = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//cvai dat sockaddr de quan ly dia chi
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port=htons(port);
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//Khi socket duoc tao ra can dùng hàm bind de bind toi dia chi
	bind(server,(SOCKADDR *)&ServerAddr, sizeof(ServerAddr));
	//chap nhan ket noi khi 1 yeu cau duoc gui den
	len=sizeof(ClientAddr);
	client = accept(server,(SOCKADDR *) &ClientAddr,&len);
	client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//dong cac ket noi
	closesocket(server);
	closesocket(client);
	//
	WSACleanup();
	return 1;
}
