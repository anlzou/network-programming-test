#include<iostream>
#include<windows.h>

using namespace std;

int main(){
	HANDLE hpip;
	OVERLAPPED ovi = {0};
	char buf[] = "命名管道测试程序";
	DWORD readbuf;
	cout<<"正在连接命名管道"<<endl;

	if(WaitNamedPipe("\\\\.\\pipe\\pipename",NMPWAIT_WAIT_FOREVER)){
		hpip = CreateFile("\\\\.\\pipe\\pipename",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
		if(hpip == INVALID_HANDLE_VALUE){
			cout<<"打开命名管道失败"<<endl;
		}else{
			if(WriteFile(hpip,buf,sizeof(buf),&readbuf,NULL)){
				cout<<"数据写入成功"<<endl;
			}else{
				cout<<"数据写入失败"<<endl;
			}
		}
	}else{
		cout<<"连接命令管道失败"<<endl;
	}
	return 0;
}