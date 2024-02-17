#include "SessionManager.hpp"
#include "ClientHandler.hpp"

// Constructor and Destructor are defaulted in the header and do not need to be defined here

void SessionManager::registerSession(long sessionId, std::shared_ptr<ClientHandler> handler)
{
    std::lock_guard<std::mutex> lock(mutex);
    sessions[sessionId] = handler;
}

void SessionManager::unregisterSession(long sessionId)
{
    std::lock_guard<std::mutex> lock(mutex);
    sessions.erase(sessionId);
}

int SessionManager::getTotalActiveSessions()
{
    std::lock_guard<std::mutex> lock(mutex);
    return sessions.size();
}

std::shared_ptr<ClientHandler> SessionManager::createHandler(int clientSocket)
{
    std::lock_guard<std::mutex> lock(mutex);
    auto handler = std::make_shared<ClientHandler>(clientSocket, *this);
    sessions[clientSocket] = handler;
    return handler;
}

void SessionManager::removeHandler(int clientSocket)
{
    std::lock_guard<std::mutex> lock(mutex);
    sessions.erase(clientSocket);
}

void SessionManager::removeAllHandlers()
{
    std::lock_guard<std::mutex> lock(mutex);
    sessions.clear();
}
