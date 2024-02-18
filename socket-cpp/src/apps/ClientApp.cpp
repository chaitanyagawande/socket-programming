#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <string>

#include "client/BasicClient.hpp"

int main(int argc, char **argv)
{
    BasicClient basicClient("127.0.0.1", 2345);
    basicClient.connectToServer();

    basicClient.startCommunicationLoop();

}