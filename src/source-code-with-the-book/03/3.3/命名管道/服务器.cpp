//Download by www.cctry.com
#include<windows.h>								//包含头文件
#include<stdio.h>

int main()
{
	HANDLE hpip;								//定义命名管道句柄
	OVERLAPPED ovi={0};							//定义结构体变量
	char buf[200];								//定义数据缓冲区
	DWORD readbuf;									//获取实际读取字节数
	hpip=CreateNamedPipe("\\\\.\\pipe\\pipename", PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE, PIPE_UNLIMITED_INSTANCES,1024,1024,0,
		NULL);					 	//创建命名管道 
	printf("创建管道成功，正在等待客户端连接！\r\n");
	if(::ConnectNamedPipe(hpip,&ovi))				//等待客户端的连接请求
	{
		printf("客户端连接成功！\r\n");
		printf("正在读取数据！\r\n");					//提示信息
		if(ReadFile(hpip,buf,200,&readbuf,NULL))		//读取管道数据
		{
			printf("数据读取成功\r\n");						//提示信息
			printf("读取的数据是：%s\r\n",buf);
		}
		else
		{
			printf("数据读取失败\r\n");
		}
	}
	return 0;
}
