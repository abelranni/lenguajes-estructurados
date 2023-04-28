#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//-----------------------------------------------------------------------------
// Funciones y Variables exportadas desde MAIN
//-----------------------------------------------------------------------------
#ifndef _INC_MAIN
#define _INC_MAIN

// VARIABLES

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window      *window;
extern SDL_Renderer    *renderer;
extern int fichas_propias;
extern int board[3][3]; 
extern SDL_Texture *player1_texture;
extern SDL_Texture *player2_texture;

// FUNCIONES

#endif // _INC_MAIN