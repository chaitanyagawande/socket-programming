#!/bin/bash

if [ -n "$1" ]; then
    python3 server/basic_server.py "$1"
else
    python3 server/basic_server.py
fi
 