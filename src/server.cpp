/*
 * Copyright 2023 Momo
 */

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
// #include <winsock.h>

#include "include/server.h"

int TCP_listen(std::uint16_t port) {
    int sock;
    struct sockaddr_in server, peer;

    // Socket descriptor
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cout << "Unable to initilize the socket" << std::endl;
        return (-1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Bind the socket to the address
    if (bind(sock, (const sockaddr *)&server, sizeof(server)) == -1) {
        std::cout << "Couldn't bind the socket to the address" << std::endl;
        return (-1);
    }

    // Setting the socket to be listening
    if (listen(sock, SOMAXCONN) == -1) {
        std::cout << "Couldn't set the socket mode to listening." << std::endl;
        return (-1);
    }

    // Now accept the incoming connectins
    std::cout << "Wating for incoming connections..." << std::endl;

    uint64_t slen = sizeof(peer);
    accept(sock, reinterpret_cast<sockaddr *>(&peer),
           reinterpret_cast<socklen_t *>(&slen));

    std::cout << "Connection accepted!" << std::endl;

    // Windows specific `close`
    close(sock);
    std::cout << "Socket closed" << std::endl;

    return (1);
}
