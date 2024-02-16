import pytest
from unittest.mock import patch

from client.basic_client import BasicClient

def test_client_initialization():
    server_address = 'localhost'
    server_port = 12347
    client = BasicClient(server_address=server_address, server_port=server_port)
    
    assert client.server_address == server_address, "Client initialized with incorrect server address"
    assert client.server_port == server_port, "Client initialized with incorrect server port"

if __name__ == "__main__":
    pytest.main(["-v", __file__])
