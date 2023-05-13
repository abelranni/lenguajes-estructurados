#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#ifndef _INC_STATE
#define _INC_STATE

typedef enum
{
    INITIAL,     // Inicio del juego, los jugadores están poniendo sus fichas en el tablero
    SELECT_CHIP, // Un jugador selecciona una de sus fichas para moverla
    MOVE_CHIP,   // Un jugador ha seleccionado una ficha y ahora selecciona dónde moverla
    END_GAME     // El juego ha terminado
} GameState;

typedef struct cell
{
    int x;
    int y;
} Cell;
typedef struct chip_selection
{
    Cell cell;
    int player;
} ChipSelection;

void state_machine( SDL_Event e );
void initial_put_chip( SDL_Event e );
void change_current_player();


bool check_player_chip_selection( SDL_Event e);
bool check_player_chip_movement( SDL_Event e);
bool move_chip(int x, int y, int player); 
void reset_game();
Cell get_cell_xy(int x, int y);


#endif // _INC_STATE