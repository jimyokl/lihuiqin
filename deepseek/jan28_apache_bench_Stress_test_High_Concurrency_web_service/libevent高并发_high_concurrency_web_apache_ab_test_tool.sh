
###########################  -----------------------------------###########################  -----------------------------------###########################

测试 C 语言版本的高并发 Web 程序需要从功能验证、性能压测、资源监控等多个维度进行。以下是详细的测试方案：
### **一、基础功能测试**
#### 1. 手动请求验证
```bash
# 使用 curl 测试基础响应
curl -v http://localhost:8080

# 预期输出：
# > GET / HTTP/1.1
# < HTTP/1.1 200 OK
# < Content-Type: text/plain
# Hello, High Performance Server!
```

#### 2. 异常请求测试
```bash
# 测试非法请求方法
curl -X INVALID_METHOD http://localhost:8080

# 测试大请求头
curl -H "Large-Header: $(openssl rand -base64 5000)" http://localhost:8080
```
### **二、性能压力测试**
#### 1. 使用 ApacheBench (ab)
```bash
# 安装测试工具
sudo yum install httpd-tools

# 基础压力测试（10万请求，500并发）
ab -n 100000 -c 500 http://localhost:8080/

# 关键指标关注：
# - Requests per second (RPS)
# - Time per request
# - 90%/95%/99% 响应时间
# - 错误率 (Non-2xx/3xx responses)
```

#### 2. 使用 wrk (更高效的压测工具)
```bash
# 安装 wrk
git clone https://github.com/wg/wrk.git
cd wrk && make && sudo cp wrk /usr/local/bin

# 高级压测（12线程，4000连接，持续30秒）
wrk -t12 -c4000 -d30s --latency http://localhost:8080/

# 输出示例：
# Latency Distribution (HdrHistogram)
#  50.000%    2.34ms
#  90.000%    3.45ms
#  99.000%   12.56ms
```

### **三、系统资源监控**
#### 1. 实时资源查看
```bash
# 查看 CPU/内存使用
top -H -p $(pgrep c_server)

# 网络连接监控
watch -n 1 "netstat -ant | grep ':8080' | awk '{print \$6}' | sort | uniq -c"

# 文件描述符监控
watch -n 1 "ls /proc/$(pgrep c_server)/fd | wc -l"
```

#### 2. 火焰图分析 (CPU/Off-CPU)
```bash
# 安装 perf 和 FlameGraph
sudo yum install perf
git clone https://github.com/brendangregg/FlameGraph

# 采集 CPU 使用
perf record -F 99 -p $(pgrep c_server) -g -- sleep 60
perf script | ./FlameGraph/stackcollapse-perf.pl | ./FlameGraph/flamegraph.pl > cpu.svg

# 生成 Off-CPU 火焰图
sudo offcputime -df -p $(pgrep c_server) 60 | ./FlameGraph/flamegraph.pl > offcpu.svg
```

### **四、高级调试技巧**
#### 1. 内存泄漏检测
```bash
# 使用 Valgrind 检测
valgrind --leak-check=full --track-origins=yes ./c_server

# 输出示例：
# ==12345== HEAP SUMMARY:
# ==12345==   in use at exit: 0 bytes in 0 blocks
# ==12345==   total heap usage: 1,234 allocs, 1,234 frees
```

#### 2. 使用 GDB 调试
```bash
# 编译时添加调试符号
gcc -g c_server.c -o c_server_debug -levent

# 附加到运行进程
gdb -p $(pgrep c_server)

# 常用命令：
# (gdb) bt                  # 查看调用栈
# (gdb) info threads        # 查看线程状态
# (gdb) thread apply all bt # 所有线程堆栈
```

### **五、测试场景建议**
| 测试类型       | 测试方法                                                                 |
|----------------|--------------------------------------------------------------------------|
| 连接风暴测试   | 瞬间爆发 10 万连接，观察连接建立成功率                                   |
| 长连接保持测试 | 使用 `wrk` 开启 Keep-Alive，测试长连接复用性能                           |
| 极限压测       | 逐步增加并发直到出现错误，确定系统瓶颈（CPU/内存/网络/文件描述符）       |
| 故障恢复测试   | 模拟网络中断、进程崩溃，测试自动恢复能力                                 |

### **六、关键优化检查点**
1. **文件描述符限制**  
   ```bash
   # 查看当前限制
   cat /proc/$(pgrep c_server)/limits | grep 'Max open files'

   # 临时修改限制
   ulimit -n 1000000
   ```

