#include "handler/ClientHandler.hpp"
#include "utils/SessionManager.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

ClientHandler::ClientHandler(int clientSocket, SessionManager &sessionManager)
    : clientSocket(clientSocket), sessionManager(sessionManager), running(false)
{
}

ClientHandler::~ClientHandler()
{
    stop();
}

void ClientHandler::start()
{

    running = true;
    thread = std::thread(&ClientHandler::run, this);
}

void ClientHandler::stop()
{
    running = false;
    if (thread.joinable())
    {
        thread.join();
    }
}

void ClientHandler::run()
{
    std::cout << "Total active sessions: " << sessionManager.getTotalActiveSessions() << std::endl;

    std::string username = readMessage();

    while (running) {
        std::string message = readMessage();
        if (message.empty() || message == "quit")
        {
            sessionManager.removeHandler(clientSocket);
            break;
        }

        std::cout << "Received message from username = [" << username << "], message = [" << message << "]" << std::endl;

        send(clientSocket, message.c_str(), message.size(), 0);
    }
    closeSocket();
}

std::string ClientHandler::readMessage()
{
    char buffer[1024] = {0};
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0)
    {
        return "";
    }
    return std::string(buffer, bytesRead);
}

void ClientHandler::closeSocket()
{
    if (clientSocket != -1)
    {
        close(clientSocket);
        clientSocket = -1;
    }
}
