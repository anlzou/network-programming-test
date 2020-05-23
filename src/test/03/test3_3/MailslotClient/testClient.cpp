#include<iostream>
#include<windows.h>
#include<stdio.h>

using namespace std;

int main(){
	HANDLE mail2;
	char text[]= "hello my name is anlzou.";
	DWORD writetext;

	mail2 = CreateFile("\\\\.\\mailslot\\my",GENERIC_WRITE,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(INVALID_HANDLE_VALUE == mail2){
		cout<<"邮槽打开失败！"<<endl;
	}else{
		if(WriteFile(mail2,text,sizeof(text),&writetext,NULL)){
			Sleep(1000);
			cout<<"数据写入成功";
		}else{
			cout<<"数据写入失败";
		}

		CloseHandle(mail2);
	}
	Sleep(10000);
	return 0;
}