#ifndef CLIENTHANDLER_HPP
#define CLIENTHANDLER_HPP

#include <thread>
#include <atomic>
#include "include/SessionManager.hpp"

class ClientHandler {
public:
    ClientHandler(int clientSocket, SessionManager& sessionManager);
    ~ClientHandler();

    void start();
    void stop();

private:
    int clientSocket;
    std::atomic<bool> running;
    std::thread thread;
    SessionManager& sessionManager;

    void run();
    std::string readMessage();
    void closeSocket();
};

#endif 
