#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/socket.h>
// IPv4 多播地址范围: 224.0.0.0-239.255.255.255
// 224.0.0.0-224.0.0.255：用于“本地网络”多播。该地址段的多播数据包仅在本地子网内传播，不会转发到其他路由器。
// 224.0.1.0-233.255.255.255：通常用于组织级别的多播，允许数据包跨越多个子网。
// 233.0.0.0-233.255.255.255：由“源特定多播（SSM）”使用，是为了通过特定的源地址发送多播而预留的。
// 239.0.0.0-239.255.255.255：管理员分配的多播地址（Administratively Scoped Multicast），“私有”范围，组织内部的多播通信，
                            //但不能在公共互联网上使用，这些地址仅在本地网络或特定的自治域（例如公司内网）内使用。
                            // 239.255.0.1 被视为一个私有多播地址, 非常适合用来测试、实验或者在公司内部使用
int main()    //基于UDP多播（Multicast）发送数据,通过socket向一个多播组发送"Hello, multicast!"
{
    int sock;
    struct sockaddr_in addr;
    char *multicast_ip = "239.255.0.1";
    int port = 12345;
    char *message = "Hello, multicast!";
    //const char *interface_name = "eth0";  // 你可以根据本机网卡改成 eno1、ens33 等
    //创建UDP socket：AF_INET: 使用 IPv4。
    sock = socket(AF_INET, SOCK_DGRAM, 0); //SOCK_DGRAM: 数据报socket（即UDP）,0:默认协议。
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    // 绑定特定接口用于发送（可选）, 多播是“一对多”的通信，需要从一个网卡发出去，默认可能会失败，因此手动设置接口
    
    struct in_addr local_interface;
    memset(&local_interface, 0, sizeof(local_interface));
    local_interface.s_addr = inet_addr("172.31.55.73");  //本地网卡 IP 地址，须和要加入的多播组在同一网段或网络可达。
    // IP_MULTICAST_IF: 这个选项让你告诉系统“从哪个本地 IP 发送这条多播消息”。
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, &local_interface, sizeof(local_interface)) < 0) 
    {
        perror("setsockopt IP_MULTICAST_IF");
        exit(1);
    }

    // 设置目标地址（多播组）, 设置一个 IPv4 地址结构体：AF_INET: IPv4, port: 要发送的端口, 
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(multicast_ip);//inet_addr(multicast_ip), 目标多播IP，multicast_ip是239.255.0.1
    // 多播 IP 地址范围是：224.0.0.0 ~ 239.255.255.255

    // 发送多播消息, 向指定的多播地址和端口发送数据。sendto() 是用于无连接的UDP发送的标准方式
    if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        perror("sendto err");  exit(1);
    }
    printf("Multicast message sent: %s\n", message);
    close(sock);
    return 0;
}