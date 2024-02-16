#!/usr/bin/expect

# Set the timeout for each send/expect interaction
set timeout 1

# Get the username from the command line arguments
set username [lindex $argv 0]

# Launch the Java client application
spawn java -cp target/classes com.socket.app.ClientApp

# Expect the username prompt and send the username
expect "Enter your username:"
send "$username\r"

# Wait for the connection confirmation
expect "Connected to server. Type 'quit' to exit."

# Send 100 messages
for {set i 1} {$i <= 100} {incr i} {
    expect "Enter message:"
    send "random$i\r"
    sleep 2
}

# Quit the application
send "quit\r"

# End the script
expect eof
