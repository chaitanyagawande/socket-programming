import pytest
from unittest.mock import MagicMock, patch
from handler.client_handler import ClientHandler
from utils.session_manager import SessionManager

@pytest.fixture
def mock_socket():
    return MagicMock()

@pytest.fixture
def mock_session_manager():
    manager = SessionManager()
    manager.register_session = MagicMock()
    manager.unregister_session = MagicMock()
    return manager

@pytest.fixture
def client_handler(mock_socket, mock_session_manager):
    return ClientHandler(mock_socket, mock_session_manager)

def test_initialization(client_handler, mock_session_manager):
    assert client_handler.session_manager == mock_session_manager
    assert client_handler.total_messages_sent == 0
    assert client_handler.total_bytes_received == 0

def test_close_connection(client_handler, mock_socket, mock_session_manager):
    client_handler.close_connection()
    mock_socket.close.assert_called_once()
    mock_session_manager.unregister_session.assert_called_with(client_handler.session_id)

if __name__ == "__main__":
    pytest.main(["-v", __file__])