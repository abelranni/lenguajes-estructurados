#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "global.h"
#include "logic.h"
#include "minimax.h"
#include "render.h"
#include "state.h"

GameState current_game_state = INITIAL;
ChipSelection selected_chip = {0, 0, 0};

/*
* tabla de movimientos adyacentes pero no diagonales
*/
int invalid_moves[3][3][3][3] = {0};

/*
 *   Función de entrada de la máquina de estados
 */
void state_machine(SDL_Event e)
{
    if (e.type != SDL_MOUSEBUTTONDOWN)
    {
        return;
    }

    Cell cell_clicked = get_cell_xy(e.button.x, e.button.y);
    switch (current_game_state)
    {
    case INITIAL:
        // Lógica para colocar las fichas en el tablero
        initial_place_chip(cell_clicked);
        if (chips_counter > 5)
        {
            current_game_state = SELECT_CHIP;
            printf("Juego iniciado\n");
            printf("Jugador %d selecciona ficha\n", current_player);
            init_invalid_moves();
        }
        break;

    case SELECT_CHIP:
        // Lógica para seleccionar una ficha para mover
        if (check_player_chip_selection(cell_clicked))
        {
            current_game_state = MOVE_CHIP;
        }
        break;

    case MOVE_CHIP:

        if ((cell_clicked.x == selected_chip.cell.x) && (cell_clicked.y == selected_chip.cell.y)) 
        {
            printf("Ficha deseleccionada\n");
            selected_chip = (ChipSelection){0, 0, 0};
            current_game_state = SELECT_CHIP;
            break;
        }

        // Lógica para seleccionar dónde mover la ficha seleccionada
        if (check_player_chip_movement(cell_clicked))
        {
            if (move_chip(cell_clicked.x, cell_clicked.y, current_player))
            {
                board[selected_chip.cell.x][selected_chip.cell.y] = 0;
                selected_chip = (ChipSelection){0, 0, 0};

                printf("Movimiento valido\n");
                printf("Jugador %d mueve ficha de (%d, %d) a (%d, %d)\n",
                       current_player,
                       selected_chip.cell.x, selected_chip.cell.y,
                       cell_clicked.x, cell_clicked.y);

                change_current_player();
                current_game_state = SELECT_CHIP;
            }
        }
        break;

    case END_GAME:
        // Lógica para manejar el final del juego
        if (cell_clicked.x == 1 && cell_clicked.y == 1)
        {
            reset_game();
        }
        return;
    }

    int winner = check_winner();
    if (winner != 0)
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
void initial_place_chip(Cell cell_clicked)
{
    printf("initial_put_chip: (%d, %d)\n", cell_clicked.x, cell_clicked.y);
    if (add_chip(cell_clicked.x, cell_clicked.y, current_player))
    {
        chips_counter++;
        change_current_player();
        ia_place_chip_minimax(current_player);
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
bool check_player_chip_selection(Cell cell_clicked) 
{
    if (board[cell_clicked.x][cell_clicked.y] == current_player)
    {
        selected_chip.cell.x = cell_clicked.x;
        selected_chip.cell.y = cell_clicked.y;
        selected_chip.player = current_player;
        printf("Ficha seleccionada\n");
        printf("Jugador %d mueve ficha de (%d, %d)\n", current_player, cell_clicked.x, cell_clicked.y);
        return true;
    }
    return false;
}

/*
 *   Verifica si el jugador selecciona una casilla válida para mover su ficha
 */
bool check_player_chip_movement(Cell cell_clicked)
{   
    // Verificar si la celda de destino está vacía
    if (board[cell_clicked.x][cell_clicked.y] != 0)
    {
        printf("CELDA OCUPADA\n");
        printf("check_player_chip_movement: (%d, %d) no es valido \n", cell_clicked.x, cell_clicked.y);
        return false;
    }

    // Verificar si la celda de destino es adyacente a la celda de origen
    double dist = distance(selected_chip.cell, cell_clicked);
    if (dist > sqrt(2)) {
        printf("CELDA NO ADYACENTE\n");
        printf("check_player_chip_movement: (%d, %d) no es valido \n", cell_clicked.x, cell_clicked.y);
        return false;    
    }

    // Verificar si la celda de destino es válida
    if (invalid_moves[selected_chip.cell.x][selected_chip.cell.y][cell_clicked.x][cell_clicked.y] == 1) {
        printf("CELDA ADYACENTE INVALIDA\n");
        printf("check_player_chip_movement: (%d, %d) no es valido \n", cell_clicked.x, cell_clicked.y);
        return false;
    }

    printf("check_player_chip_movement: (%d, %d) valido \n", cell_clicked.x, cell_clicked.y);
    printf("board[%d][%d]: %d\n", cell_clicked.x, cell_clicked.y, board[cell_clicked.x][cell_clicked.y]);
    return true;
}


/*
 *   Inicializa la tabla de movimientos válidos
 */
void init_invalid_moves()
{
    for (int i = 0; i < 3; i++)
    {
        invalid_moves[i][i][i][i] = 1;
    }
    invalid_moves[1][0][0][1] = 1; // 1,0 -> 0,1
    invalid_moves[1][0][2][1] = 1; // 1,0 -> 2,1

    invalid_moves[0][1][1][0] = 1; // 0,1 -> 1,0
    invalid_moves[0][1][1][2] = 1; // 0,1 -> 1,2

    invalid_moves[2][1][1][0] = 1; // 2,1 -> 1,0
    invalid_moves[2][1][1][2] = 1; // 2,1 -> 1,2
    
    invalid_moves[1][2][2][1] = 1; // 1,2 -> 2,1
    invalid_moves[1][2][0][1] = 1; // 1,2 -> 0,1
}

// Función para calcular la distancia entre dos celdas
double distance(Cell a, Cell b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
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
    cell.x = x / (BOARD_WIDTH / 3);
    cell.y = y / (BOARD_HEIGHT / 3);
    return cell;
}