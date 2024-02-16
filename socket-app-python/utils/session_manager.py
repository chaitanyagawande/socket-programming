class SessionManager:
    
    def __init__(self):
        self.sessions = {}

    def register_session(self, session_id, handler):
        self.sessions[session_id] = handler

    def unregister_session(self, session_id):
        if session_id in self.sessions:
            del self.sessions[session_id]

    def get_total_active_sessions(self):
        return len(self.sessions)
