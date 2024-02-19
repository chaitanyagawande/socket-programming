#!/usr/bin/expect

set timeout 1
spawn ./build/ServerApp
expect "Enter your username:"
send "chaitanya\r"

expect "Connected to server. Type 'quit' to exit."

set start_time [clock seconds]

while {1} {
    set current_time [clock seconds]
    set elapsed_time [expr {$current_time - $start_time}]

    # Adjusted the condition check for Tcl syntax
    if {$elapsed_time >= 60} {
        send "quit\r" ;# Assuming you want to gracefully exit the app
        puts "Time limit reached. Exiting."
        break
    } else {
        # The script will attempt to read the "Enter message:" prompt
        # If it does not appear within a certain timeout, the loop will continue
        # This prevents the script from hanging indefinitely if the prompt doesn't appear
        expect {
            "Enter message:" {
                set curr_timestamp [exec date "+%s%3N"]
                send "$curr_timestamp\r"
            } timeout {
                # If the prompt doesn't appear within the specified timeout, just continue
                # This can be left empty or used to log timeout occurrences
            }
        }
    }

    after 1000 ;# Sleep for 1000 milliseconds (1 second)
}

# Assuming your application needs a "quit" command to close cleanly
send "quit\r"
expect eof
