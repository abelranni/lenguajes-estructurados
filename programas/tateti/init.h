#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_INIT
#define _INC_INIT

int finish_with_error(const char *message);
void clean_up();
int init();

#endif // _INC_INIT
