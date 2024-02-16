import pytest
from unittest.mock import patch
from concurrent.futures import ThreadPoolExecutor

from server.basic_server import BasicServer
from utils.session_manager import SessionManager

def test_server_initialization():
    port = 12347
    server = BasicServer(port=port)
    assert server.port == port, "Server initialized with incorrect port"
    assert isinstance(server.session_manager, SessionManager), "SessionManager not initialized correctly"
    assert isinstance(server.connection_pool, ThreadPoolExecutor), "Connection pool not initialized correctly"

@patch('concurrent.futures.ThreadPoolExecutor.shutdown', autospec=True)
def test_server_shutdown(mock_shutdown):
    server = BasicServer(port=12347)
    server.shutdown()
    
    mock_shutdown.assert_called_once()

if __name__ == "__main__":
    pytest.main(["-v", __file__])
