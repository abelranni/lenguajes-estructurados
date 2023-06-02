import socket

def start_server():
    # Crea un socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Asocia el socket a un puerto específico
    server_socket.bind(('localhost', 12345))

    # Escucha las conexiones entrantes
    server_socket.listen()

    print("Servidor iniciado. Esperando conexiones...")

    while True:
        # Acepta una conexión entrante
        client_socket, client_address = server_socket.accept()

        print(f"Conexión establecida desde {client_address}.")

        # Recibe el mensaje del cliente
        message = client_socket.recv(1024)

        # Decodifica el mensaje y lo imprime
        print(f"Mensaje recibido: {message.decode('utf-8')}")

        # Cierra la conexión con el cliente
        client_socket.close()

if __name__ == "__main__":
    start_server()
