#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "data.h"

#ifndef _INC_STATE
#define _INC_STATE

typedef enum
{
    INITIAL,     // Inicio del juego, los jugadores están poniendo sus fichas en el tablero
    SELECT_CHIP, // Un jugador selecciona una de sus fichas para moverla
    MOVE_CHIP,   // Un jugador ha seleccionado una ficha y ahora selecciona dónde moverla
    END_GAME     // El juego ha terminado
} GameState;



void state_machine( SDL_Event e );
void initial_place_chip( Cell cell_clicked );
void change_current_player();


bool check_player_chip_selection( Cell cell_clicked);
bool check_player_chip_movement( Cell destination_cell, Cell origin_cell );
bool move_chip(int x, int y, int player); 
void reset_game();
Cell get_cell_xy(int x, int y);
double distance(Cell a, Cell b);
void init_invalid_moves();

void debug_show_board_and_delay();

#endif // _INC_STATE