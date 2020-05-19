/***
 * @Date        : 2020-05-12 22:35:53
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-12 22:44:04
 * @FilePath    : \tcp-socket\src\udp\udpServer_p20.cpp
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
    char sztext[] = "Welcome for you\r\n";
    WSAStartup(w, &data);

    SOCKET sockSer;
    sockSer = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addrSer, addrCli;
    int len = sizeof(addrCli);

    char buff[256] = {0};
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(75);
    addrSer.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(sockSer, (sockaddr*)&addrSer, sizeof(addrSer));
    cout << "UPD Server is start." << endl;

    while (1) {
        if (recvfrom(sockSer, buff, 256, 0, (sockaddr*)&addrCli, &len) != 0) {
            cout << inet_ntoa(addrCli.sin_addr) << " is connet." << endl;
            cout << "Cli send:>" << buff << endl;

            sendto(sockSer, sztext, sizeof(sztext), 0, (sockaddr*)&addrCli,
                   len);
            break;
        }
    }
    closesocket(sockSer);
    WSACleanup();

    if (getchar()) {
        return 0;
    } else {
        Sleep(100);
    }
}