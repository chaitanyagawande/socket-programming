#include "server/BasicServer.hpp"
#include <csignal>
#include <iostream>

BasicServer *basicServerPtr = nullptr; 

void signalHandler(int signal)
{
    std::cout << "Signal received: " << signal << std::endl;
    if (basicServerPtr)
    {
        basicServerPtr->stop();
    }
    exit(signal);
}

int main(int argc, char **argv) {
    int port = 12345;
    if (argc > 1) {
        port = std::stoi(argv[1]);
    }

    BasicServer basicServer(port);

    basicServerPtr = &basicServer; 
    
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    basicServer.start(); 

    return 0; 
}
