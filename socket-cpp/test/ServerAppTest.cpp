#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
#include <cassert>


int main() {
    std::cout << "ServerAppTest starting." << std::endl;


    std::cout << "Assuming the server would start in a real test..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Assuming we send SIGINT to the server in a real test..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));


    std::cout << "ServerAppTest completed." << std::endl;

    return 0;
}
