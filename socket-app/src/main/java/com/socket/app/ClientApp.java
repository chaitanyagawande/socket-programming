package com.socket.app;

import com.socket.client.BasicClient;

public class ClientApp {

    public static void main(String[] args) {
        String serverAddress = "localhost";
        int defaultPort = 9100;

        if(args.length > 0){
            defaultPort = Integer.parseInt(args[0]);
        }

        BasicClient client = new BasicClient(serverAddress, defaultPort);
        client.start();
    }

}
