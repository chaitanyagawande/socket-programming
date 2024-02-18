#!/bin/bash

if [ -n "$1" ]; then
    python3 client/basic_client.py "$1"
else
    python3 client/basic_client.py
fi

 