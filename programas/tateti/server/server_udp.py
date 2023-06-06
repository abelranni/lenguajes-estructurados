import socket
import pygame
import threading

# Configuración de Pygame
WINDOW_SIZE = (300, 300)
LINE_WIDTH = 5
FONT_SIZE = 80

# Configuración del servidor
SERVER_ADDRESS = ('192.168.100.80', 12345)

# Tablero del juego
BOARD_SIZE = 3

class GameBoard:
    def __init__(self):
        self.board = [[' ']*BOARD_SIZE for _ in range(BOARD_SIZE)]
        self.window = pygame.display.set_mode(WINDOW_SIZE)
        pygame.display.set_caption("Tateti")
        self.font = pygame.font.Font(None, FONT_SIZE)
        self.piece_x = pygame.image.load('xcross.png')
        self.piece_o = pygame.image.load('circle.png')        
        self.cell_size = WINDOW_SIZE[0] // BOARD_SIZE
        self.piece_size = self.piece_x.get_width()  # Asume que ambas piezas tienen el mismo tamaño

    def draw(self):
        self.window.fill((255, 255, 255))
        self._draw_lines()
        self._draw_pieces()
        pygame.display.flip()

    def _draw_lines(self):
        for i in range(1, BOARD_SIZE):
            pygame.draw.line(self.window, (0, 0, 0), (i*100, 0), (i*100, 300), LINE_WIDTH)
            pygame.draw.line(self.window, (0, 0, 0), (0, i*100), (300, i*100), LINE_WIDTH)

    def _draw_pieces(self):
        for i in range(BOARD_SIZE):
            for j in range(BOARD_SIZE):
                if self.board[i][j] == '2':
                    # text = self.font.render('X', True, (0, 0, 0))
                    # self.window.blit(text, (j*100+30, i*100))
                    # self.window.blit(self.piece_x, (j*100+30, i*100))    
                    self._draw_piece(self.piece_x, i, j)

                elif self.board[i][j] == '1':
                    # text = self.font.render('O', True, (0, 0, 0))
                    # self.window.blit(text, (j*100+30, i*100))
                    # self.window.blit(self.piece_o, (j*100+30, i*100))                    
                    self._draw_piece(self.piece_o, i, j)

    def _draw_piece(self, piece, row, col):
        cell_center_x = self.cell_size * col + self.cell_size // 2
        cell_center_y = self.cell_size * row + self.cell_size // 2
        piece_position = (cell_center_x - self.piece_size // 2, cell_center_y - self.piece_size // 2)
        self.window.blit(piece, piece_position)
        
    def update(self, message):
        self.board = [list(message[i:i+BOARD_SIZE]) for i in range(0, len(message), BOARD_SIZE)]


class GameServer:
    def __init__(self, game_board):
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.server_socket.bind(SERVER_ADDRESS)
        self.game_board = game_board

    def start(self):
        print("Servidor iniciado. Esperando mensajes...")

        while True:
            message, client_address = self.server_socket.recvfrom(1024)
            print(f"Mensaje recibido desde {client_address}: {message.decode('utf-8')}")
            self.game_board.update(message.decode('utf-8'))

if __name__ == "__main__":
    pygame.init()

    game_board = GameBoard()
    game_server = GameServer(game_board)

    server_thread = threading.Thread(target=game_server.start)
    server_thread.start()

    while True:
        game_board.draw()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                game_server.server_socket.close()
                exit(0)
