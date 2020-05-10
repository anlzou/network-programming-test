/***
 * @Date        : 2020-05-10 12:17:54
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-10 14:52:19
 * @FilePath    : \tcp-socket\src\tcpServer.cpp
 * @Describe    :
 */
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")  //引用连接套接字库
using namespace std;

int main() {                        //主函数开始
    WSADATA data;                   // 定义WSADATA结构体
    WORD version = MAKEWORD(2, 0);  //定义版本号
    WSAStartup(version, &data);  //初始化套接字，使socket适配Windows平台

    SOCKET sockSer;  //定义连接套接字和数据收发套接字句柄
    sockSer = socket(AF_INET, SOCK_STREAM, 0);  //创建TCP套接字

    sockaddr_in addrSer, addrCli;  //定义套接字地址结构，服务端；客户端
    addrSer.sin_family =
        AF_INET;  //初始化地址结构；AF_INET:家族协议，默认2，internetwork：UDP，TCP
    addrSer.sin_port = htons(75);               //监听端口
    addrSer.sin_addr.S_un.S_addr = INADDR_ANY;  // inet_addr("127.0.0.1")

    bind(sockSer, (sockaddr *)&addrSer, sizeof(addrSer));  //绑定套接字
    listen(sockSer, 5);                                    //监听套接字

    // printf("Server started.\r\n");  //输出提示信息
    cout << "Server wait client connect..." << endl;

    SOCKET sockConn;  //客户端的连接
    int len = sizeof(SOCKADDR);
    sockConn = accept(sockSer, (SOCKADDR *)&addrCli, &len);

    if (sockConn == INVALID_SOCKET) {
        printf("Server Accept Client Connect Fail!\r\n");
        return 0;
    } else {
        printf("Server Accept Client Connect Success!\r\n");
    }

    char sendbuf[256];
    char recvbuf[256];
    while (1) {
        cout << "Server:>";
        cin >> sendbuf;
        if (strcmp(sendbuf, "quit") == 0) {
            break;
        }
        send(sockConn, sendbuf, strlen(sendbuf) + 1,
             0);  //+1=字符串\0; 0，代表默认方式发送
        recv(sockConn, recvbuf, 256, 0);        // 0，代表默认方式接受
        cout << "Client:>" << recvbuf << endl;  //输出客户端的内容
    }
    closesocket(sockSer);
    closesocket(sockConn);
    WSACleanup();
    return 0;
}
