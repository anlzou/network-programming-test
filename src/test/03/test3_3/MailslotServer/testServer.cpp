#include<iostream>
#include<windows.h>

using namespace std;

int main(){
	HANDLE mail;
	mail = CreateMailslot("\\\\.\\mailslot\\my",0,MAILSLOT_WAIT_FOREVER,NULL);

	if(mail == INVALID_HANDLE_VALUE){
		cout<<"创建失败";
		return 0;
	}else{
		cout<<"创建成功，正在读取数据..."<<endl;
		char text[200];
		DWORD readtext;
		while(1){
			if(ReadFile(mail,text,200,&readtext,NULL)){
				cout<<text;
			}
		}
	}
	Sleep(10000);
	CloseHandle(mail);
	return 0;
}