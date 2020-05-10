<!--
 * @Date        : 2020-05-09 18:29:49
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-10 15:28:06
 * @FilePath    : \tcp-socket\README.md
 * @Describe    : 
 -->
# tcp-socket

## 服务端
tcpServer.cpp

### 注意问题
#1 <code>#include <winsock2.h></code> 要在 <code>#include <windows.h></code> 前面，否则编译不通过。

#2 代码中使用中文，编译后运行出现乱码，未解决。[解决方法一：未成功](https://blog.csdn.net/ME__WE/article/details/86478291?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase)

#3 如果编译出现 <code>undefined reference to `__imp_xxx'</code> 则需要使用CMD手动编译，添加 <code>-lwsock32</code> 参数。

## 客户端
tcpClient.cpp

### 注意问题
#4 注意事项和服务端一样。

## 运行
#3 进入src/目录下，使用CMD编译
```
g++ tcpServer.cpp -lwsock32 -o Server.exe
```

#4 进入src/目录下，使用CMD编译
```
g++ tcpClient.cpp -lwsock32 -o Client.exe
```

## 更新日志
>### V1.0.0
>>#### release-v1
#### 2020年5月9日
- 服务端和客户端连接成功，不可以相互通信。

>### V2.0.0
>>#### release-v2
#### 2020年5月9日
- 服务端和客户端单行通信。[教程地址](http://e-learning.51cto.com/video/82847)

#### 2020年5月10日
- 补充编译参数