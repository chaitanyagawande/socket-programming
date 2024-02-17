#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

#include <map>
#include <mutex>
#include <memory>
#include "ClientHandler.hpp" // Ensure this includes or forward declares ClientHandler

class SessionManager
{
public:
    SessionManager() = default;  // Keep default constructor
    ~SessionManager() = default; // Keep default destructor

    void registerSession(long sessionId, std::shared_ptr<ClientHandler> handler);
    void unregisterSession(long sessionId);
    int getTotalActiveSessions();
    std::shared_ptr<ClientHandler> createHandler(int clientSocket);
    void removeHandler(int clientSocket);
    void removeAllHandlers();

private:
    std::map<int, std::shared_ptr<ClientHandler>> sessions;
    std::mutex mutex;
};

#endif // SESSIONMANAGER_HPP
