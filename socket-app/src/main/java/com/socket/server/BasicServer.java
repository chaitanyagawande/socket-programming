package com.socket.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import com.socket.handler.ClientHandler;
import com.socket.utils.SessionManager;

public class BasicServer {

    private final int port;
    private final ExecutorService connectionPool;
    private final SessionManager sessionManager;

    public BasicServer(int port) {
        this.port = port;
        this.sessionManager = new SessionManager();
        this.connectionPool = Executors.newCachedThreadPool();
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(this.port)) {
            System.out.println("Server started on port " + this.port);

            while (!serverSocket.isClosed()) {
                Socket clientSocket = serverSocket.accept();

                System.out.println("New client connected on Address : " + clientSocket.getInetAddress() + " Port : " + clientSocket.getPort());

                ClientHandler clientHandler = new ClientHandler(clientSocket, sessionManager);
                connectionPool.execute(clientHandler);
            }

        } catch (IOException e) {
            System.err.println("Server exception: " + e.getMessage());
            e.printStackTrace();
        } finally {
            shutdown();
        }
    }

    private void shutdown() {
        connectionPool.shutdown();
        System.out.println("Server shutdown");
    }

}
