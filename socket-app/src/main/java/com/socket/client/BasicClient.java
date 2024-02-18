package com.socket.client;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class BasicClient {

    private String serverAddress;
    private Integer serverPort;

    public BasicClient(String serverAddress, Integer serverPort) {
        this.serverAddress = serverAddress;
        this.serverPort = serverPort;
    }

    public void start() {
        try (Socket socket = new Socket(serverAddress, serverPort);
             BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))) {

            System.out.print("Enter your username: ");
            String userName = stdIn.readLine();
            bos.write(userName.getBytes());
            bos.flush();

            System.out.println("Connected to server. Type 'quit' to exit.");
            String userInput;

            while (true) {
                System.out.print("Enter message: ");
                userInput = stdIn.readLine();

                if ("quit".equalsIgnoreCase(userInput)) {
                    break;
                }

                byte[] messageBytes = userInput.getBytes();
                int offset = 0;
                while (offset < messageBytes.length) {
                    int chunkSize = Math.min(messageBytes.length - offset, 2048);
                    bos.write(messageBytes, offset, chunkSize);
                    bos.flush();
                    offset += chunkSize;
                }
            }
        } catch (IOException e) {
            System.err.println("Client exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
