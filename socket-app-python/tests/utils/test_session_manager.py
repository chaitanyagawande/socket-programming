import pytest

from utils.session_manager import SessionManager

def test_initialization():
    manager = SessionManager()
    assert isinstance(manager.sessions, dict), "Sessions attribute must be a dictionary"
    assert len(manager.sessions) == 0, "Sessions dictionary should be empty upon initialization"

def test_register_session():
    manager = SessionManager()
    manager.register_session("session1", "handler1")
    assert "session1" in manager.sessions, "Session should be registered"
    assert manager.sessions["session1"] == "handler1", "Handler should match the registered session"

def test_unregister_session():
    manager = SessionManager()
    manager.register_session("session1", "handler1")
    manager.unregister_session("session1")
    assert "session1" not in manager.sessions, "Session should be unregistered"
    
    manager.unregister_session("non_existent_session")

def test_get_total_active_sessions():
    manager = SessionManager()
    manager.register_session("session1", "handler1")
    manager.register_session("session2", "handler2")
    assert manager.get_total_active_sessions() == 2, "Total active sessions should be 2"
    
    manager.unregister_session("session1")
    assert manager.get_total_active_sessions() == 1, "Total active sessions should be 1 after unregistering a session"

if __name__ == "__main__":
    pytest.main(["-v", __file__])