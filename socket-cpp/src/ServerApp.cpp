#include "BasicServer.hpp"
#include <csignal>
#include <iostream>

BasicServer *basicServerPtr = nullptr; // Global pointer to access the server instance in the signal handler

void signalHandler(int signal)
{
    std::cout << "Signal received: " << signal << std::endl;
    if (basicServerPtr)
    {
        basicServerPtr->stop();
    }
    exit(signal);
}

int main(int argc, char **argv)
{
    BasicServer basicServer(2345);
    basicServerPtr = &basicServer; // Set the global pointer

    // Register signal handler
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    basicServer.start(); // This will block and run the server loop

    return 0; // We will never reach this point due to the blocking call above
}
