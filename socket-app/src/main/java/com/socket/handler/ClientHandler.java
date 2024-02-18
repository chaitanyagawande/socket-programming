package com.socket.handler;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

import com.socket.utils.SessionManager;

public class ClientHandler implements Runnable {
    
    private final Socket clientSocket;
    private final SessionManager sessionManager;
    private final long sessionId;
    private String clientName;
    private AtomicInteger totalMessagesSent = new AtomicInteger(0);
    private AtomicLong totalBytesReceived = new AtomicLong(0);
    private Long sessionStartTime;

    public ClientHandler(Socket clientSocket, SessionManager sessionManager) {
        this.clientSocket = clientSocket;
        this.sessionManager = sessionManager;
        this.sessionId = UUID.randomUUID().getLeastSignificantBits();
        this.sessionStartTime = System.currentTimeMillis();
    }
    
    @Override
    public void run() {
        try {
            BufferedInputStream in = new BufferedInputStream(clientSocket.getInputStream());
            
            sessionManager.registerSession(sessionId, this);
            System.out.println("Total active sessions: " + sessionManager.getTotalActiveSessions());

            this.clientName = readMessage(in);

            String message;
            while ((message = readMessage(in)) != null) { 

                totalMessagesSent.incrementAndGet();
                totalBytesReceived.addAndGet(message.getBytes().length);

                System.out.println("Received message from username = [" + this.clientName + "], message = [" + message + "]");

                if ("quit".equalsIgnoreCase(message)) {
                    break;
                }
            }

        } catch (IOException e) {
            System.err.println("Exception in client handler: " + e.getMessage());
            e.printStackTrace();
        } finally {
            closeConnection();
        }
    }

    private String readMessage(BufferedInputStream in) throws IOException {
        byte[] buffer = new byte[2048];
        int bytesRead = in.read(buffer);
        if (bytesRead == -1) {
            return null; 
        }
        
        String encodedMessage = new String(buffer, 0, bytesRead);
        return encodedMessage;
    }

    private void closeConnection() {
        System.out.println("Closing client connection for username = " + this.clientName + "\nTotal messages sent: " + totalMessagesSent.get() + ", Total bytes received: " + totalBytesReceived.get() + ", Session duration: " + (System.currentTimeMillis() - sessionStartTime) + "ms");

        sessionManager.unregisterSession(sessionId);
        try {
            clientSocket.close();
        } catch (IOException e) {
            System.err.println("Error closing client socket: " + e.getMessage());
        }
    }
}
