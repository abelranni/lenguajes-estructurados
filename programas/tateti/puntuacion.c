
#include "puntuacion.h"
#include <stdio.h>

int playerscore = 100;

void resetplayerscore()
{
    playerscore=100;
}

int showplayerscore()
{
    return playerscore;
}

void playerscores()
{
    playerscore -=1;
}