2. **TCP 参数调优**  
   ```bash
   # 查看 backlog 队列
   ss -lnt | grep 8080

   # 优化建议：
   echo 65535 > /proc/sys/net/core/somaxconn
   sysctl -w net.ipv4.tcp_max_syn_backlog=65535
   ```

3. **内存碎片检查**  
   使用 `jemalloc` 替换默认内存分配器：
   ```bash
   sudo yum install jemalloc
   LD_PRELOAD=/usr/lib64/libjemalloc.so.1 ./c_server
   ```

### **七、自动化测试方案**
创建测试脚本 `test_benchmark.sh`：
```bash
#!/bin/bash

# 启动服务器
./c_server &
SERVER_PID=$!

# 等待服务启动
sleep 2

# 运行压测
ab -n 100000 -c 1000 http://localhost:8080/

# 清理
kill $SERVER_PID
```

通过持续集成工具（如 Jenkins）定期执行回归测试。

通过以上多维度测试，您可以全面验证服务器的：
- 协议兼容性（HTTP/1.1 规范）
- 资源泄漏情况（内存/连接泄漏）
- 极限负载下的稳定性
- 系统参数合理性（线程数/缓冲区大小）

[yan@localhost ~]$ sudo tcpdump -i any port 8080 -nn -v
dropped privs to tcpdump
tcpdump: listening on any, link-type LINUX_SLL (Linux cooked v1), capture size 262144 bytes
00:51:10.491117 IP (tos 0x0, ttl 128, id 3021, offset 0, flags [DF], proto TCP (6), length 41)
    192.168.112.1.63179 > 192.168.112.135.8080: Flags [.], cksum 0x8104 (correct), seq 2672728861:2672728862, ack 158757047, win 512, length 1: HTTP
