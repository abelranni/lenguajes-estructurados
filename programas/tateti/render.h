#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_RENDER
#define _INC_RENDER

SDL_Texture *load_texture(const char *path);

void draw_board();
void draw_all_chips();
void draw_chip(SDL_Texture *texture, int x, int y);

void draw_line_winner(int winner);
void draw_rounded_rect_winner(int winner);


#endif // _INC_RENDER