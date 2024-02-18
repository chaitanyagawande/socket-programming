#!/bin/bash

if [ -n "$1" ]; then
    java -cp target/classes com.socket.app.ClientApp "$1"
else
    java -cp target/classes com.socket.app.ClientApp
fi
