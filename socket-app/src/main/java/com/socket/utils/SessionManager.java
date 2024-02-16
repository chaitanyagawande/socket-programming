package com.socket.utils;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import com.socket.handler.ClientHandler;

public class SessionManager {

    private final Map<Long, ClientHandler> sessions;

    public SessionManager() {
        this.sessions = Collections.synchronizedMap(new HashMap<Long,ClientHandler>());
    }

    public void registerSession(Long sessionId, ClientHandler handler) {
        sessions.put(sessionId, handler);
    }

    public void unregisterSession(Long sessionId) {
        sessions.remove(sessionId);
    }

    public Integer getTotalActiveSessions() {
        return sessions.size();
    }

}
