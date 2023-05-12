#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init.h"
#include "render.h"
#include "logic.h"
#include "minimax.h"
#include "event.h"
#include "state.h"
#include "main.h"
#include "global.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDING = 10;
const int CELL_WIDTH = (SCREEN_WIDTH - 2 * PADDING) / 3;
const int CELL_HEIGHT = (SCREEN_HEIGHT - 2 * PADDING) / 3;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int chips_counter = 0;      // Contador de Fichas

/**
 *  \brief Mouse button event structure (event.button.*)
 */


/*
La matriz board representa el estado del tablero:
0: casilla vacía
1: ficha del jugador 1
2: ficha del jugador 2
*/
int board[3][3] = {0};

// Texturas para las fichas del jugador 1 y 2
SDL_Texture *player_texture_1 = NULL;
SDL_Texture *player_texture_2 = NULL;
int current_player = 1;

/*
*   Función principal
*/
int WinMain(void)
{
    if (!init())
    {
        return finish_with_error("Error al inicializar");
    }

    player_texture_1 = load_texture("./assets/rojo.png");
    player_texture_2 = load_texture("./assets/verde.png");

    if (!player_texture_1 || !player_texture_2)
    {
        return finish_with_error("Error al cargar las texturas de las fichas");
    }

    bool quit_main_loop = false;
    bool must_restart_game = false;

    SDL_Event e;

    while (!quit_main_loop)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit_main_loop = true;
            }
            state_machine(e);
        }
        draw_line_winner(check_winner());
        draw_board();
        SDL_RenderPresent(renderer);
    }

    clean_up();
    return 0;
}
