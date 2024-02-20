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

# Define server and client applications
add_executable(ServerApp ${SERVER_SOURCES})
add_executable(ClientApp ${CLIENT_SOURCES})

# Link Threads library
target_link_libraries(ServerApp Threads::Threads)
target_link_libraries(ClientApp Threads::Threads)

# Enable testing
enable_testing()

# Assuming you have test files named ClientTest.cpp and ServerTest.cpp in the test directory
set(TEST_SOURCES
    test/ClientAppTest.cpp
    test/ServerAppTest.cpp
)

# For simplicity, adding executable targets for each test suite
# Adjust according to your actual test files
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE) # Extracts the file name without the directory and extension
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} Threads::Threads)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
