#!/usr/bin/expect

set timeout 1
set username [lindex $argv 0]
spawn java -cp target/classes com.socket.app.ClientApp
expect "Enter your username:"
send "$username\r"

expect "Connected to server. Type 'quit' to exit."

for {set i 1} {$i <= 100} {incr i} {
    expect "Enter message:"
    send "random$i\r"
    sleep 2
}

send "quit\r"

expect eof
