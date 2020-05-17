//Download by www.cctry.com
#include<winsock2.h>				//包含头文件
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"WS2_32.lib")		//显式连接套接字库
using namespace std;

int main()							//主函数开始
{
	WSADATA data;						//定义WSADATA结构体对象
	WORD w=MAKEWORD(2,0);					//定义版本号码
	WSAStartup(w,&data);					//初始化套接字库

	SOCKET socketCli;						//定义连接套接字句柄
	char recvBuf[10]={0};					//接收的消息缓存
	socketCli=socket(AF_INET,SOCK_STREAM,0);			//创建TCP套接字
	sockaddr_in addrCli;					//定义套接字地址结构
	addrCli.sin_family=AF_INET;				//初始化地址结构
	addrCli.sin_port=htons(75);
	addrCli.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	printf("客户端已经启动\r\n");				//输出提示信息

	connect(socketCli,(sockaddr*)&addrCli,sizeof(addrCli));
	recv(socketCli,recvBuf,sizeof(recvBuf),0);
	printf("%s\r\n",recvBuf);
	
	closesocket(socketCli);					//关闭套接字句柄
	WSACleanup();						//释放套接字库
	if(getchar())						//如果有输入，则关闭程序
	{
		return 0;					//正常结束程序
	}
	else
	{
		Sleep(100);					//程序睡眠
	}
}
