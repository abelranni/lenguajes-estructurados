#include <stdio.h>
#include <stdlib.h> // para rand()
#include <time.h>   // para time()
#include <math.h>

#include "init.h"
#include "main.h"
#include "global.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window      *window     = NULL;
SDL_Renderer    *renderer   = NULL;
int fichas_propias = 0;

/* 
La matriz board representa el estado del tablero
Puede tener los siguientes valores:
0: casilla vacía 
1: ficha del jugador 1
2: ficha del jugador 2
*/
int board[3][3] = {0}; 

// Texturas para las fichas del jugador 1 y 2
SDL_Texture *player1_texture = NULL;
SDL_Texture *player2_texture = NULL;

int is_full()
{
    int empty_cells = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                empty_cells++;
            }
        }
    }
    if (empty_cells == 0)
    {
        return 1;
    }
    return 0;
}

int check_winner()
{
    // Verificar filas
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Verificar columnas
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Verificar diagonales
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    return 0;
}

int check_game_over()
{
    printf("Verificando si el juego ha terminado...\n");
    int winner = check_winner();
    if (winner != 0)
    {
        printf("El jugador %d ha ganado!\n", winner);
        return 1;
    }

    if (is_full())
    {
        printf("Empate!\n");
        return 1;
    }

    return 0;
}

void draw_line_winner(int winner)
{
    // Dibujar la línea que indica el ganador
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == winner && board[i][1] == winner && board[i][2] == winner)
        {
            SDL_RenderDrawLine(renderer, i * SCREEN_WIDTH / 3 + SCREEN_WIDTH / 6, 0, i * SCREEN_WIDTH / 3 + SCREEN_WIDTH / 6, SCREEN_HEIGHT);
        }
        if (board[0][i] == winner && board[1][i] == winner && board[2][i] == winner)
        {
            SDL_RenderDrawLine(renderer, 0, i * SCREEN_HEIGHT / 3 + SCREEN_HEIGHT / 6, SCREEN_WIDTH, i * SCREEN_HEIGHT / 3 + SCREEN_HEIGHT / 6);
        }
    }
    if (board[0][0] == winner && board[1][1] == winner && board[2][2] == winner)
    {
        SDL_RenderDrawLine(renderer, 
                           0, 
                           0, 
                           SCREEN_WIDTH, 
                           SCREEN_HEIGHT
                           );
    }    

    if (board[0][2] == winner && board[1][1] == winner && board[2][0] == winner)
    {
        SDL_RenderDrawLine(renderer, 
                           0, 
                           SCREEN_HEIGHT, 
                           SCREEN_WIDTH, 
                           0
                           );
    }     

    SDL_RenderPresent(renderer);
}

int minimax(int depth, int is_maximizing, int player)
{
    int winner = check_winner();
    if (winner != 0)
    {
        return winner == player ? 1 : -1;
    }

    if (is_full())
    {
        return 0;
    }

    int best_value = is_maximizing ? -1000 : 1000;
    int opponent = player == 1 ? 2 : 1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = is_maximizing ? player : opponent;
                int value = minimax(depth + 1, !is_maximizing, player);
                board[i][j] = 0;

                best_value = is_maximizing ? fmax(best_value, value) : fmin(best_value, value);
            }
        }
    }

    return best_value;
}

void ia_move_minimax(int currentPlayer)
{
    int best_value = -1000;
    int best_x = -1;
    int best_y = -1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = currentPlayer;
                int value = minimax(0, 0, currentPlayer);
                board[i][j] = 0;

                if (value > best_value)
                {
                    best_value = value;
                    best_x = i;
                    best_y = j;
                }
            }
        }
    }

    if (best_x != -1 && best_y != -1)
    {
        add_piece(best_x, best_y, currentPlayer);
    }
}

// Función para generar un movimiento aleatorio válido para el programa
void ia_move(int currentPlayer)
{
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios
    int x, y;
    int validMove = 0;
    int max_attempts = 100; // Intentos máximos para generar un movimiento válido

    while (!validMove)
    {
        x = rand() % 3; // Generar un número aleatorio entre 0 y 2 para la posición x
        y = rand() % 3; // Generar un número aleatorio entre 0 y 2 para la posición y

        // Verificar si el movimiento es válido y agregar la pieza
        if (add_piece(x, y, currentPlayer))
        {
            validMove = 1;
        }
        else
        {
            max_attempts--;
            if (max_attempts == 0)
            {
                // Si no se pudo generar un movimiento válido en 100 intentos, salir del bucle
                break;
            }
        }
    }
}

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


int WinMain (int argc, char* args[])
{
    if (!init())
    {
        return finish_with_error("Error al inicializar");
    }

    player1_texture = load_texture("./assets/rojo.png");
    player2_texture = load_texture("./assets/verde.png");

    if (!player1_texture || !player2_texture)
    {
        return finish_with_error("Error al cargar las texturas de las fichas");
    }

    int quit = 0;
    int restart = 0;
    SDL_Event e;
    int currentPlayer = 1;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (restart)
                {
                    restart = 0;
                    currentPlayer = 1;
                    clear_board();
                }
                else 
                {
                    handle_mouse_event(e, &currentPlayer, &restart);
                }
            }
        }

        draw_board();
        if (restart)
        {
            draw_line_winner(check_winner());
            fichas_propias = 0;
        }
        SDL_RenderPresent(renderer);
    }

    clean_up();
    return 0;
}
