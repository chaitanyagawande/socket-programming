#include "BasicServer.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <memory>

BasicServer::BasicServer(int port)
    : port(port), serverSocket(-1), running(false) {
}

BasicServer::~BasicServer() {
    stop();
}

void BasicServer::start() {
    struct sockaddr_in serverAddr;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Could not create socket" << std::endl;
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return;
    }

    listen(serverSocket, 5);
    std::cout << "Server started on port " << port << std::endl;

    running = true;
    acceptConnections();
}

void BasicServer::stop() {
    running = false;
    if (serverSocket != -1) {
        close(serverSocket);
        serverSocket = -1;
    }

    for (auto& thread : clientThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    clientThreads.clear();
}

void BasicServer::acceptConnections() {
    while (running) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            if (running) { 
                std::cerr << "Accept failed" << std::endl;
            }
            continue;
        }

        clientThreads.emplace_back(&BasicServer::handleClient, this, clientSocket);
    }
}

void BasicServer::handleClient(int clientSocket) {
    std::cout << "Handling client" << std::endl;
    close(clientSocket);
}
