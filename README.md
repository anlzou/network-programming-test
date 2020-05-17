<!--
 * @Date        : 2020-05-09 18:29:49
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-17 15:23:04
 * @LastEditTime: 2020-05-12 23:13:29
 * @FilePath    : \socket\README.md
 * @Describe    : 
 -->
# 网络编程

## tcp/

### 服务端
[tcpServer.cpp](./src/tcp/tcpServer.cpp)

### 客户端
[tcpClient.cpp](./src/tcp/tcpClient.cpp)

### 注意问题
1. <code>#include <winsock2.h></code> 要在 <code>#include <windows.h></code> 前面，否则编译不通过。

2. 代码中使用中文，编译后运行出现乱码，未解决。[解决方法一：未成功](https://blog.csdn.net/ME__WE/article/details/86478291?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase)

3. 如果编译出现 <code>undefined reference to `__imp_xxx'</code> 则需要使用CMD手动编译，添加 <code>-lwsock32</code> 参数。

### 运行
#### CMD 编译
**<code>服务端</code>** 进入 <code>*.cpp</code> 目录下，使用CMD编译
```
g++ tcpServer.cpp -lwsock32 -o Server.exe
```

**<code>客户端</code>** 进入 <code>*.cpp</code> 目录下，使用CMD编译
```

g++ tcpClient.cpp -lwsock32 -o Client.exe
```

------

## udp/
#1 课本 

- Server：[udpServer_p20.cpp](src/udp/udpServer_p20.cpp)

- Client：[udpClient_p21.cpp](src/udp/udpClient_p21.cpp)

#2 [Socket 网络基本编程视频课程](http://e-learning.51cto.com/course/4951)

- Server：[udpServer.cpp](src/udp/udpServer.cpp)

- Client：[udpClient.cpp](src/udp/udpClient.cpp)

------
## ftp/
coding...

------
## test/
- 对课本实例进行编写测试

【环境】vc++6.0

------
## restructure-by-vs2019/
- 对课本实例进行重构

【环境】vs2019

------
## restructure-by-python3/
计划在...
- 对课本实例进行重构

【环境】python3

-------
## 更新日志


>### master、develop
#### 2020年5月9日
- 服务端和客户端单行通信。[教程地址](http://e-learning.51cto.com/video/82847)

#### 2020年5月10日
- 补充编译参数

#### 2020年5月16日
- 修改项目框架
- 添加书本源码 source-code-with-book/

#### 2020年5月17日
- 添加文件夹
  - test/ 在vc++6.0 环境下调试
  - restructure-by-vs2019/ 在vs2019环境下重构