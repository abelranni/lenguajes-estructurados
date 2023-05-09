#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_MINIMAX
#define _INC_MINIMAX

void ia_move_minimax(int currentPlayer);
int minimax(int depth, int is_maximizing, int player);

#endif // _INC_MINIMAX