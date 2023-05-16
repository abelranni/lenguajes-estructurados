#include <stdio.h>
#include <math.h>
#include "logic.h"
#include "minimax.h"
#include "global.h"

void ia_place_chip_minimax(int current_player)
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
                board[i][j] = current_player;
                int value = minimax(0, 0, current_player);
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
        add_chip(best_x, best_y, current_player);
    }
}

int minimax(int depth, int is_maximizing, int player)
{
    int winner = check_winner();
    if (winner != 0)
    {
        return winner == player ? 1 : -1;
    }

    if (is_board_full())
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

//------------------------------------------------------------

// void generate_moves(int player, int moves[9][2])
// {
//     // TODO: Implementar esta función. Debe llenar el array 'moves' con todos los
//     // movimientos posibles para el jugador 'player'. Cada movimiento es un par de
//     // posiciones: la posición de la ficha que se va a mover y la posición a la que
//     // se va a mover. Solo se deben considerar movimientos a celdas adyacentes.
// }

// void ia_move_minimax(int current_player)
// {
//     int best_value = -1000;
//     int best_move[2] = {-1, -1};

//     int moves[9][2];
//     generate_moves(current_player, moves);

//     for (int i = 0; i < 9; ++i)
//     {
//         if (moves[i][0] != -1 && moves[i][1] != -1)
//         {
//             int old_value = board[moves[i][1]];
//             board[moves[i][1]] = board[moves[i][0]];
//             board[moves[i][0]] = 0;

//             int value = minimax(0, 0, current_player);

//             board[moves[i][0]] = board[moves[i][1]];
//             board[moves[i][1]] = old_value;

//             if (value > best_value)
//             {
//                 best_value = value;
//                 best_move[0] = moves[i][0];
//                 best_move[1] = moves[i][1];
//             }
//         }
//     }

//     if (best_move[0] != -1 && best_move[1] != -1)
//     {
//         board[best_move[1]] = board[best_move[0]];
//         board[best_move[0]] = 0;
//     }
// }

// int minimax(int depth, int is_maximizing, int player)
// {
//     int winner = check_winner();
//     if (winner != 0)
//     {
//         return winner == player ? 1 : -1;
//     }

//     if (is_board_full())
//     {
//         return 0;
//     }

//     int best_value = is_maximizing ? -1000 : 1000;
//     int opponent = player == 1 ? 2 : 1;

//     int moves[9][2];
//     generate_moves(is_maximizing ? player : opponent, moves);

//     for (int i = 0; i < 9; ++i)
//     {
//         if (moves[i][0] != -1 && moves[i][1] != -1)
//         {
//             int old_value = board[moves[i][1]];
//             board[moves[i][1]] = board[moves[i][0]];
//             board[moves[i][0]] = 0;

//             int value = minimax(depth + 1, !is_maximizing, player);

//             board[moves[i][0]] = board[moves[i][1]];
//             board[moves[i][1]] = old_value;

//             best_value = is_maximizing ? fmax(best_value, value) : fmin(best_value, value);
//         }
//     }

//     return best_value;
// }
