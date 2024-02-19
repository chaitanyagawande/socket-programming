#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <cassert>

int main() {
    std::cout << "ClientAppTest starting." << std::endl;

    // Define the port number to use for testing
    int testPort = 12345; // Ensure this matches the server's listening port or is adjusted for your test environment

    // Construct the command to start ClientApp with the test port
    std::string command = "start \"\" \"..\\src\\apps\\ClientApp.cpp\" " + std::to_string(testPort);

    // Execute the command to start ClientApp
    if (system(command.c_str()) == -1) {
        std::cerr << "Failed to start ClientApp." << std::endl;
        return EXIT_FAILURE;
    }

    // Here you could simulate waiting for ClientApp to perform its operations
    // For a real test, you'd likely want to interact with a server or observe the effects of the connection attempt
    std::cout << "ClientApp launched, attempting to connect to server on port " << testPort << "." << std::endl;

    // Wait a bit for any initial communication to occur (adjust time as necessary for your application)
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "ClientAppTest completed. Check server logs or other mechanisms to verify connection and communication." << std::endl;

    return EXIT_SUCCESS;
}
