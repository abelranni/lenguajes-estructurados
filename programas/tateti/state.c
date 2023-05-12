#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdbool.h>
#include "logic.h"
#include "minimax.h"
#include "render.h"
#include "state.h"
#include "global.h"

typedef enum
{
    INITIAL,     // Inicio del juego, los jugadores están poniendo sus fichas en el tablero
    SELECT_CHIP, // Un jugador selecciona una de sus fichas para moverla
    MOVE_CHIP,   // Un jugador ha seleccionado una ficha y ahora selecciona dónde moverla
    END_GAME     // El juego ha terminado
} GameState;

GameState current_game_state = INITIAL;

typedef struct chip_selection
{
    int x;
    int y;
    int player;
} ChipSelection;

ChipSelection selected_chip = {0, 0, 0};

void state_machine(SDL_Event e)
{
    if (e.type != SDL_MOUSEBUTTONDOWN)
    {
        return;
    }

    switch (current_game_state)
    {
    case INITIAL:
        // Lógica para colocar las fichas en el tablero
        initial_put_chip(e);
        if (chips_counter > 5)
        {
            current_game_state = SELECT_CHIP;
            printf("Juego iniciado\n");
            printf("Jugador %d selecciona ficha\n", current_player);
        }
        break;

    case SELECT_CHIP:
        // Lógica para seleccionar una ficha para mover
        if (check_player_chip_selection(e))
        {
            current_game_state = MOVE_CHIP;
        }
        break;

    case MOVE_CHIP:
        // Lógica para seleccionar dónde mover la ficha seleccionada

        if (check_player_chip_movement(e))
        {
            int x = e.button.x / (SCREEN_WIDTH / 3);
            int y = e.button.y / (SCREEN_HEIGHT / 3);

            if (move_chip(x, y, current_player))
            {
                board[selected_chip.x][selected_chip.y] = 0;
                selected_chip = (ChipSelection){0, 0, 0};

                printf("Movimiento valido\n");
                printf("Jugador %d mueve ficha de (%d, %d) a (%d, %d)\n", current_player, selected_chip.x, selected_chip.y, x, y);

                change_current_player();
                current_game_state = SELECT_CHIP;
            }
        }

        break;

    case END_GAME:
        // Lógica para manejar el final del juego
        int x = e.button.x / (SCREEN_WIDTH / 3);
        int y = e.button.y / (SCREEN_HEIGHT / 3);
        if (x == 1 && y == 1)
        {
            reset_game();
        }
        return;
    }

    int winner = check_winner();
    if ( winner != 0 )
    {
        printf("Juego terminado\n");
        printf("Ganador: Jugador %d\n", winner);
        current_game_state = END_GAME;
        draw_line_winner(winner);
    }

}

void reset_game()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
    chips_counter = 0;
    current_player = 1;
    selected_chip = (ChipSelection){0, 0, 0};
    current_game_state = INITIAL;
}


/*
 *   Coloca las fichas en el tablero
 */
void initial_put_chip(SDL_Event e)
{

    int x = e.button.x / (SCREEN_WIDTH / 3);
    int y = e.button.y / (SCREEN_HEIGHT / 3);

    printf("initial_put_chip: (%d, %d)\n", x, y);

    if (add_chip(x, y, current_player))
    {
        chips_counter++;
        change_current_player();
    }
}

/*
 *   Cambia el jugador actual
 */
void change_current_player()
{
    current_player = (current_player == 1) ? 2 : 1;
}

bool check_player_chip_selection(SDL_Event e)
{

    int x = e.button.x / (SCREEN_WIDTH / 3);
    int y = e.button.y / (SCREEN_HEIGHT / 3);

    if (board[x][y] == current_player)
    {
        selected_chip.x = x;
        selected_chip.y = y;
        selected_chip.player = current_player;
        printf("Ficha seleccionada\n");
        printf("Jugador %d mueve ficha de (%d, %d)\n", current_player, x, y);
        return true;
    }

    return false;
}

bool check_player_chip_movement(SDL_Event e)
{

    int x = e.button.x / (SCREEN_WIDTH / 3);
    int y = e.button.y / (SCREEN_HEIGHT / 3);

    printf("check_player_chip_movement: (%d, %d)\n", x, y);

    if (board[x][y] == 0)
    {
        printf("check_player_chip_movement: (%d, %d) es valido \n", x, y);
        return true;
    }

    printf("check_player_chip_movement: (%d, %d) no es valido \n", x, y);
    printf("board[%d][%d]: %d\n", x, y, board[x][y]);
    return false;
}

bool move_chip(int x, int y, int player)
{
    if (board[x][y] == 0)
    {
        board[x][y] = player;
        return true;
    }

    return false;
}