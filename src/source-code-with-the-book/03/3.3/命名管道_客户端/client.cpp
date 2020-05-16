//Download by www.cctry.com
#include<windows.h>								//包含头文件
#include<stdio.h>

int main()
{
	HANDLE hpip;
	OVERLAPPED ovi={0};	
	char buf[]="命名管道测试程序123";							//定义数据缓冲区
	DWORD readbuf;											//定义结构体变量
	printf("正在连接命名管道！\r\n");
	if(WaitNamedPipe("\\\\.\\pipe\\pipename", NMPWAIT_WAIT_FOREVER))
		//连接命名管道
	{
		//打开指定命名管道
		hpip=CreateFile("\\\\.\\pipe\\pipename", 
			GENERIC_READ| GENERIC_WRITE,0,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);
		if(hpip==INVALID_HANDLE_VALUE)						//打开命名管道失败
		{
			printf("打开命名管道失败\r\n");
		}
		else
		{								
			if(WriteFile(hpip,buf,sizeof(buf),&readbuf,NULL))		//写入数据到管道
			{
				printf("数据写入成功\r\n");								//提示信息
			}
			else
			{
				printf("数据写入失败\r\n");
			}
		}
	}
	else
	{
		printf("连接命名管道失败\r\n");							//提示信息
	}
	return 0;
}
