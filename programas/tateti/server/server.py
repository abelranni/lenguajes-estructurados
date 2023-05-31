import socket
import pygame
import threading

# Configuración de Pygame
pygame.init()
window_size = (300, 300)
window = pygame.display.set_mode(window_size)
pygame.display.set_caption("Tateti")
font = pygame.font.Font(None, 100)

# Configuración del servidor
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(('localhost', 12345))

# Tablero del juego
board = [[' ']*3 for _ in range(3)]

def draw_board():
    window.fill((255, 255, 255))

    # Dibuja las líneas del tablero
    pygame.draw.line(window, (0, 0, 0), (100, 0), (100, 300), 5)
    pygame.draw.line(window, (0, 0, 0), (200, 0), (200, 300), 5)
    pygame.draw.line(window, (0, 0, 0), (0, 100), (300, 100), 5)
    pygame.draw.line(window, (0, 0, 0), (0, 200), (300, 200), 5)

    # Dibuja las fichas del tablero
    for i in range(3):
        for j in range(3):
            if board[i][j] == '2':
                text = font.render('X', True, (0, 0, 0))
                window.blit(text, (j*100+30, i*100))
            elif board[i][j] == '1':
                text = font.render('O', True, (0, 0, 0))
                window.blit(text, (j*100+30, i*100))

    pygame.display.flip()

def server_thread():
    print("Servidor iniciado. Esperando mensajes...")

    while True:
        # Recibe un mensaje y la dirección del cliente
        message, client_address = server_socket.recvfrom(1024)

        # Decodifica el mensaje y lo imprime
        print(f"Mensaje recibido desde {client_address}: {message.decode('utf-8')}")

        # Actualiza el tablero
        global board
        board = [list(message.decode('utf-8')[i:i+3]) for i in range(0, 7, 3)]
        print(board)

if __name__ == "__main__":
    # Inicia el hilo del servidor
    threading.Thread(target=server_thread).start()

    # Bucle de eventos de Pygame
    while True:
        draw_board()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                server_socket.close()
                exit(0)
