package com.socket.app;

import com.socket.client.BasicClient;

public class ClientApp {

    public static void main(String[] args) {
        String serverAddress = "localhost";
        Integer serverPort = 12347;

        BasicClient client = new BasicClient(serverAddress, serverPort);
        client.start();
    }

}
