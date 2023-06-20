#ifdef _WIN32
#include <wtypes.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init.h"
#include "render.h"
#include "logic.h"
#include "minimax.h"
#include "event.h"
#include "state.h"
#include "udp.h"
#include "config.h"
#include "debug.h"
#include "main.h"
#include "global.h"
#include "score.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 520;
const int BOARD_WIDTH = 640;
const int BOARD_HEIGHT = SCREEN_HEIGHT - 40;
const int PADDING = 10;
const int CELL_WIDTH = (BOARD_WIDTH - 2 * PADDING) / 3;
const int CELL_HEIGHT = (BOARD_HEIGHT - 2 * PADDING) / 3;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int chips_counter = 0; // Contador de Fichas

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

Config config = {0};

TTF_Font *font = NULL;

// Texturas para las fichas del jugador 1 y 2
SDL_Texture *player_texture_1 = NULL;
SDL_Texture *player_texture_2 = NULL;
int current_player = 1;

/*
 *   Función principal
 */
#ifdef _WIN32
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char *, int nShowCmd)
{
    return main(__argc, __argv);
}
int main(int argc, char *argv[])
#else
int main(int argc, char *argv[])

#endif
{
    (void)parse_command(argc, argv);
    config = read_config("./config.cfg");
    DEBUG2("Configuración:\n");
    DEBUG2("Modo de juego: %d\n", config.game_mode);
    DEBUG2("Ancho de pantalla: %d\n", config.screen_width);
    DEBUG2("Alto de pantalla: %d\n", config.screen_height);
    DEBUG2("Color de fondo: %d,%d,%d\n",
           config.background_color[0],
           config.background_color[1],
           config.background_color[2]);

    if (!init())
    {
        return finish_with_error("Error al inicializar");
    }

    player_texture_1 = load_texture("./assets/circle.png");
    player_texture_2 = load_texture("./assets/xcross.png");

    if (!player_texture_1 || !player_texture_2)
    {
        return finish_with_error("Error al cargar las texturas de las fichas");
    }

    bool quit_main_loop = false;
    bool must_restart_game = false;

    SDL_Event e;

    font = TTF_OpenFont("./assets/OpenSans-Regular.ttf", 24);
    if (!font)
    {
        return finish_with_error("Error al cargar la fuente");
    }

    (void)udp_config();
    udp_send("000000000");

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

        SDL_RenderClear(renderer); // Limpia la pantalla

        draw_board();
        render_info_game();
        draw_line_winner(check_winner());

        SDL_RenderPresent(renderer);
    }

    clean_up();
    return 0;
}

void render_info_game()
{
    char playerTurnText[50];
    int player_one_wins = get_player_one_wins();
    int player_two_wins = get_player_two_wins();
    sprintf(playerTurnText, "Turno del jugador: %d\t\t\t\t Victorias P1: %d, P2: %d", current_player, player_one_wins, player_two_wins);
    render_text(playerTurnText, 10, SCREEN_HEIGHT - 50);
}
