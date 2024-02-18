#!/bin/bash

if [ -n "$1" ]; then
    ./build/ServerApp "$1"
else
    ./build/ServerApp
fi