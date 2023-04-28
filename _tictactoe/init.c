#include <stdio.h>
#include "init.h"
#include "global.h"


SDL_Texture *load_texture(const char *path)
{
    SDL_Surface *loaded_surface = IMG_Load(path);
    if (!loaded_surface)
    {
        printf("Error al cargar la imagen %s: %s\n", path, IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if (!texture)
    {
        printf("Error al crear la textura a partir de %s: %s\n", path, SDL_GetError());
    }

    SDL_FreeSurface(loaded_surface);

    return texture;
}

/*
La función add_piece agrega una ficha en la posición (x, y) del tablero.
Retorna:
- 1 si se pudo agregar la ficha
- 0 en caso contrario
*/

int add_piece(int x, int y, int player)
{
    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        return 0;
    }

    if (board[x][y] != 0)
    {
        return 0;
    }

    board[x][y] = player;
    return 1;
}

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

void draw_piece(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest_rect;
    dest_rect.x = x * (SCREEN_WIDTH / 3) + (SCREEN_WIDTH / 6) - 16;
    dest_rect.y = y * (SCREEN_HEIGHT / 3) + (SCREEN_HEIGHT / 6) - 16;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}

void clear_board()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = 0;
        }
    }
}


// Constantes para personalizar colores
const SDL_Color BACKGROUND_COLOR = {0xFF, 0xFF, 0xFF, 0xFF};
const SDL_Color LINE_COLOR = {0, 0, 0, 0xFF};

// Espacio entre las líneas del tablero y los bordes de la ventana
const int PADDING = 10;

void draw_board()
{
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, LINE_COLOR.r, LINE_COLOR.g, LINE_COLOR.b, LINE_COLOR.a);
    for (int i = 1; i < 3; ++i)
    {
        SDL_RenderDrawLine(renderer, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3 - 1, PADDING, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3 - 1, SCREEN_HEIGHT - PADDING);
        SDL_RenderDrawLine(renderer, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3, PADDING, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3, SCREEN_HEIGHT - PADDING);
        SDL_RenderDrawLine(renderer, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3 + 1, PADDING, PADDING + i * (SCREEN_WIDTH - 2 * PADDING) / 3 + 1, SCREEN_HEIGHT - PADDING);

        SDL_RenderDrawLine(renderer, PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3 - 1, SCREEN_WIDTH - PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3 - 1);
        SDL_RenderDrawLine(renderer, PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3, SCREEN_WIDTH - PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3);
        SDL_RenderDrawLine(renderer, PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3 + 1, SCREEN_WIDTH - PADDING, PADDING + i * (SCREEN_HEIGHT - 2 * PADDING) / 3 + 1);
    }

    // Dibujar las fichas en el tablero
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 1)
            {
                draw_piece(player1_texture, i, j);
            }
            else if (board[i][j] == 2)
            {
                draw_piece(player2_texture, i, j);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

// void draw_board()
// {
//     SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//     SDL_RenderClear(renderer);

//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
//     for (int i = 1; i < 3; ++i)
//     {
//         SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / 3 - 1, 0, i * SCREEN_WIDTH / 3 - 1, SCREEN_HEIGHT);
//         SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / 3, 0, i * SCREEN_WIDTH / 3, SCREEN_HEIGHT);
//         SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / 3 + 1 , 0, i * SCREEN_WIDTH / 3 + 1, SCREEN_HEIGHT);

//         SDL_RenderDrawLine(renderer, 0, i * SCREEN_HEIGHT / 3 - 1 , SCREEN_WIDTH, i * SCREEN_HEIGHT / 3 - 1);
//         SDL_RenderDrawLine(renderer, 0, i * SCREEN_HEIGHT / 3, SCREEN_WIDTH, i * SCREEN_HEIGHT / 3);
//         SDL_RenderDrawLine(renderer, 0, i * SCREEN_HEIGHT / 3 + 1, SCREEN_WIDTH, i * SCREEN_HEIGHT / 3 + 1);
//     }

//     // Dibujar las fichas en el tablero
//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             if (board[i][j] == 1)
//             {
//                 draw_piece(player1_texture, i, j);
//             }
//             else if (board[i][j] == 2)
//             {
//                 draw_piece(player2_texture, i, j);
//             }
//         }
//     }

//     SDL_RenderPresent(renderer);
// }