#include "include/request.h"

#include <iostream>

Request::Request(std::string _method, std::string _path) {
    method = _method;
    path = _path;
}

Request Request::from_text(std::string HTTP_text) {
    std::string method;
    std::string path;
    int space;

    space = 0;

    // C++11
    for (const char &ch : HTTP_text) {
        if (ch == ' ') {
            space++;
            continue;
        }
        if (space == 0) {
            method += ch;
        } else if (space == 1) {
            path += ch;
        } else {
            break;
        }
    }
    return (Request(method, path));
};