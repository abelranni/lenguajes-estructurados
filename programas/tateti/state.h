#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#ifndef _INC_STATE
#define _INC_STATE

void state_machine( SDL_Event e );
void initial_put_chip( SDL_Event e );
void change_current_player();


bool check_player_chip_selection( SDL_Event e);
bool check_player_chip_movement( SDL_Event e);
bool move_chip(int x, int y, int player); 
void reset_game();


#endif // _INC_STATE