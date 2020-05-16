//Download by www.cctry.com
#include <stdio.h>
#include <afxmt.h>

DWORD WINAPI myfun1(LPVOID lpParameter);	//声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter);
CCriticalSection m_Sec;									//定义全局变量m_Sec
int a=0;
												//定义全局变量a
int main()
{	
	HANDLE h1,h2;											//定义线程句柄
	h1=::CreateThread(NULL,0,myfun1,NULL,0,NULL);			//创建线程1
	printf("线程1开始运行！\r\n");
	h2=::CreateThread(NULL,0,myfun2,NULL,0,NULL);			//创建线程2
	printf("线程2开始运行！\r\n");
	::CloseHandle(h1);										//关闭线程句柄对象
	::CloseHandle(h2);
	::Sleep(10000);											//程序睡眠10秒
	return 0;
}
DWORD WINAPI myfun1(LPVOID lpParameter) 				//线程函数1
{
	m_Sec.Lock();										//锁定临界区
	a+=1;													//变量加1
	printf("%d\n",a);										//输出变量
	m_Sec.Unlock();								//对临界区进行解锁
	return 0;
}
DWORD WINAPI myfun2(LPVOID lpParameter) 		//线程函数2
{
	m_Sec.Lock();								//锁定临界区
	a+=1;											//变量加1
	printf("%d\n",a);								//输出变量
	m_Sec.Unlock();								//对临界区进行解锁
	return 0;
}
