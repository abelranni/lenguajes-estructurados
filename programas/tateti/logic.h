#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_LOGIC
#define _INC_LOGIC

int add_piece(int x, int y, int player);
void clear_board();
int is_full();
int check_winner();
int check_game_over();

#endif // _INC_LOGIC



