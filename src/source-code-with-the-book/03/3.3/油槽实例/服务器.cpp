//Download by www.cctry.com
#include<windows.h>											//包含头文件
#include<stdio.h>

int main()														//主函数
{
	HANDLE mail;												//定义邮槽句柄
	//创建邮槽
	mail=CreateMailslot("\\\\.\\mailslot\\my",0,MAILSLOT_WAIT_FOREVER,NULL);
	
	if(mail==INVALID_HANDLE_VALUE)								//判断邮槽句柄
	{
		printf("创建邮槽失败！\r\n");								//提示信息
		return 0;
	}
	else
	{
		printf("创建邮槽成功，正在读取数据……！\r\n");
		char text[200];												//定义字符数组
		DWORD readtext;												//获取实际读取值
		while(1)
		{
			
			if(ReadFile(mail,text,200,&readtext,NULL))					//读取数据
			{
				printf(text);												//显示数据
			}
		}
	}
	Sleep(100000);
	CloseHandle(mail);
	return 0;
}
