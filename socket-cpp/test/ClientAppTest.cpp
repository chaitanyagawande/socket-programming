#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <cassert>

int main() {
    std::cout << "ClientAppTest starting." << std::endl;


    int testPort = 12345; 


    std::string command = "start \"\" \"..\\src\\apps\\ClientApp.cpp\" " + std::to_string(testPort);

    if (system(command.c_str()) == -1) {
        std::cerr << "Failed to start ClientApp." << std::endl;
        return EXIT_FAILURE;
    }

    
    std::cout << "ClientApp launched, attempting to connect to server on port " << testPort << "." << std::endl;

    
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "ClientAppTest completed. Check server logs or other mechanisms to verify connection and communication." << std::endl;

    return EXIT_SUCCESS;
}
