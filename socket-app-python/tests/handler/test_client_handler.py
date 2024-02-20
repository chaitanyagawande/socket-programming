import pytest
from unittest.mock import MagicMock
import uuid

from handler.client_handler import ClientHandler

class MockSessionManager:
    def register_session(self, session_id, handler):
        pass

    def unregister_session(self, session_id):
        pass

    def get_total_active_sessions(self):
        return 1

@pytest.fixture
def client_socket():
    mock_socket = MagicMock()
    return mock_socket

@pytest.fixture
def session_manager():
    return MagicMock(spec=MockSessionManager)

def test_client_handler_initialization(session_manager, client_socket):
    handler = ClientHandler(client_socket, session_manager)
    assert isinstance(handler.session_id, int)
    assert handler.total_messages_sent == 0
    assert handler.total_bytes_received == 0

if __name__ == "__main__":
    pytest.main(["-v", __file__])
