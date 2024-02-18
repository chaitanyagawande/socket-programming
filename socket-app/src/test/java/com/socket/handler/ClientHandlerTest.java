package com.socket.handler;

import static org.mockito.Mockito.*;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Base64;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import com.socket.utils.SessionManager;

public class ClientHandlerTest {

    @Mock
    private Socket mockSocket;
    @Mock
    private SessionManager mockSessionManager;

    private ClientHandler clientHandler;

    @BeforeEach
    void setUp() throws IOException {
        MockitoAnnotations.openMocks(this);

        String simulatedInput = Base64.getEncoder().encodeToString("testUser\nquit".getBytes());
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(simulatedInput.getBytes());
        BufferedInputStream bufferedInputStream = new BufferedInputStream(byteArrayInputStream);

        when(mockSocket.getInputStream()).thenReturn(bufferedInputStream);

        clientHandler = new ClientHandler(mockSocket, mockSessionManager);
    }

    @Test
    void testClientHandlerReceivesMessagesAndClosesConnection() throws IOException {
        Thread clientHandlerThread = new Thread(clientHandler);
        clientHandlerThread.start();

        
        try {
            clientHandlerThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new RuntimeException("Test interrupted", e);
        }


        verify(mockSessionManager, times(1)).registerSession(anyLong(), eq(clientHandler));
        verify(mockSessionManager, times(1)).unregisterSession(anyLong());

        verify(mockSocket, times(1)).close();
    }
}
