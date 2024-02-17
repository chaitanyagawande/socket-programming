#include "ClientHandler.hpp"
#include "SessionManager.hpp"
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
    while (running)
    {
        std::string message = readMessage();
        if (message.empty())
        {
            sessionManager.removeHandler(clientSocket);
            break;
        }
        std::cout << "Received message: " << message << std::endl;

        // Echo the received message back to the client as a simple response
        std::string response = "Echo: " + message;
        send(clientSocket, response.c_str(), response.size(), 0);
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
