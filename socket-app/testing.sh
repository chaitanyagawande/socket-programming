#!/bin/bash

for i in {1..1000}; do
  username=$(openssl rand -base64 6 | tr -d '/+=' | cut -c 1-8)
  ./send_msg.sh "$username" &
done
