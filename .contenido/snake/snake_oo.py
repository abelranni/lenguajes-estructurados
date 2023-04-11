import pygame
import sys
import random

# Configuración inicial
pygame.init()
clock = pygame.time.Clock()

# Tamaño de la ventana y de los bloques
cell_size = 20
cell_number = 20
screen = pygame.display.set_mode((cell_number * cell_size, cell_number * cell_size))

# Colores
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)

class Snake:
    def __init__(self):
        self.body = [pygame.Rect(5, 5, cell_size, cell_size)]
        self.direction = pygame.Vector2(1, 0)

    def draw(self):
        for segment in self.body:
            pygame.draw.rect(screen, GREEN, segment)

    def move(self):
        new_head = self.body[0].copy()
        new_head.move_ip(self.direction * cell_size)
        self.body.insert(0, new_head)
        if new_head.colliderect(fruit.rect):
            fruit.randomize()
        else:
            self.body.pop()

    def check_collisions(self):
        head = self.body[0]
        if head.x < 0 or head.y < 0 or head.x >= cell_number * cell_size or head.y >= cell_number * cell_size:
            return True
        for segment in self.body[1:]:
            if head.colliderect(segment):
                return True
        return False

class Fruit:
    def __init__(self):
        self.randomize()

    def draw(self):
        pygame.draw.rect(screen, RED, self.rect)

    def randomize(self):
        x = random.randint(0, cell_number - 1) * cell_size
        y = random.randint(0, cell_number - 1) * cell_size
        self.rect = pygame.Rect(x, y, cell_size, cell_size)


snake = Snake()
fruit = Fruit()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                snake.direction = pygame.Vector2(0, -1)
            if event.key == pygame.K_DOWN:
                snake.direction = pygame.Vector2(0, 1)
            if event.key == pygame.K_LEFT:
                snake.direction = pygame.Vector2(-1, 0)
            if event.key == pygame.K_RIGHT:
                snake.direction = pygame.Vector2(1, 0)

    screen.fill(WHITE)
    snake.move()
    snake.draw()
    fruit.draw()

    # if snake.body[0].colliderect(fruit.rect):
    #     fruit.randomize()
    if snake.check_collisions():
        snake = Snake()  # Reiniciar la serpiente        

    pygame.display.update()
    clock.tick(10)


