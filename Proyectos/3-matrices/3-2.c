
#include <stdio.h>

#define FIL 3
#define COL 2

void leerMatriz(int m[FIL][COL]);
void mostrarMatriz(int m[FIL][COL]);
void sumarColumnas(int m[FIL][COL], int suma[COL]);
void calcularMaximo(int v[], int tam, int *max, int *c);

int main(void)
{
    int mat[FIL][COL];
    int suma[COL]; // Vector que almacena la suma de cada columna
    int max, col_max;
    int i, j;

    leerMatriz(mat);
    mostrarMatriz(mat);

    sumarColumnas(mat, suma);
    calcularMaximo(suma, COL, &max, &col_max);

    printf("\nLa suma de columnas mayor tiene el valor %i y corresponde a la columna %i\n", max, col_max);

    return 0;
}

void leerMatriz(int m[FIL][COL])
{
    /*Almacena en una matriz los datos introducidos por teclado*/
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("\n mat[%i][%i]=", i, j);
            scanf("%i", &m[i][j]);
        }
    }
    return;
}

void mostrarMatriz(int m[FIL][COL])
{
    /*Muestra por pantallas los elementos de una matriz*/
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%i\t", m[i][j]);
        }
        printf("\n");
    }
    return;
}

void sumarColumnas(int m[FIL][COL], int suma[COL])
{
    /*Almacena en el vector suma el resultado de sumar los
    elemementos de cada columna:
    Parámetros: int m[FIL][COL] Matriz cuyas columnas queremos
    sumar
   suma[COL] Vector en el que se almacena la suma
    Valor Retorno: Ninguno*/
    int i, j;
    for (j = 0; j < COL; j++)
    {
        suma[j] = 0; // Inicializacion
        for (i = 0; i < FIL; i++)
        {
            suma[j] = suma[j] + m[i][j];
        }
    }

    return;
}

void calcularMaximo(int v[], int tam, int *max, int *c)
{
    /*
    Calcula el máximo de los elementos de un vector y la posición que ocupa
    Parámetros: int v[] Vector de entrada
    int tam Dimensiones del vector
    int *max Máx. de las componentes del vector
    int *c Componente con el valor máximo
    Valor de Retorno: Ninguno
    */
    int i;

    *max = v[0]; // Se asume que la 1ª componente tiene el max valor
    *c = 0;
    for (i = 1; i < tam; i++)
    {
        if (v[i] > *max)
        {
            *max = v[i];
            *c = i;
        }
    }
    
    return;
}

/*
    Escriba un programa en C que pida al usuario los valores de una tabla de elementos enteros de
    dimensión 4 filas por 3 columnas, y muestre en pantalla la mayor de las sumas de sus columnas.
 */