#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "data.h"
#include "config.h"

//-----------------------------------------------------------------------------
// Funciones y Variables exportadas desde MAIN
//-----------------------------------------------------------------------------
#ifndef _INC_MAIN
#define _INC_MAIN

extern int current_player;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int BOARD_WIDTH;
extern const int BOARD_HEIGHT;
extern const int PADDING;       // Espacio entre las líneas del tablero y los bordes de la ventana
extern const int CELL_WIDTH;    // Ancho de cada celda del tablero
extern const int CELL_HEIGHT;    // Alto de cada celda del tablero

extern SDL_Window      *window;
extern SDL_Renderer    *renderer;
extern int chips_counter;
extern int board[3][3]; 
extern Config config;

extern SDL_Texture *player_texture_1;
extern SDL_Texture *player_texture_2;
extern TTF_Font *font;

#endif // _INC_MAIN

//-----------------------------------------------------------------------------


#ifndef _INC_RENDER
#define _INC_RENDER

// Constantes para personalizar colores
extern const SDL_Color BACKGROUND_COLOR;
extern const SDL_Color LINE_COLOR;

#endif // _INC_RENDER

#ifndef _INC_STATE

// extern GameState current_game_state;
extern ChipSelection selected_chip;

#endif // _INC_STATE