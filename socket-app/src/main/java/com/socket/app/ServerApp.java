package com.socket.app;

import com.socket.server.BasicServer;

public class ServerApp {
    
    public static void main(String[] args) {
        int port = 9100;
        BasicServer server = new BasicServer(port);
        server.start();
    }
    
}
