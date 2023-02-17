#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>

/* HTTP request representor */
class Request
{
public:
    std::string method;
    std::string path;
    /* Constructor */
    Request(std::string method, std::string path);
    /* @returns Request from an HTTP request text */
    static Request from_text(std::string HTTP_text);
};

#endif