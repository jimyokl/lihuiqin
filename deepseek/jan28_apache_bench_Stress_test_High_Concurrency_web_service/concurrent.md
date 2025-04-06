
sudo yum install libevent-devel
rpm -q libevent //显示版本号
pkg-config --modversion libevent //显示版本号
ls /usr/include/event2/event.h //检查头文件是否已正确安装
gcc -o concurrent concurrent.c -levent
./concurrent
ps aux | grep c_server  //服务进程是否运行：
netstat -tlnp | grep 8080  # 应显示 LISTEN 状态

# 查看防火墙状态
sudo firewall-cmd --state
# 开放端口（临时）
sudo firewall-cmd --add-port=8080/tcp
# 永久生效
sudo firewall-cmd --permanent --add-port=8080/tcp
sudo firewall-cmd --reload

sudo tcpdump -i any port 8080 -nn -v  //tcpdump 抓取网络流量：
192.168.112.1.63179 > 192.168.112.135.8080: Flags [P.], cksum 0x1cf9 (correct), seq 1:492, ack 1, win 512, length 491: HTTP, length: 491
	GET / HTTP/1.1
	Host: 192.168.112.135:8080
	Connection: keep-alive
	Cache-Control: max-age=0
	Upgrade-Insecure-Requests: 1
	User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36
	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
	Accept-Encoding: gzip, deflate
	Accept-Language: en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7,vi;q=0.6

192.168.112.135.8080 > 192.168.112.1.63179: Flags [P.], cksum 0x628d (incorrect -> 0xdcab), seq 1:154, ack 492, win 254, length 153: HTTP, length: 153
	HTTP/1.1 200 OK
	Date: Mon, 27 Jan 2025 16:51:41 GMT
	Content-Length: 32
	Content-Type: text/html; charset=ISO-8859-1

1. 最末的代码是一个使用 C（看.c文件）/C++ 实现高并发 Web 后台的解决方案，采用 Reactor 模式 + epoll 多路复用技术
2. 编译运行: 
gcc c_server.c -o c_server -levent                               ./c_server
g++ cpp_server.cpp -o cpp_server -lboost_system -pthread         ./cpp_server
2. 性能优化配置：
# 调整文件描述符限制
echo "* soft nofile 1000000" >> /etc/security/limits.conf
echo "* hard nofile 1000000" >> /etc/security/limits.conf

# 网络参数优化
sysctl -w net.core.somaxconn=65535
sysctl -w net.ipv4.tcp_max_syn_backlog=65535
sysctl -w net.ipv4.tcp_tw_reuse=1

架构特点：
1. 事件驱动架构：基于 epoll/kqueue 实现 IO 多路复用
2. 非阻塞 IO：使用异步处理模式，避免线程阻塞
3. 内存池技术：可配合内存池减少内存碎片
4. 零拷贝技术：优化网络数据传输效率
5. 连接复用：支持 Keep-Alive 保持长连接

压力测试：
C:\Users\yan>ab -n 100000 -c 10000 http://192.168.112.135:8080/
Concurrency Level:      10000
Time taken for tests:   250.706 seconds
Complete requests:      100000              Failed requests:        0
Total transferred:      9600000 bytes       HTML transferred:       3200000 bytes
Requests per second:    398.87 [#/sec] (mean)
Time per request:       25070.628 [ms] (mean)
Time per request:       2.507 [ms] (mean, across all concurrent requests)
Transfer rate:          37.39 [Kbytes/sec] received

# 查看 CPU/内存使用
top -H -p $(pgrep c_server)
# 网络连接监控
watch -n 1 "netstat -ant | grep ':8080' | awk '{print \$6}' | sort | uniq -c"
# 文件描述符监控
watch -n 1 "ls /proc/$(pgrep c_server)/fd | wc -l"

建议扩展方向：
1. 加入线程池实现半同步/半异步模式
2. 集成 Prometheus 监控指标
3. 实现 HTTP/2 协议支持
4. 添加 TLS 加密支持
5. 开发 RESTful API 路由功能
6. 集成 Redis/Mysql 连接池

两种实现的对比：

| 特性           | C (libevent)          | C++ (Boost.Asio)       |
|--------------|-----------------------|------------------------|
| 性能          | 更高                   | 稍低                   |
| 开发效率       | 较低                   | 较高                   |
| 内存管理       | 手动管理                | RAII 自动管理          |
| 跨平台性       | 优秀                   | 优秀                   |
| 协议支持       | 需自行实现              | 内置更多协议支持         |
| 适用场景       | 极致性能要求            | 快速开发复杂业务逻辑      |

可根据具体需求选择合适的实现方案，对于需要极致性能的场景推荐 C 语言方案，对于需要快速开发复杂业务逻辑的场景推荐 C++ 方案。

// C++ 版本 (基于 Boost.Asio)
#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket) : socket_(std::move(socket)) {}
    
    void start() {
        do_read();
    }

private:
    void do_read() {
        auto self(shared_from_this());
        socket_.async_read_some(buffer(data_),
            [this, self](boost::system::error_code ec, size_t length) {
                if (!ec) {
                    std::string response = 
                        "HTTP/1.1 200 OK\r\n"
                        "Content-Length: 28\r\n"
                        "Content-Type: text/plain\r\n\r\n"
                        "Hello, High Performance Server!";
                    do_write(response);
                }
            });
    }

    void do_write(const std::string& response) {
        auto self(shared_from_this());
        async_write(socket_, buffer(response),
            [this, self](boost::system::error_code ec, size_t) {
                if (!ec) {
                    boost::system::error_code ign_ec;
                    socket_.shutdown(tcp::socket::shutdown_both, ign_ec);
                }
            });
    }

    tcp::socket socket_;
    char data_[1024];
};

class Server {
public:
    Server(io_context& io, short port)
        : acceptor_(io, tcp::endpoint(tcp::v4(), port)) {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket))->start();
                }
                do_accept();
            });
    }

    tcp::acceptor acceptor_;
};

int main() {
    try {
        io_context io;
        Server server(io, 8080);
        std::cout << "Server running on port 8080..." << std::endl;
        io.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}



