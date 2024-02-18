#ifndef BASICCLIENT_HPP
#define BASICCLIENT_HPP

#include <string>

class BasicClient {
public:
    BasicClient(const std::string& serverAddress, int serverPort);
    void connectToServer();
    void sendUsername();
    void sendMessage(const std::string& message);
    void startCommunicationLoop();

private:
    std::string serverAddress;
    int serverPort;
    int sockfd;
    void createSocket();
    std::string readResponse();
};

#endif
