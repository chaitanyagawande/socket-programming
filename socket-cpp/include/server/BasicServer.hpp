#ifndef BASICSERVER_HPP
#define BASICSERVER_HPP

#include <thread>
#include <vector>
#include <atomic>
#include "utils/SessionManager.hpp"

class BasicServer
{
public:
    BasicServer(int port);
    ~BasicServer();
    void start();
    void stop();

private:
    int port;
    int serverSocket;
    std::atomic<bool> running;
    SessionManager sessionManager;

    void acceptConnections();
};

#endif
