/***
 * @Date        : 2020-05-09 19:06:39
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-09 19:08:31
 * @FilePath    : \tcp-socket\src\tcpClient.cpp
 * @Describe    :
 */

#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib, "WS2_32.lib")  //显示连接套接字

using namespace std;

int main() {
    WSADATA data;             //定义WSADATA结构体对象
    WORD w = MAKEWORD(2, 0);  //定义版本号
    ::WSAStartup(w, &data);   //初始化套接字库
    SOCKET s;                 //定义连接套接字句柄
    char sztext[10] = {0};
    s = ::socket(AF_INET, SOCK_STREAM, 0);  //创建TCP套接字
    sockaddr_in addr;                       //定义套接字地址结构
    addr.sin_family = AF_INET;              //初始化地址结构
    addr.sin_port = htons(75);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    printf("Client started.\r\n");  //输出提示信息
    ::connect(s, (sockaddr*)&addr, sizeof(addr));
    ::recv(s, sztext, sizeof(sztext), 0);
    printf("%s\r\n", sztext);
    ::closesocket(s);  //关闭套接字句柄
    ::WSACleanup();    //如果有输入，则关闭程序
    if (getchar()) {
        return 0;  //正常结束程序
    } else {
        ::Sleep(100);  //程序休眠
    }
    return 0;
}