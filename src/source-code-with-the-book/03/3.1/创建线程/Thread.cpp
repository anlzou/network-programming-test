//Download by www.cctry.com
#include <windows.h>								//包含相应头文件
#include <stdio.h>	
							
DWORD WINAPI myfun1(LPVOID lpParameter 	);			//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter 	);

int main()											//主函数
{
	HANDLE h1,h2;										//定义句柄变量
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);		//创建线程1
	printf("线程1开始运行！\r\n");						//输出线程1运行信息
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);		//创建线程2
	printf("线程2开始运行！\r\n");						//输出线程2运行信息
	::CloseHandle(h1);									//关闭线程句柄对象
	::CloseHandle(h2);
	while(1)
	{
		if(getchar()=='q')								//如果用户输入字符q
		{
			return 0;										//程序正常退出
		}
		else												//如果用户输入的字符不是q
		{
			::Sleep(100);									//程序睡眠
		}
	}
}

DWORD WINAPI myfun1(LPVOID lpParameter) 			//分别实现线程函数
{
	printf("线程1正在运行！\r\n");						//输出信息
	return 0;											//正常结束线程函数
}
DWORD WINAPI myfun2(LPVOID lpParameter) 
{
	printf("线程2正在运行！\r\n");
	return 0;
}
