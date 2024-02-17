cmake_minimum_required(VERSION 3.10)
project(SocketProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Find threads package, which is typically pthreads on UNIX-like systems
find_package(Threads REQUIRED)

# Define the source files for the SERVER executable
set(SERVER_SOURCES
    src/BasicServer.cpp
    src/ServerApp.cpp
    src/SessionManager.cpp
    src/ClientHandler.cpp
    # Add other server-related source files here
)

# Define the source files for the CLIENT executable
set(CLIENT_SOURCES
    src/BasicClient.cpp
    src/ClientApp.cpp
    # Add other client-related source files here
)

# Create an executable for the server
add_executable(ServerApp ${SERVER_SOURCES})

# Create an executable for the client
add_executable(ClientApp ${CLIENT_SOURCES})

# Link pthread library to both executables
target_link_libraries(ServerApp Threads::Threads)
target_link_libraries(ClientApp Threads::Threads)
