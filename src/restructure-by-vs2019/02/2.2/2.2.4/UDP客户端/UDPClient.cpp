//Download by www.cctry.com
#include<winsock2.h>					//包含头文件
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"WS2_32.lib")			//连接套接字库
using namespace std;

int main()
{
	WSADATA data;					//定义结构体变量
	WORD w=MAKEWORD(2,0);				//初始化套接字版本号
	WSAStartup(w,&data);				//初始化套接字库
	
	SOCKET socketCli;					//定义套接字
	socketCli=socket(AF_INET,SOCK_DGRAM,0);		//创建UDP套接字
	sockaddr_in addrSer,addrCli;				//定义套接字地址
	int len=sizeof(addrCli);
	char buff[10]={0};
	addrSer.sin_family=AF_INET;
	addrSer.sin_port=htons(75);
	addrSer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");		
	printf("UDP客户端已经启动\r\n");
	char sendBuf[]="你好\r\n";

	if(sendto(socketCli,sendBuf,sizeof(sendBuf),0,(sockaddr*)&addrSer,len)!=0)	//发送信息
	{
		recvfrom(socketCli,buff,10,0,(sockaddr*)&addrCli,&len);		//接收信息
		printf("服务器说：%s\r\n",buff);
		closesocket(socketCli);					//关闭套接字
		WSACleanup();						//释放套接字库
	}

	if(getchar())							//如果有输入，则关闭程序
	{
		return 0;						//正常结束程序
	}
	else
	{
		Sleep(100);						//应用程序睡眠
	}
}
