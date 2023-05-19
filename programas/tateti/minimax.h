#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "state.h"

#ifndef _INC_MINIMAX
#define _INC_MINIMAX

void ia_place_chip_minimax(int current_player);
int minimax_place(int depth, int is_maximizing, int player);

void ia_move_chip_minimax(int current_player);
int minimax_move(int depth, int is_maximizing, int player);
void ia_move_chip( Cell origin_cell, Cell destination_cell, int current_player);

#endif // _INC_MINIMAX