import pytest

from utils.session_manager import SessionManager

class MockHandler:
    pass

def test_session_manager_initialization():
    session_manager = SessionManager()
    assert isinstance(session_manager.sessions, dict)
    assert len(session_manager.sessions) == 0, "SessionManager should start with no sessions"

def test_register_and_unregister_session():
    session_manager = SessionManager()
    mock_session_id = 123456
    mock_handler = MockHandler()

    session_manager.register_session(mock_session_id, mock_handler)
    assert mock_session_id in session_manager.sessions
    assert session_manager.sessions[mock_session_id] == mock_handler
    assert len(session_manager.sessions) == 1, "Session should be registered"

    session_manager.unregister_session(mock_session_id)
    assert mock_session_id not in session_manager.sessions
    assert len(session_manager.sessions) == 0, "Session should be unregistered"

def test_get_total_active_sessions():
    session_manager = SessionManager()
    session_manager.register_session(1, MockHandler())
    session_manager.register_session(2, MockHandler())
    assert session_manager.get_total_active_sessions() == 2, "Should return the total number of active sessions"

    session_manager.unregister_session(1)
    assert session_manager.get_total_active_sessions() == 1, "Should update the total number of active sessions after unregistering"

if __name__ == "__main__":
    pytest.main(["-v", __file__])
