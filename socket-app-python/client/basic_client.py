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

                    message_bytes = user_input.encode('utf-8')
                    sock.sendall(message_bytes)

        except Exception as e:
            print(f"Client exception: {e}")

if __name__ == "__main__":
    port = 12347

    if len(sys.argv) > 1:
        port = int(sys.argv[1])

    client = BasicClient(server_address='localhost', server_port=port)
    client.start()