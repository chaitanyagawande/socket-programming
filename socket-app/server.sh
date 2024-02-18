#!/bin/bash

if [ -n "$1" ]; then
    java -cp target/classes com.socket.app.ServerApp "$1"
else
    java -cp target/classes com.socket.app.ServerApp
fi
