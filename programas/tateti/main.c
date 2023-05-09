#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "render.h"
#include "logic.h"
#include "minimax.h"
#include "event.h"
#include "main.h"
#include "global.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDING = 10;
const int CELL_WIDTH = (SCREEN_WIDTH - 2 * PADDING)/3;
const int CELL_HEIGHT = (SCREEN_HEIGHT - 2 * PADDING)/3;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int fichas_propias = 0;

/*
La matriz board representa el estado del tablero:
0: casilla vacía
1: ficha del jugador 1
2: ficha del jugador 2
*/
int board[3][3] = {0};

// Texturas para las fichas del jugador 1 y 2
SDL_Texture *player1_texture = NULL;
SDL_Texture *player2_texture = NULL;

int WinMain(void)
{
    if (!init())
    {
        return finish_with_error("Error al inicializar");
    }

    player1_texture = load_texture("./assets/rojo.png");
    player2_texture = load_texture("./assets/verde.png");

    if (!player1_texture || !player2_texture)
    {
        return finish_with_error("Error al cargar las texturas de las fichas");
    }

    int quit = 0;
    int restart = 0;
    SDL_Event e;
    int currentPlayer = 1;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (restart)
                {
                    restart = 0;
                    currentPlayer = 1;
                    clear_board();
                }
                else
                {
                    handle_mouse_event(e, &currentPlayer, &restart);
                }
            }
        }

        draw_board();
        if (restart)
        {
            //draw_line_winner(check_winner());
            draw_rounded_rect_winner(check_winner());
            fichas_propias = 0;
        }
        SDL_RenderPresent(renderer);
    }

    clean_up();
    return 0;
}
