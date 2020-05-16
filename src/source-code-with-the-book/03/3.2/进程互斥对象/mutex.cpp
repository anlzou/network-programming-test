//Download by www.cctry.com
#include<windows.h>								//包含头文件
#include<stdio.h>

int main()												//主函数
{
	HANDLE hmutex;									//定义互斥对象句柄
	hmutex=::CreateMutex(NULL,true,"VC网络编程");	//创建互斥对象并返回其句柄
	if(hmutex)										//判断创建互斥对象是否成功
	{
		if(ERROR_ALREADY_EXISTS==GetLastError())		//获取错误
		{
			printf("只允许一个实例程序运行！\r\n");		//打印相关信息
		}
		else
		{
			printf("实例程序运行成功！\r\n");
		}
	}
	::ReleaseMutex(hmutex);						//释放互斥对象句柄
	::Sleep(100000);								//使程序睡眠100秒
	return 0;										//程序正常结束
}
