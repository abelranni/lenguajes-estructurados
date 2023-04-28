#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_MAIN
#define _INC_MAIN

int is_full();
int check_winner();
int check_game_over();
void draw_line_winner(int winner);
int minimax(int depth, int is_maximizing, int player);
void ia_move_minimax(int currentPlayer);
void ia_move(int currentPlayer);
void handle_mouse_event(SDL_Event e, int *currentPlayer, int *restart);
int WinMain();


#endif // _INC_MAIN

/* 
Compilar fuentes por separado:
gcc -c init.c -o init.o
gcc -c main.c -o main.o

Luego linkear con:
gcc .\main.o .\init.o  -o tateti.exe -lSDL2 -lSDL2_ttf -lSDL2_image
*/