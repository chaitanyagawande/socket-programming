cmake_minimum_required(VERSION 3.10)
project(SocketProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

find_package(Threads REQUIRED)

set(SERVER_SOURCES
    src/server/BasicServer.cpp
    src/apps/ServerApp.cpp
    src/utils/SessionManager.cpp
    src/handler/ClientHandler.cpp
)

set(CLIENT_SOURCES
    src/client/BasicClient.cpp
    src/apps/ClientApp.cpp
)

add_executable(ServerApp ${SERVER_SOURCES})

add_executable(ClientApp ${CLIENT_SOURCES})

target_link_libraries(ServerApp Threads::Threads)
target_link_libraries(ClientApp Threads::Threads)
