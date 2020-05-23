//Download by www.cctry.com
#include <windows.h>							//包含头文件
#include <stdio.h>

DWORD WINAPI myfun1(LPVOID lpParameter);//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter);
HANDLE hmutex;
int a=0;										//定义全局变量a

int main()
{	
	hmutex=::CreateMutex(NULL,FALSE,NULL);			//创建互斥对象并返回其句柄
	HANDLE h1,h2;									//定义线程句柄
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
		::WaitForSingleObject(hmutex,INFINITE);		//请求互斥对象
		if(a<10000)
		{
			a+=1;											//变量自加
			::Sleep(1000);									//线程睡眠1秒
			printf("线程1：%d\r\n",a);
			::ReleaseMutex(hmutex);						//释放互斥对象句柄
		}
		else
		{
			::ReleaseMutex(hmutex);							//释放互斥对象句柄
			break;										//跳出循环
		}
	}
    return 0;								
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//线程函数2
{
	while(1)
	{
		::WaitForSingleObject(hmutex,INFINITE);		//请求互斥对象
		if(a<10000)
		{
			a+=1;
			::Sleep(1000);
			printf("线程2：%d\r\n",a);					//输出变量
			::ReleaseMutex(hmutex);						//释放互斥对象句柄
		}
		else
		{	
			::ReleaseMutex(hmutex);						//释放互斥对象句柄
			break;										//跳出循环
		}
	}
    return 0;									//线程正常退出
}
