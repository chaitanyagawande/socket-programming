#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

#include <map>
#include <mutex>
#include <memory>
#include "include/ClientHandler.hpp"

class SessionManager {
public:
    SessionManager() = default;
    ~SessionManager() = default;

    void registerSession(long sessionId, std::shared_ptr<ClientHandler> handler);
    void unregisterSession(long sessionId);
    int getTotalActiveSessions();

private:
    std::map<long, std::shared_ptr<ClientHandler>> sessions;
    std::mutex mutex;
};

#endif
