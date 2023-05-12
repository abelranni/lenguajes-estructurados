#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#ifndef _INC_LOGIC
#define _INC_LOGIC

int add_chip(int x, int y, int player);
void clear_board();
bool is_board_full();
int check_winner();
int check_game_over();
void print_board();

#endif // _INC_LOGIC



