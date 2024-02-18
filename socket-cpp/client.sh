#!/bin/bash

if [ -n "$1" ]; then
    ./build/ClientApp "$1"
else
    ./build/ClientApp
fi