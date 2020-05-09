/***
 * @Date        : 2020-05-09 16:42:42
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-09 17:05:08
 * @FilePath    : \tcp-socket\tcpClient.cpp
 * @Describe    :
 */
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "WS2_32.lib")  //显示连接套接字库
using namespace std;

int main() {                       //主函数开始
    WSADATA data;                  // 定义WSADATA结构体
    WORD w = MAKEWORD(2, 0);       //定义版本号
    char sztext[] = "Welcome!\r\n";  //定义初始化发送到客户端的字符数组
    ::WSAStartup(w, &data);        //初始化套接字
    SOCKET s, s1;  //定义连接套接字和数据收发套接字句柄
    s = ::socket(AF_INET, SOCK_STREAM, 0);  //创建TCP套接字
    sockaddr_in addr, addr2;                //定义套接字地址结构
    int n = sizeof(addr2);                  //获取套接字地址结构大小
    addr.sin_family = AF_INET;              //初始化地址结构
    addr.sin_port = htons(75);
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    ::bind(s, (sockaddr*)&addr, sizeof(addr));  //绑定套接字
    ::listen(s, 5);                             //监听套接字
    printf("Server started.\r\n");           //输出提示信息

    while (true) {
        s1 = ::accept(s, (sockaddr*)&addr2, &n);  //接受连接请求
        if (s1 != NULL) {
            printf("%s Connected.\r\n", inet_ntoa(addr2.sin_addr));
            ::send(s1, sztext, sizeof(sztext), 0);  //向客户端发送字符数组
        }
        ::closesocket(s);
        ::closesocket(s1);
        ::WSACleanup;     //释放套接字库
        if (getchar()) {  //如果有输入，则关闭程序
            return 0;     //正常结束
        } else {
            ::Sleep(100);  //睡眠0.1秒
        }
    }
}
