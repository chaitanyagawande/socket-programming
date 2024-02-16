#include "include/ClientHandler.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

ClientHandler::ClientHandler(int clientSocket, SessionManager& sessionManager)
    : clientSocket(clientSocket), sessionManager(sessionManager), running(false) {
}

ClientHandler::~ClientHandler() {
    stop();
}

void ClientHandler::start() {
    running = true;
    thread = std::thread(&ClientHandler::run, this);
}

void ClientHandler::stop() {
    running = false;
    closeSocket();
    if (thread.joinable()) {
        thread.join();
    }
}

void ClientHandler::run() {

    while (running) {
        std::string message = readMessage();
        if (message.empty()) {
            break; 
        }

        std::cout << "Received message: " << message << std::endl;

    }

    closeSocket();
}

std::string ClientHandler::readMessage() {
    char buffer[1024] = {0};
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        return "";
    }
    return std::string(buffer, bytesRead);
}

void ClientHandler::closeSocket() {
    if (clientSocket != -1) {
        close(clientSocket);
        clientSocket = -1;
    }
}
