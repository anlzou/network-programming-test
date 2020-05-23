//Download by www.cctry.com
#include <windows.h>							//包含头文件
#include <stdio.h>

DWORD WINAPI myfun1(LPVOID lpParameter );//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter );

static int a1=0;								//定义全局变量并初始化
CRITICAL_SECTION Section;						//定义临界区对象

int main()										//主函数
{

	InitializeCriticalSection(&Section); 			//初始化临界区对象

	HANDLE h1,h2;									//定义线程句柄
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);	//创建线程1
	printf("线程1开始运行！\r\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);	//创建线程2
	printf("线程2开始运行！\r\n");
	::CloseHandle(h1);								//关闭线程句柄对象
	::CloseHandle(h2);

	::Sleep(10000);									//程序睡眠10秒
	printf("正常退出程序请按\r\n");
	while(1)
	{
		if(getchar()=='q')								//如果用户输入字符q
		{
			DeleteCriticalSection(&Section);			//删除临界区对象
			return 0;
		}
	}
}

DWORD WINAPI myfun1(LPVOID lpParameter) 		//线程函数1
{
	while(1)							
	{
		EnterCriticalSection(&Section);			//进入临界区
		a1++;										//变量自加
		if(a1<10000)								//设置变量a1小于10000
		{
			//::Sleep(1000);								//程序睡眠1秒
			printf("线程1正在计数%d\r\n",a1);
			LeaveCriticalSection(&Section);				//离开临界区
		}
		else										//如果变量大于10000
		{
			LeaveCriticalSection(&Section);			//离开临界区
			break;									//跳出循环
		}
	}
	return 0;
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//线程函数2
{
	while(1)
	{
		EnterCriticalSection(&Section);		//进入临界区
		a1++;
		if(a1<10000)
		{
			//::Sleep(1000);							//程序睡眠1秒
			printf("线程2正在计数%d\r\n",a1);
			LeaveCriticalSection(&Section);				//离开临界区
		}
		else
		{
			LeaveCriticalSection(&Section);			
			break;
		}
	}
	return 0;									//线程函数返回0
}
