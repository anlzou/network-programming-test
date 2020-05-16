//Download by www.cctry.com
#include <windows.h>							//包含头文件
#include <stdio.h>

DWORD WINAPI myfun1(LPVOID lpParameter);//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter);
HANDLE hevent;									//定义全局变量hevent
int a=0;										//定义全局变量a

int main()
{	
	HANDLE h1,h2;									//定义线程句柄
	hevent=::CreateEvent(NULL,false,false,NULL);
	::SetEvent(hevent);
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);	//创建线程1
	printf("线程1开始运行！\r\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);	//创建线程2
	printf("线程2开始运行！\r\n");
	::CloseHandle(h1);								//关闭线程句柄对象
	::CloseHandle(h2);
	::Sleep(10000);									//程序睡眠10秒
	return 0;
}

DWORD WINAPI myfun1(LPVOID lpParameter) 		//线程函数1
{
	while(1)
	{
		::WaitForSingleObject(hevent,INFINITE);		//请求事件对象
		if(a<10000)
		{
			a+=1;											//变量自加
			::Sleep(1000);									//线程睡眠1秒
			printf("线程1：%d\r\n",a);					//输出变量
			::SetEvent(hevent);							//设置事件对象为有信号状态
		}
		else
		{
			::SetEvent(hevent);							//设置事件对象为有信号状态
			break;										//跳出循环
		}
	}
    return 0;	
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//线程函数2
{
	while(1)
	{
		::WaitForSingleObject(hevent,INFINITE);		//请求事件对象
		if(a<10000)
		{
			a+=1;
			::Sleep(1000);
			printf("线程2：%d\r\n",a);					//输出变量
			::SetEvent(hevent);
		}
		else
		{
			::SetEvent(hevent);							//设置事件对象为有信号状态
			break;										//跳出循环
		}
	}
    return 0;									//线程正常退出
}
