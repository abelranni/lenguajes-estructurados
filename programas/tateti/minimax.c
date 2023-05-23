#include <stdio.h>
#include <math.h>
#include "debug.h"
#include "logic.h"
#include "state.h"
#include "minimax.h"
#include "global.h"

#define MINIMAX_DEPTH 4

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
                int value = minimax_place(0, 0, current_player);
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

int minimax_place(int depth, int is_maximizing, int player)
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
                int value = minimax_place(depth + 1, !is_maximizing, player);
                board[i][j] = 0;
                best_value = is_maximizing ? fmax(best_value, value) : fmin(best_value, value);
            }
        }
    }
    return best_value;
}

//------------------------------------------------------------

void ia_move_chip_minimax(int current_player)
{
    int best_value = -1000;
    int best_destination_x = -1;
    int best_destination_y = -1;
    int best_origin_x = -1;
    int best_origin_y = -1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == current_player)
            {

                for (int im = 0; im < 3; ++im)
                {
                    for (int jm = 0; jm < 3; ++jm)
                    {

                        Cell origin_cell = {i, j};
                        Cell destination_cell = {im, jm};

                        if (check_player_chip_movement(destination_cell, origin_cell))
                        {
                            DEBUG2("Check movimiento de (%d, %d) a (%d, %d)\n", i, j, im, jm);
                            board[i][j] = 0;
                            board[im][jm] = current_player;
                            debug_show_board_and_delay();

                            int value = minimax_move(0, 0, current_player);
                            board[i][j] = current_player;
                            board[im][jm] = 0;
                            debug_show_board_and_delay();

                            DEBUG2("Value: %d\n", value);

                            if (value > best_value)
                            {
                                best_value = value;
                                best_destination_x = im;
                                best_destination_y = jm;
                                best_origin_x = i;
                                best_origin_y = j;
                            }
                        }
                    }
                }
            }
        }
    }

    if (best_destination_x != -1 && best_destination_y != -1)
    {
        DEBUG2("best_value: %d\n", best_value);

        Cell origin_cell = {best_origin_x, best_origin_y};
        Cell destination_cell = {best_destination_x, best_destination_y};

        ia_move_chip(origin_cell, destination_cell, current_player);

    }
}

void ia_move_chip( Cell origin_cell, Cell destination_cell, int current_player)
{
    if (check_player_chip_movement(destination_cell, origin_cell))
    {
        board[origin_cell.x][origin_cell.y] = 0;
        board[destination_cell.x][destination_cell.y] = current_player;
    }
}

int minimax_move(int depth, int is_maximizing, int player)
{
    int winner = check_winner();
    if (winner != 0)
    {
        return winner == player ? 1 : -1;
    }

    if (depth > MINIMAX_DEPTH )
    {
        return 0;
    }

    int best_value = is_maximizing ? -1000 : 1000;
    int opponent = player == 1 ? 2 : 1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == (is_maximizing ? player : opponent))
            {            
                for (int im = 0; im < 3; ++im)
                {
                    for (int jm = 0; jm < 3; ++jm)
                    {

                        Cell origin_cell = {i, j};
                        Cell destination_cell = {im, jm};

                        if (check_player_chip_movement(destination_cell, origin_cell))
                        {
                            board[i][j] = 0;
                            board[im][jm] = is_maximizing ? player : opponent;
                            int value = minimax_move(depth + 1, !is_maximizing, player);
                            
                            debug_show_board_and_delay();

                            board[i][j] = is_maximizing ? player : opponent;
                            board[im][jm] = 0;
                            best_value = is_maximizing ? fmax(best_value, value) : fmin(best_value, value);

                            debug_show_board_and_delay();


                        }
                    }

                }
            }
        }
    }
    return best_value;
}

