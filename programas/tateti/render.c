#include <SDL2/SDL2_gfxPrimitives.h>

#include <stdio.h>
#include "render.h"
#include "global.h"

// Constantes para personalizar colores
const SDL_Color BACKGROUND_COLOR = {0xFF, 0xFF, 0xFF, 0xFF};
const SDL_Color LINE_COLOR = {0, 0, 0, 0xFF};


void draw_piece(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest_rect;
    dest_rect.x = x * (SCREEN_WIDTH / 3) + (SCREEN_WIDTH / 6) - 16;
    dest_rect.y = y * (SCREEN_HEIGHT / 3) + (SCREEN_HEIGHT / 6) - 16;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}

void draw_board()
{
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, LINE_COLOR.r, LINE_COLOR.g, LINE_COLOR.b, LINE_COLOR.a);

    const int cellWidth = (SCREEN_WIDTH - 2 * PADDING) / 3;
    int lineWidth = 5;
    for (int i = 1; i < 3; ++i)
    {
        SDL_Rect verticalRect = {
            .x = PADDING + i * CELL_WIDTH - lineWidth / 2,
            .y = PADDING,
            .w = lineWidth,
            .h = SCREEN_HEIGHT - 2 * PADDING};
        SDL_Rect horizontalRect = {
            .x = PADDING,
            .y = PADDING + i * CELL_HEIGHT - lineWidth / 2,
            .w = SCREEN_WIDTH - 2 * PADDING,
            .h = lineWidth};

        SDL_RenderFillRect(renderer, &verticalRect);
        SDL_RenderFillRect(renderer, &horizontalRect);
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

void draw_line_winner(int winner)
{
    // Dibujar la línea que indica el ganador
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == winner && board[i][1] == winner && board[i][2] == winner)
        {
            SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / 3 + SCREEN_WIDTH / 6, 0, i * SCREEN_WIDTH / 3 + SCREEN_WIDTH / 6, SCREEN_HEIGHT);
        }
        if (board[0][i] == winner && board[1][i] == winner && board[2][i] == winner)
        {
            SDL_RenderDrawLine(renderer, 0, i * SCREEN_HEIGHT / 3 + SCREEN_HEIGHT / 6, SCREEN_WIDTH, i * SCREEN_HEIGHT / 3 + SCREEN_HEIGHT / 6);
        }
    }
    if (board[0][0] == winner && board[1][1] == winner && board[2][2] == winner)
    {
        SDL_RenderDrawLine(renderer,
                           0,
                           0,
                           SCREEN_WIDTH,
                           SCREEN_HEIGHT);
    }

    if (board[0][2] == winner && board[1][1] == winner && board[2][0] == winner)
    {
        SDL_RenderDrawLine(renderer,
                           0,
                           SCREEN_HEIGHT,
                           SCREEN_WIDTH,
                           0);
    }

    SDL_RenderPresent(renderer);
}

void draw_rounded_rect_winner(int winner)
{
    const Uint8 red = 255, green = 0, blue = 0, alpha = 255;
    const int rectWidth = SCREEN_WIDTH - 2 * PADDING;
    const int rectHeight = (SCREEN_HEIGHT - 2 * PADDING) / 3;
    const float borderRadius = 20.0f;
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == winner && board[i][1] == winner && board[i][2] == winner)
        {
            roundedBoxRGBA(renderer,
                           PADDING + i * CELL_WIDTH,
                           PADDING,
                           PADDING + i * CELL_WIDTH + CELL_WIDTH,
                           PADDING + 3 * CELL_HEIGHT,
                           borderRadius,
                           red,
                           green,
                           blue,
                           alpha);
        }
        if (board[0][i] == winner && board[1][i] == winner && board[2][i] == winner)
        {
            roundedBoxRGBA(renderer,
                           PADDING,
                           PADDING + i * CELL_HEIGHT,
                           PADDING + 3 * CELL_WIDTH,
                           PADDING + i * CELL_HEIGHT + CELL_HEIGHT,
                           borderRadius,
                           red,
                           green,
                           blue,
                           alpha);
        }
    }

    if (board[0][0] == winner && board[1][1] == winner && board[2][2] == winner)
    {
        SDL_RenderDrawLine(renderer,
                           0,
                           0,
                           SCREEN_WIDTH,
                           SCREEN_HEIGHT);
    }

    if (board[0][2] == winner && board[1][1] == winner && board[2][0] == winner)
    {
        SDL_RenderDrawLine(renderer,
                           0,
                           SCREEN_HEIGHT,
                           SCREEN_WIDTH,
                           0);
    }

    // SDL_RenderPresent(renderer);

}
