#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <net/if.h>
// IPv4 多播地址范围: 224.0.0.0-239.255.255.255
// 224.0.0.0-224.0.0.255：用于“本地网络”多播。该地址段的多播数据包仅在本地子网内传播，不会转发到其他路由器。
// 224.0.1.0-233.255.255.255：通常用于组织级别的多播，允许数据包跨越多个子网。
// 233.0.0.0-233.255.255.255：由“源特定多播（SSM）”使用，是为了通过特定的源地址发送多播而预留的。
// 239.0.0.0-239.255.255.255：管理员分配的多播地址（Administratively Scoped Multicast），“私有”范围，组织内部的多播通信，
                            //但不能在公共互联网上使用，这些地址仅在本地网络或特定的自治域（例如公司内网）内使用。
                            // 239.255.0.1 被视为一个私有多播地址, 非常适合用来测试、实验或者在公司内部使用
int main()          //use ip_mreqn to join a multicast group, UDP多播接收程序，加入一个多播组，接收该组的消息,并打印
{
    int sock;
    struct sockaddr_in addr;
    struct ip_mreqn mreqn;
    char *multicast_ip = "239.255.0.1";
    int port = 12345;

    // 创建UDP socket, AF_INET表示使用IPv4地址，SOCK_DGRAM表示使用数据报（即UDP）协议
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    // 设置SO_REUSEADDR 允许多个socket绑定到相同端口，这在多播中是必要的，因为多个进程可能需要接收同一组的消息
    // 允许多个套接字绑定到相同的地址和端口，通常用于多播或多进程监听同一端口的场景。
    int reuse = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt SO_REUSEADDR");
        exit(1);
    }
    // 绑定本地端口, 将套接字绑定到本地地址和端口    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY使得该套接字能够接收任何网络接口上的数据包，而不是特定的IP地址
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // 设置加入多播组
    memset(&mreqn, 0, sizeof(mreqn));
    mreqn.imr_multiaddr.s_addr = inet_addr(multicast_ip); // 多播组的IP

    // 让套接字加入了一个多播组 239.255.0.1（这是一个局部多播地址），并指定了接收该组消息的网卡接口（在这里是 eth0）。
    // 使用网卡名获取接口索引（如eth0）
    mreqn.imr_ifindex = if_nametoindex("eth0"); // 可根据系统改为对应接口，设置绑定的网卡接口
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreqn, sizeof(mreqn)) < 0)//IP_ADD_MEMBERSHIP选项表示加入多播组
    { 
        perror("setsockopt IP_ADD_MEMBERSHIP");
        exit(1);
    }
    printf("Joined multicast group %s on port %d\n", multicast_ip, port);
    // 使用 recvfrom 函数从套接字中接收数据, （示例只接收一次）。
    // 接收到的数据会被存储在 buffer 中，然后输出到控制台。recvfrom 返回的 n 是接收到的数据字节数。
    char buffer[1024];
    socklen_t addrlen = sizeof(addr);
    int n = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addrlen);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }
    close(sock); // 关闭套接字，释放资源。
    return 0;
}