//Download by www.cctry.com
#include<winsock2.h>					//包含头文件
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"WS2_32.lib")			//连接套接字库

int main()
{
	WSADATA data;					//定义结构体变量
	WORD w=MAKEWORD(2,0);				//初始化套接字版本号
	::WSAStartup(w,&data);				//初始化套接字库
	SOCKET s;					//定义套接字
	s=::socket(AF_INET,SOCK_DGRAM,0);		//创建UDP套接字
	sockaddr_in addr,addr2;				//定义套接字地址
	int n=sizeof(addr2);
	char buff[10]={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(75);
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");		
	printf("UDP客户端已经启动\r\n");
	char sztext[]="你好\r\n";
	if(::sendto(s,sztext,sizeof(sztext),0,(sockaddr*)&addr,n)!=0)	//发送信息
	{
		::recvfrom(s,buff,10,0,(sockaddr*)&addr2,&n);		//接收信息
		printf("服务器说：%s\r\n",buff);
		::closesocket(s);					//关闭套接字
		::WSACleanup();						//释放套接字库
	} 
	if(getchar())							//如果有输入，则关闭程序
	{
		return 0;						//正常结束程序
	}
	else
	{
		::Sleep(100);						//应用程序睡眠
	}
}
