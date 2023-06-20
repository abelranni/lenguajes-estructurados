#include "score.h"

int player_one_wins = 0;
int player_two_wins = 0;

int increase_player_one_wins()
{
    player_one_wins++;
    return player_one_wins;
}

int get_player_one_wins()
{
    return player_one_wins;
}

int increase_player_two_wins()
{
    player_two_wins++;
    return player_two_wins;
}

int get_player_two_wins()
{

    return player_two_wins;
}

int increase_wins(int player)
{
    if (player == 1)
    {
        return increase_player_one_wins();
    }
    if (player == 2)
    {
        return increase_player_two_wins();
    }
    return 0;
}