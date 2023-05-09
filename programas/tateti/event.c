
#include <stdio.h>
#include "logic.h"
#include "minimax.h"
#include "event.h"
#include "global.h"


// Función para manejar el evento SDL_MOUSEBUTTONDOWN
void handle_mouse_event(SDL_Event e, int *currentPlayer, int *restart)
{
    int x = e.button.x / (SCREEN_WIDTH / 3);
    int y = e.button.y / (SCREEN_HEIGHT / 3);

    if (fichas_propias < 3)
    {
        fichas_propias++;
        if (add_piece(x, y, *currentPlayer))
        {
            if (check_game_over(*currentPlayer))
            {
                *restart = 1;
                return;
            }
            *currentPlayer = (*currentPlayer == 1) ? 2 : 1; // Cambiar el jugador actual
            
            // El programa juega automáticamente después del movimiento del jugador humano
            if (*currentPlayer == 2)
            {
                ia_move_minimax(*currentPlayer);
                if (check_game_over(*currentPlayer))
                {
                    *restart = 1;
                    return;
                }
                *currentPlayer = 1; // Cambiar el jugador actual de vuelta al jugador humano
            }
        }
    }
    else
    {

    }


}

