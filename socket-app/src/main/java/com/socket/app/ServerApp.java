package com.socket.app;

import com.socket.server.BasicServer;

public class ServerApp {
    
    public static void main(String[] args) {

        int defaultPort = 9100;

        if(args.length > 0){
            defaultPort = Integer.parseInt(args[0]);
        }
        
        BasicServer server = new BasicServer(defaultPort);
        server.start();
    }
    
}