00:51:10.491291 IP (tos 0x0, ttl 64, id 29767, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.112.135.8080 > 192.168.112.1.63179: Flags [.], cksum 0x6200 (incorrect -> 0xd71e), ack 1, win 245, options [nop,nop,sack 1 {0:1}], length 0
00:51:41.577937 IP (tos 0x0, ttl 128, id 3114, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.112.1.63202 > 192.168.112.135.8080: Flags [S], cksum 0x2a6c (correct), seq 4212971081, win 64240, options [mss 1460,nop,wscale 8,nop,nop,sackOK], length 0
00:51:41.578267 IP (tos 0x0, ttl 64, id 0, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.112.135.8080 > 192.168.112.1.63202: Flags [S.], cksum 0x6200 (incorrect -> 0x7b1e), seq 2571542231, ack 4212971082, win 29200, options [mss 1460,nop,nop,sackOK,nop,wscale 7], length 0
00:51:41.579792 IP (tos 0x0, ttl 128, id 3115, offset 0, flags [DF], proto TCP (6), length 40)
    192.168.112.1.63202 > 192.168.112.135.8080: Flags [.], cksum 0x2c00 (correct), ack 1, win 513, length 0
00:51:41.579852 IP (tos 0x0, ttl 128, id 3116, offset 0, flags [DF], proto TCP (6), length 531)
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
	
00:51:41.579873 IP (tos 0x0, ttl 64, id 29768, offset 0, flags [DF], proto TCP (6), length 40)
    192.168.112.135.8080 > 192.168.112.1.63179: Flags [.], cksum 0x61f4 (incorrect -> 0x801b), ack 492, win 254, length 0
00:51:41.580201 IP (tos 0x0, ttl 64, id 29769, offset 0, flags [DF], proto TCP (6), length 193)
    192.168.112.135.8080 > 192.168.112.1.63179: Flags [P.], cksum 0x628d (incorrect -> 0xdcab), seq 1:154, ack 492, win 254, length 153: HTTP, length: 153
	HTTP/1.1 200 OK
	Date: Mon, 27 Jan 2025 16:51:41 GMT
	Content-Length: 32
	Content-Type: text/html; charset=ISO-8859-1
	
	Hello, High Performance Server!
00:51:41.622391 IP (tos 0x0, ttl 128, id 3119, offset 0, flags [DF], proto TCP (6), length 40)
    192.168.112.1.63179 > 192.168.112.135.8080: Flags [.], cksum 0x7e81 (correct), ack 154, win 511, length 0
00:51:41.652438 IP (tos 0x0, ttl 128, id 3121, offset 0, flags [DF], proto TCP (6), length 454)
    192.168.112.1.63179 > 192.168.112.135.8080: Flags [P.], cksum 0x03fe (correct), seq 492:906, ack 154, win 511, length 414: HTTP, length: 414
	GET /favicon.ico HTTP/1.1
	Host: 192.168.112.135:8080
	Connection: keep-alive
	User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36
	Accept: image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8
	Referer: http://192.168.112.135:8080/
	Accept-Encoding: gzip, deflate
	Accept-Language: en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7,vi;q=0.6
	
00:51:41.652912 IP (tos 0x0, ttl 64, id 29770, offset 0, flags [DF], proto TCP (6), length 193)
    192.168.112.135.8080 > 192.168.112.1.63179: Flags [P.], cksum 0x628d (incorrect -> 0xda6c), seq 154:307, ack 906, win 262, length 153: HTTP, length: 153
	HTTP/1.1 200 OK
	Date: Mon, 27 Jan 2025 16:51:41 GMT
	Content-Length: 32
	Content-Type: text/html; charset=ISO-8859-1
	
	Hello, High Performance Server!
00:51:41.697832 IP (tos 0x0, ttl 128, id 3122, offset 0, flags [DF], proto TCP (6), length 40)
    192.168.112.1.63179 > 192.168.112.135.8080: Flags [.], cksum 0x7c4b (correct), ack 307, win 510, length 0
00:52:26.580636 IP (tos 0x0, ttl 128, id 3254, offset 0, flags [DF], proto TCP (6), length 41)
    192.168.112.1.63202 > 192.168.112.135.8080: Flags [.], cksum 0x2c00 (correct), seq 0:1, ack 1, win 513, length 1: HTTP
00:52:26.580756 IP (tos 0x0, ttl 64, id 28776, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.112.135.8080 > 192.168.112.1.63202: Flags [.], cksum 0x6200 (incorrect -> 0x5436), ack 1, win 229, options [nop,nop,sack 1 {0:1}], length 0
00:52:26.654742 IP (tos 0x0, ttl 128, id 3256, offset 0, flags [DF], proto TCP (6), length 41)
    192.168.112.1.63179 > 192.168.112.135.8080: Flags [.], cksum 0x7c4b (correct), seq 905:906, ack 307, win 510, length 1: HTTP
00:52:26.654793 IP (tos 0x0, ttl 64, id 29771, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.112.135.8080 > 192.168.112.1.63179: Flags [.], cksum 0x6200 (incorrect -> 0xcb40), ack 906, win 262, options [nop,nop,sack 1 {905:906}], length 0
^C
16 packets captured
17 packets received by filter
0 packets dropped by kernel
###########################  -----------------------------------###########################  -----------------------------------###########################  -----------------------------------

以下是一个使用 C/C++ 实现高并发 Web 后台的解决方案，采用 Reactor 模式 + epoll 多路复用技术：

```c
// C 语言版本 (基于 libevent)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>

void request_handler(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf = evbuffer_new();
    evbuffer_add_printf(buf, "Hello, High Performance Server!\n");
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    evbuffer_free(buf);
}

int main() {
    struct event_base *base = event_base_new();
    struct evhttp *http = evhttp_new(base);
    
    evhttp_bind_socket(http, "0.0.0.0", 8080);
    evhttp_set_gencb(http, request_handler, NULL);
    
    printf("Server running on port 8080...\n");
    event_base_dispatch(base);
    
    evhttp_free(http);
    event_base_free(base);
    return 0;
}
```

```cpp
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
```

部署步骤（CentOS）：

1. 环境准备：
```bash
sudo yum install epel-release
sudo yum install gcc gcc-c++ make cmake
sudo yum install libevent-devel boost-devel
```

2. 编译运行：

C 版本：
```bash
gcc c_server.c -o c_server -levent
./c_server
```

C++ 版本：
```bash
g++ cpp_server.cpp -o cpp_server -lboost_system -pthread
./cpp_server
```

3. 性能优化配置：

```bash
# 调整文件描述符限制
echo "* soft nofile 1000000" >> /etc/security/limits.conf
echo "* hard nofile 1000000" >> /etc/security/limits.conf

# 网络参数优化
sysctl -w net.core.somaxconn=65535
sysctl -w net.ipv4.tcp_max_syn_backlog=65535
sysctl -w net.ipv4.tcp_tw_reuse=1
```
###########################  -----------------------------------###########################  -----------------------------------###########################
压力测试：
```bash
ab -n 100000 -c 5000 http://localhost:8080/
wrk -t12 -c4000 -d30s http://localhost:8080/
```

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