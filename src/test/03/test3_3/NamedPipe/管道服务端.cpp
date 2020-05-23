#include<iostream>
#include<windows.h>

using namespace std;

int mainxx(){
	HANDLE hpip;
	OVERLAPPED ovi = {0};
	char buf[200];
	DWORD readbuf;
	hpip = CreateNamedPipe("\\\\.\\pip\\pipename",PIPE_ACCESS_DUPLEX,PIPE_TYPE_BYTE,PIPE_UNLIMITED_INSTANCES,1024,1024,0,NULL);
	cout<<"create sucess"<<endl;

	cout<<"正在等待客户端的连接。。。"<<endl;
	if(ConnectNamedPipe(hpip,&ovi)){
		cout<<"客户端连接成功!!!!!"<<endl;
		cout<<"正在读取数据"<<endl;
		if(ReadFile(hpip,buf,200,&readbuf,NULL)){
			cout<<"读取数据成功！！！！！<<endl";
			cout<<"数据为："<<buf<<endl;
		}else{
			cout<<"读取数据失败！！！！！！！！";
		}
	}
	return 0;
}