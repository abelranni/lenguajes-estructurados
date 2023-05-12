#include <stdio.h>
#include <math.h>
#include "logic.h"
#include "minimax.h"
#include "global.h"


void ia_move_minimax(int current_player)
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
