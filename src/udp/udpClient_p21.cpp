/***
 * @Date        : 2020-05-12 22:36:12
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-12 22:55:43
 * @FilePath    : \tcp-socket\src\udp\udpClient_p21.cpp
 * @Describe    :
 */
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA data;
    WORD w = MAKEWORD(2, 0);
    WSAStartup(w, &data);
    SOCKET sockSer;
    sockSer = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addrSer, addrCli;
    int len = sizeof(addrCli);
    char buff[256] = {0};

    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(75);
    addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    cout << "UDP Client is start." << endl;
    char sztext[] = "hello";

    if (sendto(sockSer, sztext, sizeof(sztext), 0, (sockaddr*)&addrSer, len)) {
        recvfrom(sockSer, buff, 256, 0, (sockaddr*)&addrCli, &len);
        cout << "Server send:>" << buff << endl;
        closesocket(sockSer);
        WSACleanup();
    }
    if (getchar()) {
        return 0;
    } else {
        Sleep(100);
    }
}