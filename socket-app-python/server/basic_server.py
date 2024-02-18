import socket
import sys
from concurrent.futures import ThreadPoolExecutor
from utils.session_manager import SessionManager
from handler.client_handler import ClientHandler

class BasicServer:

    def __init__(self, port):
        self.port = port
        self.session_manager = SessionManager()  
        self.connection_pool = ThreadPoolExecutor()

    def start(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
            server_socket.bind(('', self.port))
            server_socket.listen()
            print(f"Server started on port {self.port}")

            try:
                while True:
                    client_socket, _ = server_socket.accept()
                    print(f"New client connected: {client_socket.getpeername()}")

                    client_handler = ClientHandler(client_socket, self.session_manager)  
                    self.connection_pool.submit(client_handler.run)
            except KeyboardInterrupt:
                print("Server stopping")
            finally:
                self.shutdown()

    def shutdown(self):
        self.connection_pool.shutdown()
        print("Server shutdown complete")

if __name__ == "__main__":
    port = 12347

    if len(sys.argv) > 1:
        port = int(sys.argv[1])

    server = BasicServer(port=port)
    server.start()
