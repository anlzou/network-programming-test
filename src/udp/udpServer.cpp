/***
 * @Date        : 2020-05-12 09:34:53
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-12 09:36:20
 * @FilePath    : \tcp-socket\src\udp\updServer.cpp
 * @Describe    :
 */
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib, "WS2_32.lib")
using namespace std;

int main() {
    WSADATA data;
    WORD w = MAKEWORD(2, 2);
    WSAStartup(w, &data);

    SOCKET sockSer;
    sockSer = socket(AF_INET, SOCK_DGRAM, 0);
    SOCKADDR_IN addrSer, addrCli;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(5050);
    addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    bind(sockSer, (SOCKADDR*)&addrSer, sizeof(SOCKADDR));

    char sendbuf[256];
    char recvbuf[256];
    int len = sizeof(SOCKADDR);

    while (1) {
        recvfrom(sockSer, recvbuf, 256, 0, (SOCKADDR*)&addrCli, &len);
        cout << "Cli:>" << recvbuf << endl;

        cout << "Ser:>";
        cin >> sendbuf;
        if (strcmp(sendbuf, "quit") == 0) break;
        sendto(sockSer, sendbuf, strlen(sendbuf) + 1, 0, (SOCKADDR*)&addrCli,
               len);
    }

    closesocket(sockSer);
    WSACleanup();
    return 0;
}