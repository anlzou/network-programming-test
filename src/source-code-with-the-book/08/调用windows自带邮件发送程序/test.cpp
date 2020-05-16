//Download by www.cctry.com
#include <stdio.h>								//调用相关头文件
#include <windows.h>

int main()											//主函数				
{
	int i=0;										//定义循环变量
	char ch;										//定义字符，用于获取用户输入
	printf("确认打开邮件收发程序!(Y/N)\n");			//提示用户
	scanf(&ch);										//输入指令
	if(ch && 'Y')									//判断输入指令
	{
		printf("邮件收发程序正在打开！请稍候……\n");	//提示用户
		while(i<=10000000)							//循环，模拟计算机工作
		{
			i+=1;													
		}
		ShellExecute(NULL,NULL,"mailto:lymlrl@163.com",
			NULL,NULL,SW_SHOW);								//调用函数启动邮件收发程序
		printf("邮件收发程序已经打开，请使用！\n");
	}
	else
	{
		printf("谢谢使用!\n");  
	}
	return 0;
}
