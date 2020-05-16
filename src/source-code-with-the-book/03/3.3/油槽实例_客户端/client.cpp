//Download by www.cctry.com
#include<windows.h>											//包含头文件
#include<stdio.h>

int main()														//主函数
{
	HANDLE mail2;												//定义邮槽句柄
	char text[]="您好，this is a message";						//初始化消息
	DWORD writetext;											//获取实际发送值
	mail2=CreateFile("\\\\.\\mailslot\\my",GENERIC_WRITE,FILE_SHARE_READ,
		NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	//打开文件
	if(INVALID_HANDLE_VALUE==mail2)	
	{
		printf("邮槽打开失败！\r\n");
	}
	else
	{		 
		if(WriteFile(mail2,text,sizeof(text),&writetext,NULL))	//写入数据
		{
			Sleep(1000);
			printf("数据写入成功\r\n");								//数据写入成功
		}
		else
		{
			printf("数据写入失败\r\n");
		}
		CloseHandle(mail2);											//关闭句柄
	}
	Sleep(10000);
	return 0;
}