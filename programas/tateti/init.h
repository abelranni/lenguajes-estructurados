#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_INIT
#define _INC_INIT

void clear_board();
void draw_board();
void draw_piece(SDL_Texture *texture, int x, int y);
int finish_with_error(const char *message);
void clean_up();
int init();
int add_piece(int x, int y, int player);
SDL_Texture *load_texture(const char *path);

#endif // _INC_INIT
