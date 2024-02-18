import uuid
import time
from threading import Thread

class ClientHandler(Thread):

    def __init__(self, client_socket, session_manager):
        Thread.__init__(self)
        self.client_socket = client_socket
        self.session_manager = session_manager
        self.session_id = uuid.uuid4().int & (1<<64)-1  
        self.client_name = None
        self.total_messages_sent = 0
        self.total_bytes_received = 0
        self.session_start_time = time.time() * 1000  

    def run(self):
        try:
            with self.client_socket as in_stream:
                self.session_manager.register_session(self.session_id, self)

                print(f"Total active sessions: {self.session_manager.get_total_active_sessions()}")

                self.client_name = self.read_message(in_stream)

                while True:
                    message = self.read_message(in_stream)

                    if message is None:
                        break

                    self.total_messages_sent += 1
                    self.total_bytes_received += len(message.encode('utf-8'))

                    print(f"Received message from username = [{self.client_name}], message = [{message}]")

                    if message.lower() == "quit":
                        break

        except Exception as e:
            print(f"Exception in client handler: {e}")
        finally:
            self.close_connection()

    def read_message(self, in_stream):
        buffer = in_stream.recv(2048)
        if len(buffer) == 0:
            return None

        return buffer.decode('utf-8')

    def close_connection(self):
        print(f"Closing client connection for username = {self.client_name}\nTotal messages sent: {self.total_messages_sent}, Total bytes received: {self.total_bytes_received}, Session duration: {time.time() * 1000 - self.session_start_time}ms")

        self.session_manager.unregister_session(self.session_id)
        try:
            self.client_socket.close()
        except Exception as e:
            print(f"Error closing client socket: {e}")
