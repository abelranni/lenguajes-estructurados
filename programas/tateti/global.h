#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//-----------------------------------------------------------------------------
// Funciones y Variables exportadas desde MAIN
//-----------------------------------------------------------------------------
#ifndef _INC_MAIN
#define _INC_MAIN

// VARIABLES
extern int current_player;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int PADDING;       // Espacio entre las líneas del tablero y los bordes de la ventana
extern const int CELL_WIDTH;    // Ancho de cada celda del tablero
extern const int CELL_HEIGHT;    // Alto de cada celda del tablero

extern SDL_Window      *window;
extern SDL_Renderer    *renderer;
extern int chips_counter;
extern int board[3][3]; 
extern SDL_Texture *player_texture_1;
extern SDL_Texture *player_texture_2;

// FUNCIONES

#endif // _INC_MAIN


#ifndef _INC_RENDER
#define _INC_RENDER

// VARIABLES

// Constantes para personalizar colores
extern const SDL_Color BACKGROUND_COLOR;
extern const SDL_Color LINE_COLOR;




// FUNCIONES

#endif // _INC_RENDER