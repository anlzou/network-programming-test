/*** 
 * @Date        : 2020-05-09 19:06:39
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-09 22:10:09
 * @FilePath    : \tcp-socket\src\tcpClient.cpp
 * @Describe    : 
 */

#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib, "WS2_32.lib")  //显示连接套接字

using namespace std;

int main() {
    WSADATA data;             //定义WSADATA结构体对象
    WORD version = MAKEWORD(2, 0);  //定义版本号
    WSAStartup(version, &data);   //初始化套接字库
    SOCKET sockCli;                 //定义连接套接字句柄
    char sztext[10] = {0};
    sockCli = socket(AF_INET, SOCK_STREAM, 0);  //创建TCP套接字
    
    sockaddr_in addrSer;                       //定义套接字地址结构
    addrSer.sin_family = AF_INET;              //初始化地址结构
    addrSer.sin_port = htons(75);
    addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    int res = connect(sockCli, (sockaddr*)&addrSer, sizeof(addrSer));
    if (res != 0){
        cout<<"Client Connect Server Fail!"<<endl;
    }else{
        cout<<"Client Connect Server Success!"<<endl;
    }

    char sendbuf[256];
    char recvbuf[256];
    while (1)
    {
        recv(sockCli,recvbuf,256,0);
        cout<<"Ser:>"<<recvbuf<<endl;

        cout<<"Cli:>";
        cin>>sendbuf;
        if (strcmp(sendbuf,"quit") == 0){
            break;
        }
        send(sockCli,sendbuf,strlen(sendbuf)+1,0);
    }
    closesocket(sockCli);
    WSACleanup();
    return 0;
}