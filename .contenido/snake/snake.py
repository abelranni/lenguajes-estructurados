import pygame
import sys
import random

# Configuración inicial
pygame.init()
clock = pygame.time.Clock()

# Inicializa el mezclador de Pygame
pygame.mixer.init()

# Carga el archivo de sonido en formato FLAC
eat_sound = pygame.mixer.Sound("audio_shot.flac")

# Tamaño de la ventana y de los bloques
cell_size = 20
cell_number = 20
screen = pygame.display.set_mode((cell_number * cell_size, cell_number * cell_size))

# Colores
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)

# Variables de la serpiente
snake = [pygame.Rect(5, 5, cell_size, cell_size)]
direction = pygame.Vector2(1, 0)

# Variables de la fruta
fruit = pygame.Rect(random.randint(0, cell_number - 1) * cell_size,
                    random.randint(0, cell_number - 1) * cell_size, cell_size, cell_size)

def draw_rect(screen, color, rect):
    pygame.draw.rect(screen, color, rect)

def move_snake(snake, direction, fruit):
    new_head = snake[0].copy()
    new_head.move_ip(direction * cell_size)
    if new_head.colliderect(fruit):
        randomize_fruit(fruit)
        # Reproduce el sonido de comer
        eat_sound.play()        
    else:
        snake.pop()
    snake.insert(0, new_head)

def randomize_fruit(fruit):
    fruit.x = random.randint(0, cell_number - 1) * cell_size
    fruit.y = random.randint(0, cell_number - 1) * cell_size

def check_collisions(snake):
    head = snake[0]
    if head.x < 0 or head.y < 0 or head.x >= cell_number * cell_size or head.y >= cell_number * cell_size:
        return True
    for segment in snake[1:]:
        if head.colliderect(segment):
            return True
    return False

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                direction = pygame.Vector2(0, -1)
            if event.key == pygame.K_DOWN:
                direction = pygame.Vector2(0, 1)
            if event.key == pygame.K_LEFT:
                direction = pygame.Vector2(-1, 0)
            if event.key == pygame.K_RIGHT:
                direction = pygame.Vector2(1, 0)

    screen.fill(WHITE)
    move_snake(snake, direction, fruit)
    for segment in snake:
        draw_rect(screen, GREEN, segment)
    draw_rect(screen, RED, fruit)

    if check_collisions(snake):
        snake = [pygame.Rect(5, 5, cell_size, cell_size)]  # Reiniciar la serpiente

    pygame.display.update()
    clock.tick(10)
