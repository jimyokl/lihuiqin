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
