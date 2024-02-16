#include "include/SessionManager.hpp"
#include "include/ClientHandler.hpp"

void SessionManager::registerSession(long sessionId, std::shared_ptr<ClientHandler> handler) {
    std::lock_guard<std::mutex> lock(mutex);
    sessions[sessionId] = handler;
}

void SessionManager::unregisterSession(long sessionId) {
    std::lock_guard<std::mutex> lock(mutex);
    if (sessions.find(sessionId) != sessions.end()) {
        sessions.erase(sessionId);
    }
}

int SessionManager::getTotalActiveSessions() {
    std::lock_guard<std::mutex> lock(mutex);
    return sessions.size();
}