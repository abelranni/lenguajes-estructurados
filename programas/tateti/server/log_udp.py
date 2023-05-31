import socket

def start_server():
    # Crea un socket UDP
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Asocia el socket a un puerto específico
    server_socket.bind(('localhost', 12345))

    print("Servidor UDP iniciado. Esperando mensajes...")

    while True:
        # Recibe un mensaje y la dirección del cliente
        message, client_address = server_socket.recvfrom(1024)

        # Decodifica el mensaje y lo imprime
        print(f"Mensaje recibido desde {client_address}: {message.decode('utf-8')}")

if __name__ == "__main__":
    start_server()
