#include <iostream>

#include "src/include/server.h"

int main(void) {
    std::string http_text = "GET /test HTTP1.1\r\nContent-Length: 435983";
    // Request req = Request::from_text(http_text);
    // cout << req.method << " - " << req.path << endl;
    std::cout << "Lets connect!";
    TCP_listen(2345);
    return (0);
}