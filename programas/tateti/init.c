#include <stdio.h>
#include "init.h"
#include "global.h"


int init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Tateti", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Error al crear el renderizador: %s\n", SDL_GetError());
        return 0;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        return 0;
    }

    if (TTF_Init() < 0)
    {
        printf("Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        return 0;
    }

    return 1;
}

void clean_up()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

// Función para manejar errores y limpiar la memoria
int finish_with_error(const char *message)
{
    printf("%s\n", message);
    clean_up();
    return 1;
}






