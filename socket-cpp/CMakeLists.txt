cmake_minimum_required(VERSION 3.10)
project(SocketProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/BasicClient.cpp
    src/BasicServer.cpp
    src/ClientHandler.cpp
    src/SessionManager.cpp
    src/ServerApp.cpp
    src/ClientApp.cpp
)

include_directories(include)

add_executable(SocketProject ${SOURCES})
