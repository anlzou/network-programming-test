/***
 * @Date        : 2020-05-12 09:35:18
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-12 18:25:31
 * @FilePath    : \tcp-socket\src\udp\udpClient.cpp
 * @Describe    :
 */
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")  //引用连接套接字库
using namespace std;

int main() {
    WSADATA data;
    WORD w = MAKEWORD(2, 2);

    SOCKET sockCli;
    sockCli = socket(AF_INET, SOCK_DGRAM, 0);

    SOCKADDR_IN addrSer;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(5050);
    addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    char sendbuf[256];
    char recvbuf[256];
    int len = sizeof(SOCKADDR);
    while (1) {
        cout << "Cli:>";
        cin >> sendbuf;
        if (strcmp(sendbuf, "quit") == 0) break;
        sendto(sockCli, recvbuf, strlen(sendbuf) + 1, 0, (SOCKADDR*)&addrSer,
               len);

        recvfrom(sockCli, recvbuf, 256, 0, (SOCKADDR*)&addrSer, &len);
        cout << "Ser:>" << recvbuf << endl;
    }
    closesocket(sockCli);
    WSACleanup();

    return 0;
}