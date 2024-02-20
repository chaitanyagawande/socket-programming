# Socket Programming Examples

This repository contains example code for socket programming in C++, Java, and Python. These examples demonstrate how to set up basic client-server communication using sockets.

## Introduction

Socket programming is a way to enable communication between two applications over a network. It involves using API calls to send and receive data through a network. This repository provides practical examples of how socket programming can be implemented in different programming languages.

## Installation

### C++

1. **Change to C++ Code Directory**

    ```bash
    cd socket-cpp
    ```

2. **Build Code**

    ```bash
    chmod +x build.sh
    ./build.sh
    ```

3. **Run Test Cases**

```bash
cd build
ctest
```

4. **Run Server**

    ```bash
    chmod +x server.sh
    ./server.sh
    # You can specify port while running this script. e.g., ./server.sh 9001
    ```

5. **Run Client**

    ```bash
    chmod +x client.sh
    ./client.sh
    # You can specify port while running this script. e.g., ./client.sh 9001
    ```

### Java

1. **Change to Java Code Directory**

    ```bash
    cd socket-app
    ```

2. **Run Test Cases**

    ```bash
    mvn package
    ```

3. **Run Server**

    ```bash
    chmod +x server.sh
    ./server.sh
    # You can specify port while running this script. e.g., ./server.sh 9001
    ```

4. **Run Client**

    ```bash
    chmod +x client.sh
    ./client.sh
    # You can specify port while running this script. e.g., ./client.sh 9001
    ```

### Python

1. **Change to Python Code Directory**

    ```bash
    cd socket-app-python
    ```

2. **Run Test Cases**

    ```bash
    pytest tests
    ```

3. **Run Server**

    ```bash
    chmod +x server.sh
    ./server.sh
    # You can specify port while running this script. e.g., ./server.sh 9001
    ```

4. **Run Client**

    ```bash
    chmod +x client.sh
    ./client.sh
    # You can specify port while running this script. e.g., ./client.sh 9001
    ```

## Conclusion

This repository provides a simple yet comprehensive guide to getting started with socket programming across three major programming languages. Whether you are a student, educator, or professional, these examples can serve as a foundational step towards understanding and implementing network communication in your projects.
