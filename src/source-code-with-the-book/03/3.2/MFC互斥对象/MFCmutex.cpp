//Download by www.cctry.com
#include <afxmt.h>
#include <stdio.h>

DWORD WINAPI myfun1(LPVOID lpParameter);//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter);
CMutex hmutex(NULL,FALSE,NULL);				//定义全局互斥对象
int a=0;										//定义全局变量a

int main()
{	
	HANDLE h1,h2;									//定义线程句柄
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);	//创建线程1
	printf("使用CMutex 类实现线程同步\r\n");
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
		hmutex.Lock(INFINITE);						//锁定互斥对象
		if(a<10000)
		{
			a+=1;											//变量自加
			::Sleep(1000);									//线程睡眠1秒
			printf("线程1：%d\r\n",a);
			hmutex.Unlock();							//释放互斥对象
		}
		else
		{
			hmutex.Unlock();								//释放互斥对象
			break;										//跳出循环
		}
	}
    return 0;	
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//线程函数2
{
	while(1)
	{
		hmutex.Lock(INFINITE);						//锁定互斥对象
		if(a<10000)
		{
			a+=1;
			::Sleep(1000);
			printf("线程2：%d\r\n",a);					//输出变量
			hmutex.Unlock();							//释放互斥对象
		}
		else
		{	
			hmutex.Unlock();							//释放互斥对象
			break;										//跳出循环
		}
	}
    return 0;									//线程正常退出
}
