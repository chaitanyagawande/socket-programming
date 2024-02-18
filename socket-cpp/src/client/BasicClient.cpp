#include "client/BasicClient.hpp"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

BasicClient::BasicClient(const std::string &serverAddress, int serverPort)
    : serverAddress(serverAddress), serverPort(serverPort), sockfd(-1)
{
}

void BasicClient::createSocket()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Could not create socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverAddress.c_str(), &serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void BasicClient::connectToServer()
{
    createSocket();
    std::cout << "Connected to server. Type 'quit' to exit." << std::endl;
}

void BasicClient::sendUsername() {
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    
    send(sockfd, username.c_str(), username.length(), 0);
}

void BasicClient::sendMessage(const std::string &message)
{
    send(sockfd, message.c_str(), message.length(), 0);
    std::string response = readResponse();
    std::cout << "Server-to-Client:: " << response << std::endl;
}

std::string BasicClient::readResponse()
{
    char buffer[1024] = {0};
    ssize_t valread = read(sockfd, buffer, 1024);
    if (valread < 0)
    {
        std::cerr << "Failed to read response from server" << std::endl;
        return "";
    }
    return std::string(buffer, valread);
}

void BasicClient::startCommunicationLoop()
{
    sendUsername();

    std::string message;
    while (true)
    {
        std::cout << "Enter message (type 'quit' to exit): ";
        std::getline(std::cin, message);

        if (message == "quit")
        {
            sendMessage("quit");
            break;
        }

        sendMessage(message);
    }
    close(sockfd);
}
