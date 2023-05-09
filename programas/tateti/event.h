#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_EVENT
#define _INC_EVENT

void handle_mouse_event(SDL_Event e, int *currentPlayer, int *restart);

#endif // _INC_EVENT