#include <stdio.h>

#define TAM 3

// Al tratarse de una matriz cuadrada, los valors de FIL Y COL son iguales 

void leerMatriz(int m[TAM][TAM]);
void mostrarMatriz(int m[TAM][TAM]);
void cambiarDiagonal(int m[TAM][TAM]);

int main(void)
{
    int mat[TAM][TAM];
    int i, j;

    leerMatriz(mat);
    mostrarMatriz(mat);
    cambiarDiagonal(mat);
    mostrarMatriz(mat);
    
    return 0;
}

void leerMatriz(int m[TAM][TAM])
{
    /*Almacena en una matriz los datos introducidos por teclado*/
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("\n mat[%i][%i]=", i, j);
            scanf("%i", &m[i][j]);
        }
    }
    return;
}


void mostrarMatriz(int m[TAM][TAM])
{
    /*Muestra por pantallas los elementos de una matriz*/
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("%i\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}


void cambiarDiagonal(int m[TAM][TAM])
{
    /*Pone a 0 los elementos de la diagonal Principal*/
    int i;
    for (i = 0; i < TAM; i++)
        m[i][i] = 0;
    return;
}

/* 
    Escriba un programa que declare un array llamado tabla, cuadrado y de dos
    dimensiones, rellene todos sus elementos con el valor 1 y muestre dicho array.
    Luego el programa deberá poner a 0 todos los elementos de la diagonal principal y
    volver a mostrar el resultado.
 */