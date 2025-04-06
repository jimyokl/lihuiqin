#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/socket.h>
#include <ifaddrs.h>
// IPv4 多播地址范围: 224.0.0.0-239.255.255.255
// 224.0.0.0-224.0.0.255：用于“本地网络”多播。该地址段的多播数据包仅在本地子网内传播，不会转发到其他路由器。
// 224.0.1.0-233.255.255.255：通常用于组织级别的多播，允许数据包跨越多个子网。
// 233.0.0.0-233.255.255.255：由“源特定多播（SSM）”使用，是为了通过特定的源地址发送多播而预留的。
// 239.0.0.0-239.255.255.255：管理员分配的多播地址（Administratively Scoped Multicast），“私有”范围，组织内部的多播通信，
                            //但不能在公共互联网上使用，这些地址仅在本地网络或特定的自治域（例如公司内网）内使用。
                            // 239.255.0.1 被视为一个私有多播地址, 非常适合用来测试、实验或者在公司内部使用
int main() {
    int sock;
    struct sockaddr_in addr;
    char *multicast_ip = "239.255.0.1";
    int port = 12345;
    char *message = "Hello, multicast!";
    const char *interface_name = "eth0";  // 可修改为 eno1、ens33 等实际网卡名
    // 获取接口对应的 IP 地址
    struct in_addr local_interface;
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1)    //getifaddrs() 遍历本地网卡。
    {
        perror("getifaddrs"); exit(1);
    }
    int found = 0;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        if (ifa->ifa_addr->sa_family == AF_INET && strcmp(ifa->ifa_name, interface_name) == 0)//找到eth0的IP地址
        {
            local_interface = ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            found = 1;
            break;
        }
    }
    freeifaddrs(ifaddr);
    if (found) 
    {
        printf("Interface %s has IP address: %s\n", interface_name, inet_ntoa(local_interface));
    }else{
        fprintf(stderr, "Interface %s not found or has no IPv4 address.\n", interface_name); exit(1);
    }
    // 创建 UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) 
    {
        perror("socket"); exit(1);
    }
    // 设置用于发送多播的本地接口，用提取到的地址设置 IP_MULTICAST_IF。
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, &local_interface, sizeof(local_interface)) < 0) {
        perror("setsockopt IP_MULTICAST_IF"); exit(1);
    }
    // 设置目标地址（多播组）
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(multicast_ip);
    // 发送多播消息
    if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        perror("sendto err"); exit(1);
    }
    printf("Multicast message sent: %s (via %s [%s])\n", message, interface_name, inet_ntoa(local_interface));
    close(sock);
    return 0;
}
