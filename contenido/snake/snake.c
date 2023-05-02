#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x;
    int y;
} Coordenada;

typedef struct
{
    Coordenada *cuerpo;
    int longitud;
} Serpiente;

Serpiente *crear_serpiente(int longitud_inicial)
{
    Serpiente *serpiente = (Serpiente *)malloc(sizeof(Serpiente));
    serpiente->longitud = longitud_inicial;
    serpiente->cuerpo = (Coordenada *)malloc(longitud_inicial * sizeof(Coordenada));
    for (int i = 0; i < longitud_inicial; i++)
    {
        serpiente->cuerpo[i].x = i + 1;
        serpiente->cuerpo[i].y = 1;
    }
    return serpiente;
}

void destruir_serpiente(Serpiente *serpiente)
{
    free(serpiente->cuerpo);
    free(serpiente);
}

void mover_serpiente(Serpiente *serpiente, int direccion)
{
    for (int i = serpiente->longitud - 1; i > 0; i--)
    {
        serpiente->cuerpo[i] = serpiente->cuerpo[i - 1];
    }

    // Actualizar la posición de la cabeza de la serpiente según la dirección
    switch (direccion)
    {
    case 0: // Arriba
        serpiente->cuerpo[0].y--;
        break;
    case 1: // Derecha
        serpiente->cuerpo[0].x++;
        break;
    case 2: // Abajo
        serpiente->cuerpo[0].y++;
        break;
    case 3: // Izquierda
        serpiente->cuerpo[0].x--;
        break;
    }
}

int colision(Serpiente* serpiente, int ancho, int alto) {
    Coordenada cabeza = serpiente->cuerpo[0];

    // Verificar si la cabeza choca con los límites del área de juego
    if (cabeza.x < 0 || cabeza.x >= ancho || cabeza.y < 0 || cabeza.y >= alto) {
        printf ("Colision con los limites del area de juego \n");        
        return 1;
    }

    // Verificar si la cabeza choca con alguna parte del cuerpo
    for (int i = 1; i < serpiente->longitud-1; i++) {
        if (cabeza.x == serpiente->cuerpo[i].x && cabeza.y == serpiente->cuerpo[i].y) {
            printf ("Colision con el cuerpo \n");
            return 1;
        }
    }

    // Si no hay colisiones, retornar 0
    return 0;
}

int comer(Serpiente *serpiente, Coordenada comida)
{
    if (serpiente->cuerpo[0].x == comida.x && serpiente->cuerpo[0].y == comida.y)
    {
        serpiente->longitud++;
        serpiente->cuerpo = (Coordenada *)realloc(serpiente->cuerpo, serpiente->longitud * sizeof(Coordenada));
        serpiente->cuerpo[serpiente->longitud - 1] = serpiente->cuerpo[serpiente->longitud - 2];
        return 1;
    }
    return 0;
}

void dibujar_serpiente(SDL_Renderer *renderer, Serpiente *serpiente, int size_celda)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rect;
    rect.w = size_celda;
    rect.h = size_celda;
    rect.x = serpiente->cuerpo[0].x * size_celda;
    rect.y = serpiente->cuerpo[0].y * size_celda;
    SDL_RenderFillRect(renderer, &rect);    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    for (int i = 1; i < serpiente->longitud; i++)
    {
        rect.x = serpiente->cuerpo[i].x * size_celda;
        rect.y = serpiente->cuerpo[i].y * size_celda;
        SDL_RenderFillRect(renderer, &rect);
    }
}

void dibujar_comida(SDL_Renderer *renderer, Coordenada comida, int size_celda)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = comida.x * size_celda;
    rect.y = comida.y * size_celda;
    rect.w = size_celda;
    rect.h = size_celda;
    SDL_RenderFillRect(renderer, &rect);
}

Coordenada generar_comida(Serpiente *serpiente, int ancho, int alto)
{
    Coordenada comida;
    int ocupado;
    do
    {
        ocupado = 0;
        comida.x = rand() % ancho;
        comida.y = rand() % alto;
        for (int i = 0; i < serpiente->longitud; i++)
        {
            if (serpiente->cuerpo[i].x == comida.x && serpiente->cuerpo[i].y == comida.y)
            {
                ocupado = 1;
                break;
            }
        }

    } while (ocupado);
    return comida;
}

void manejar_eventos(int *salir, int *iniciar_movimiento, int *direccion)
{
    SDL_Event evento;
    while (SDL_PollEvent(&evento))
    {
        switch (evento.type)
        {

        case SDL_QUIT:
            *salir = 1;
            break;

        case SDL_KEYDOWN:

            // printf("Tecla presionada %d \n", evento.key.keysym.scancode);
            switch (evento.key.keysym.scancode)
            {
            case SDL_SCANCODE_UP:
                if (*direccion != 2)
                {
                    *direccion = 0;
                    *iniciar_movimiento = 1;
                }
                break;
            case SDL_SCANCODE_RIGHT:
                if (*direccion != 3)
                {
                    *direccion = 1;
                    *iniciar_movimiento = 1;
                }
                break;
            case SDL_SCANCODE_DOWN:
                if (*direccion != 0)
                {
                    *direccion = 2;
                    *iniciar_movimiento = 1;
                }
                break;
            case SDL_SCANCODE_LEFT:
                if (*direccion != 1)
                {
                    *direccion = 3;
                    *iniciar_movimiento = 1;
                }
                break;

            default:
                break;

            }
        }
    }
}

// int WinMain(int argc, char *argv[])
int WinMain()
{
    srand(time(NULL));
    int ancho = 20;
    int alto = 15;
    int size_celda = 32;
    int velocidad = 100;

    // SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          ancho * size_celda, 
                                          alto * size_celda, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Serpiente *serpiente = crear_serpiente(5);
    Coordenada comida = generar_comida(serpiente, ancho, alto);

    int direccion = 1; // 0 = arriba, 1 = derecha, 2 = abajo, 3 = izquierda
                       // Inicializamos la dirección en -1 (ninguna dirección)
    int iniciar_movimiento = 0;
    int salir = 0;

    while (!salir)
    {
        manejar_eventos(&salir, &iniciar_movimiento, &direccion);

        if (iniciar_movimiento)
        {
            mover_serpiente(serpiente, direccion);

            if (colision(serpiente, ancho, alto))
            {
                printf("Colision \n");
                while (!salir)
                {
                    SDL_Event evento;
                    while (SDL_PollEvent(&evento))
                    {
                        if (evento.type == SDL_QUIT)
                        {
                            salir = 1;
                        }
                    }
                    SDL_Delay(100);
                }
            }

            if (comer(serpiente, comida))
            {
                printf("Comer \n");
                comida = generar_comida(serpiente, ancho, alto);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        dibujar_serpiente(renderer, serpiente, size_celda);

        dibujar_comida(renderer, comida, size_celda);

        SDL_RenderPresent(renderer);

        SDL_Delay(velocidad);
    }

    destruir_serpiente(serpiente);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}