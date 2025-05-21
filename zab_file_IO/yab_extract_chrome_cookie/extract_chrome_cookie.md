
gcc main.c -ID:\apps\msys64\ucrt64\local\include -LD:\apps\msys64\ucrt64\local\lib64 -LD:\apps\msys64\ucrt64\lib -lcrypt32 -lcryptui -lws2_32 -luser32 -lole32 -lsqlite3 -lcrypto -lssl -o chrome_cookies_export.exe

msys2 minGW,使用SQLite3来访问Chrome的Cookies数据库,

    从Chrome Local State读取并解密AES密钥, 复制Chrome的Cookies数据库副本，防止锁定,SQLite3从Cookies数据库中筛选youtube.com域名的
cookies,解析encrypted_value的v20格式,使用AES-GCM解密,输出解密后的 cookie 到 cookies.txt

Chrome加密方式——Chrome 80+以后的加密机制,使用AES-GCM加密,并且密钥经过DPAPI加密,保存在Local State文件中,
以下代码查看chrome加密格式:
    sqlite3_open(temp_path, &db);  // 打开复制后的数据库
    // 额外：调试信息
    printf("encrypted_value prefix: %.3s\n", enc_val);  // 输出是v20

Chrome AES-GCM Cookie 解密流程(Windows)
    1. 从 Local State 文件中提取 AES 密钥（base64 编码）
        %LOCALAPPDATA%\Google\Chrome\User Data\Local State 是一个 JSON 文件，其中包含加密的密钥（base64 编码）：
            "os_crypt": {
            "encrypted_key": "base64..."
            }
        这个 base64 解码后前缀是 DPAPI，你要用 CryptUnprotectData 解密它，得到真正的 AES 密钥。

    2. sql读取encrypted_value字段

    3. 用这个AES密钥去解密 encrypted_value
        Chrome 的 cookie 存储结构如下：
        前缀	IV(12字节)	     密文	  GCM Tag(16字节)
        v20	       √	          √	           √

    4. 你要：去除前缀（3字节）："v20",提取 IV：接下来的 12 字节,提取 GCM Tag：最后 16 字节,剩下的是密文,然后用 AES-256-GCM 解密。



-lcrypt32, 调用 Windows DPAPI
-lsqlite3, 自行安装sqlite3 dev库
-lcrypto -lssl, OpenSSL库

需要 Chrome 关闭状态下运行，保证复制数据库文件成功


