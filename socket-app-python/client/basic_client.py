import socket
import base64
import sys

class BasicClient:
    
    def __init__(self, server_address, server_port):
        self.server_address = server_address
        self.server_port = server_port

    def start(self):
        try:
            with socket.create_connection((self.server_address, self.server_port)) as sock:
                sock_stream = sock.makefile(mode='rwb')

                print("Enter your username: ", end='')
                sys.stdout.flush()
                user_name = input()
                sock_stream.write(user_name.encode('utf-8'))
                sock_stream.flush()

                print("Connected to server. Type 'quit' to exit.")
                while True:
                    print("Enter message: ", end='')
                    sys.stdout.flush()
                    user_input = input()

                    if user_input.lower() == 'quit':
                        break

                    encoded_message = base64.b64encode(user_input.encode('utf-8')).decode('utf-8')
                    message_bytes = encoded_message.encode('utf-8')
                    sock.sendall(message_bytes)

        except Exception as e:
            print(f"Client exception: {e}")

if __name__ == "__main__":
    client = BasicClient(server_address='localhost', server_port=12347)
    client.start()