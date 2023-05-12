#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#ifndef _INC_EVENT
#define _INC_EVENT

void handle_mouse_event(SDL_Event e, bool *must_restart_game);

#endif // _INC_EVENT