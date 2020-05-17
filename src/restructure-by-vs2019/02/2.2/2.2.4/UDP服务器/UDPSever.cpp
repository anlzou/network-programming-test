//Download by www.cctry.com
#include<winsock2.h>							//包含头文件
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"WS2_32.lib")				//连接套接字库

int main()
{
	WSADATA data;									//定义结构体变量
	WORD w=MAKEWORD(2,0);							//定义套接字版本
	char sztext[]="欢迎你\r\n";						//定义欢迎信息
	::WSAStartup(w,&data);							//初始化套接字库
	
	SOCKET socketSer;										//定义套接字句柄
	socketSer=::socket(AF_INET, SOCK_DGRAM,0);				//创建UDP套接字
	sockaddr_in addrSer,addrCli;							//套接字地址结构变量
	int len=sizeof(addrCli);							//地址结构变量大小
	char buff[10]={0};								//接收数据缓冲区
	addrSer.sin_family=AF_INET;
	addrSer.sin_port=htons(75);
	addrSer.sin_addr.S_un.S_addr=INADDR_ANY;
    ::bind(socketSer,(sockaddr*)&addrSer,sizeof(addrSer));		//绑定套接字
	printf("UDP服务器已经启动\r\n");				//显示提示信息

	while(1)
	{
		if(::recvfrom(socketSer,buff,10,0,(sockaddr*)&addrCli,&len)!=0)		//接收客户端信息
		{
			printf("%s已经连接上\r\n",inet_ntoa(addrCli.sin_addr));
			printf("%s\r\n",buff);
			::sendto(socketSer,sztext,sizeof(sztext),0,(sockaddr*)&addrCli,len);//发送数据到客户端
			break;
		} 
	}
	::closesocket(socketSer);							//关闭套接字对象
	::WSACleanup();								//释放套接字库

	if(getchar())							//如果有输入，则关闭程序
	{
	   return 0;									//正常结束程序
	}
	else
	{
	   ::Sleep(100);									//应用程序睡眠
	}
}
