#include <stdio.h>
#include <stdbool.h>
#include "logic.h"
#include "minimax.h"
#include "event.h"
#include "global.h"

/*
*   Función para manejar los eventos de SDL
*/
void handle_mouse_event(SDL_Event e, bool *must_restart_game)
{
    int x = e.button.x / (SCREEN_WIDTH / 3);
    int y = e.button.y / (SCREEN_HEIGHT / 3);

    if (chips_counter < 6)
    {
        chips_counter++;
        if (add_chip(x, y, current_player))
        {
            if (check_game_over(current_player))
            {
                *must_restart_game = true;
                return;
            }
            current_player = (current_player == 1) ? 2 : 1; // Cambiar el jugador actual
            
            // El programa juega automáticamente después del movimiento del jugador humano
            // if (current_player == 2)
            // {
            //     ia_move_minimax(current_player);
            //     if (check_game_over(current_player))
            //     {
            //         *must_restart_game = true;
            //         return;
            //     }
            //     current_player = 1; // Cambiar el jugador actual de vuelta al jugador humano
            // }
        }
    }
    else
    {

    }


}

