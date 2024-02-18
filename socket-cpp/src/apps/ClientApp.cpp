#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <string>

#include "client/BasicClient.hpp"

int main(int argc, char **argv) {
    int port = 12345;
    if (argc > 1) {
        port = std::stoi(argv[1]);
    }

    BasicClient basicClient("127.0.0.1", port);
    basicClient.connectToServer();

    basicClient.startCommunicationLoop();

}