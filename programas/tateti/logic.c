#include <stdio.h>
#include <stdbool.h>
#include "logic.h"
#include "global.h"


/*
Función para agregar una ficha en la posición (x, y) del tablero.
Retorna:
- 1 si se pudo agregar la ficha
- 0 en caso contrario
*/
int add_chip(int x, int y, int player)
{
    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        return 0;
    }

    if (board[x][y] != 0)
    {
        return 0;
    }

    board[x][y] = player;
    printf( "Tablero:\n");
    print_board();

    return 1;
}

void print_board()
{
    printf("-------------\n");
    for (int i = 0; i < 3; ++i)
    {
        printf("| ");
        for (int j = 0; j < 3; ++j)
        {
            printf("%d | ", board[j][i]);
        }
        printf("\n-------------\n");
    }
}



/*
Función para reiniciar el tablero
*/
void clear_board()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = 0;
        }
    }
}

/*
Función para verificar si el tablero está lleno
*/
bool is_board_full()
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
        return true;
    }
    return false;
}

/*
Función para verificar si hay un ganador
*/
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

/*
Función para verificar si el juego ha terminado
*/
int check_game_over()
{
    printf("Verificando si el juego ha terminado...\n");
    int winner = check_winner();
    if (winner != 0)
    {
        printf("El jugador %d ha ganado!\n", winner);
        return 1;
    }

    if (is_board_full())
    {
        printf("Empate!\n");
        return 1;
    }

    return 0;
}

