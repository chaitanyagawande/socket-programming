#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <string>

#include "include/BasicClient.hpp"

int main(int argc, char **argv) {
    BasicClient basicClient("localhost", 2345);
    basicClient.connectToServer();

    std::stringstream msg;
    msg << "hello. My name is inigo montoya." << std::ends;
    basicClient.sendMessage(msg.str());

    std::cout << "sleeping a bit before exiting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}