#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <cassert>

int main() {
    std::cout << "ServerAppTest starting." << std::endl;

    const char* command = "start \"\" \"..\\src\\apps\\ServerApp.cpp\"";

    if (system(command) == -1) {
        std::cerr << "Failed to start ServerApp." << std::endl;
        return EXIT_FAILURE;
    }


    std::cout << "Assuming the server would start in a real test..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));


    std::cout << "Assuming we send SIGINT to the server in a real test..." << std::endl;
 


    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "ServerAppTest completed." << std::endl;

    return EXIT_SUCCESS;
}
