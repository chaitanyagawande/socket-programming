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

# sanitizers used: ASAN, UBSAN, or NONE
set(SANITIZER "NONE" CACHE STRING "Choose the type of sanitizer: ASAN, UBSAN, NONE")

if(SANITIZER STREQUAL "ASAN")
    set(SANITIZER_FLAGS "-fsanitize=address" "-fno-omit-frame-pointer" "-g")
    set(SANITIZER_LINKER_FLAGS "-fsanitize=address")
elseif(SANITIZER STREQUAL "UBSAN")
    set(SANITIZER_FLAGS "-fsanitize=undefined" "-fno-omit-frame-pointer" "-g")
    set(SANITIZER_LINKER_FLAGS "-fsanitize=undefined")
endif()

if(NOT SANITIZER STREQUAL "NONE")
    target_compile_options(ServerApp PRIVATE ${SANITIZER_FLAGS})
    target_compile_options(ClientApp PRIVATE ${SANITIZER_FLAGS})
    target_link_options(ServerApp PRIVATE ${SANITIZER_LINKER_FLAGS})
    target_link_options(ClientApp PRIVATE ${SANITIZER_LINKER_FLAGS})
endif()

target_link_libraries(ServerApp Threads::Threads)
target_link_libraries(ClientApp Threads::Threads)

enable_testing()

set(TEST_SOURCES
    test/ClientAppTest.cpp
    test/ServerAppTest.cpp
)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} Threads::Threads)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()