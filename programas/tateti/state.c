#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdbool.h>
#include "global.h"
#include "logic.h"
#include "minimax.h"
#include "render.h"
#include "state.h"

GameState current_game_state = INITIAL;
ChipSelection selected_chip = {0, 0, 0};

/*
*   Función de entrada de la máquina de estados
*/
void state_machine(SDL_Event e)
{
    if (e.type != SDL_MOUSEBUTTONDOWN)
    {
        return;
    }

    Cell cell = get_cell_xy(e.button.x, e.button.y);
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
            if (move_chip(cell.x, cell.y, current_player))
            {
                board[selected_chip.cell.x][selected_chip.cell.y] = 0;
                selected_chip = (ChipSelection){0, 0, 0};

                printf("Movimiento valido\n");
                printf("Jugador %d mueve ficha de (%d, %d) a (%d, %d)\n", current_player, selected_chip.cell.x, selected_chip.cell.y, cell.x, cell.y);

                change_current_player();
                current_game_state = SELECT_CHIP;
            }
        }
        break;

    case END_GAME:
        // Lógica para manejar el final del juego
        if (cell.x == 1 && cell.y == 1)
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
    }

}

/*
* Resetea el juego
*/
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
    Cell cell = get_cell_xy(e.button.x, e.button.y);

    printf("initial_put_chip: (%d, %d)\n", cell.x, cell.y);

    if (add_chip(cell.x, cell.y, current_player))
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

/*
*   Verifica si el jugador selecciona una de sus fichas
*/
bool check_player_chip_selection(SDL_Event e)
{
    Cell cell = get_cell_xy(e.button.x, e.button.y);
    if (board[cell.x][cell.y] == current_player)
    {
        selected_chip.cell.x = cell.x;
        selected_chip.cell.y = cell.y;
        selected_chip.player = current_player;
        printf("Ficha seleccionada\n");
        printf("Jugador %d mueve ficha de (%d, %d)\n", current_player, cell.x, cell.y);
        return true;
    }
    return false;
}

/*
*   Verifica si el jugador selecciona una casilla válida para mover su ficha
*/
bool check_player_chip_movement(SDL_Event e)
{
    Cell cell = get_cell_xy(e.button.x, e.button.y);
    printf("check_player_chip_movement: (%d, %d)\n", cell.x, cell.y);
    if (board[cell.x][cell.y] == 0)
    {
        printf("check_player_chip_movement: (%d, %d) es valido \n", cell.x, cell.y);
        return true;
    }
    printf("check_player_chip_movement: (%d, %d) no es valido \n", cell.x, cell.y);
    printf("board[%d][%d]: %d\n", cell.x, cell.y, board[cell.x][cell.y]);
    return false;
}

/*
*   Mueve la ficha seleccionada a la casilla seleccionada
*/
bool move_chip(int x, int y, int player)
{
    if (board[x][y] == 0)
    {
        board[x][y] = player;
        return true;
    }
    return false;
}

/*
*   Obtiene la celda seleccionada según las coordenadas del mouse
*/
Cell get_cell_xy(int x, int y)
{
    Cell cell = {0, 0};
    cell.x = x / (SCREEN_WIDTH / 3);
    cell.y = y / (SCREEN_HEIGHT / 3);
    return cell;
}