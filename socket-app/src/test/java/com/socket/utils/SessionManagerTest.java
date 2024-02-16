package com.socket.utils;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import com.socket.handler.ClientHandler;
import org.mockito.Mock;

public class SessionManagerTest {

    private SessionManager sessionManager;
    
    @Mock
    private ClientHandler clientHandler;

    @BeforeEach
    public void setUp() {
        sessionManager = new SessionManager();
    }
    
    @Test
    public void testRegisterSession() {
        Long sessionId = 1L;
        sessionManager.registerSession(sessionId, clientHandler);
        assertEquals(1, sessionManager.getTotalActiveSessions());
    }

    @Test
    public void testUnregisterSession() {
        Long sessionId = 1L;
        sessionManager.registerSession(sessionId, clientHandler);
        sessionManager.unregisterSession(sessionId);
        assertEquals(0, sessionManager.getTotalActiveSessions());
    }

    @Test
    public void testGetTotalActiveSessions() {
        Long firstSessionId = 1L;
        Long secondSessionId = 2L;
        ClientHandler anotherClientHandler = new ClientHandler(null, sessionManager);

        sessionManager.registerSession(firstSessionId, clientHandler);
        sessionManager.registerSession(secondSessionId, anotherClientHandler);

        assertEquals(2, sessionManager.getTotalActiveSessions());
    }
}
