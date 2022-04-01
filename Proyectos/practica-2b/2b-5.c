#include <stdio.h>

#define FIL 2
#define COL 3

void leerMatriz(float m[FIL][COL]);
void imprimirMatriz(float m[FIL][COL]);
float maxMatriz(float m[FIL][COL]);
float minMatriz(float m[FIL][COL]);
void sumarMatrices(float m1[FIL][COL], float m2[FIL][COL], float r[FIL][COL]);
void restarMatrices(float m1[FIL][COL], float m2[FIL][COL], float r[FIL][COL]);
void multiplicarMatrizEscalar(float m[FIL][COL], float x, float r[FIL][COL]);
void multiplicarMatrices(float m1[FIL][COL], float m2[COL][FIL],
                         float r[FIL][FIL]);
void traspuesta(float m[FIL][COL], float r[COL][FIL]);


int main(void)
{
    float a[FIL][COL];
    float b[FIL][COL];
    float c[FIL][COL];
    float p[FIL][FIL];
    float t[COL][FIL];
    int i, j;
    
    /* Probar funciones */
    printf("\nLeer matriz a:\n");
    leerMatriz(a);

    printf("\nLeer matriz b:\n");
    leerMatriz(b);

    printf("\nMatriz a:\n");
    imprimirMatriz(a);

    printf("\nMatriz b:\n");
    imprimirMatriz(b);

    printf("\nMax a: %f\n", maxMatriz(a));
    printf("\nMin a: %f\n", minMatriz(a));

    sumarMatrices(a, b, c);
    printf("\nSuma a+b\n");
    imprimirMatriz(c);

    restarMatrices(a, b, c);
    printf("\nResta a-b\n");
    imprimirMatriz(c);

    multiplicarMatrizEscalar(a, 2.0, c);
    printf("\nMultiplicar a*2.0\n");
    imprimirMatriz(c);

    traspuesta(a, t);
    printf("\nTraspuesta\n");
    for (i = 0; i < COL; i++)
    {
        for (j = 0; j < FIL; j++)
            printf("%2.2f ", t[i][j]);
        printf("\n");
    }

    multiplicarMatrices(a, t, p);
    printf("\nMultiplicar a x b\n");
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < FIL; j++)
            printf("%2.2f ", p[i][j]);
        printf("\n");
    }

    return 0;

}


void leerMatriz(float m[FIL][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
        for (j = 0; j < COL; j++)
        {
            printf("Introduzca valor (%d, %d): ", i, j);
            scanf("%f", &m[i][j]);
        }
}

void imprimirMatriz(float m[FIL][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%2.2f ", m[i][j]);
        }
        printf("\n");
    }
}

float maxMatriz(float m[FIL][COL])
{
    int i, j;
    float max = m[0][0];
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (m[i][j] > max)
                max = m[i][j];
        }
    }
    return max;
}

float minMatriz(float m[FIL][COL])
{
    int i, j;
    float min = m[0][0];
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (m[i][j] < min)
                min = m[i][j];
        }
    }
    return min;
}

void sumarMatrices(float m1[FIL][COL], float m2[FIL][COL], float r[FIL][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            r[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void restarMatrices(float m1[FIL][COL], float m2[FIL][COL], float r[FIL][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            r[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void multiplicarMatrizEscalar(float m[FIL][COL], float x, float r[FIL][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            r[i][j] = m[i][j] * x;
        }
    }
}

void multiplicarMatrices(float m1[FIL][COL], float m2[COL][FIL],
                         float r[FIL][FIL])
{
    int i, j, k;
    for (i = 0; i < FIL; i++)
        for (j = 0; j < FIL; j++)
        {
            r[i][j] = 0;
            for (k = 0; k < COL; k++)
                r[i][j] += m1[i][k] * m2[k][j];
        }
}

void traspuesta(float m[FIL][COL], float r[COL][FIL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            r[j][i] = m[i][j];
        }
    }
}

/* 

    Escriba las funciones necesarias para implementar las siguientes operaciones con matrices
    (representadas como arrays de dos dimensiones).
    (NOTA: El tamaño de las matrices (número de filas y de columnas) será definido como una
    constante con la directiva #define).

    a) Leer valores de matriz
        Parámetros: Matriz float m [FILAS][COLUMNAS]
        Devuelve: Nada
        Acción: Lee valores para la matriz

    b) Imprimir matrices
        Parámetros: Matriz float m[FILAS][COLUMNAS]
        Devuelve: Nada
        Acción: Imprime m en pantalla

    c) Obtener el valor máximo de los elementos de la matriz
        Parámetros: Matriz float m[FILAS][COLUMNAS]
        Devuelve: double max
        Acción: Obtiene el valor máximo de la matriz

    d) Obtener el valor mínimo de los elementos de la matriz
        Parámetros: Matriz float m[FILAS][COLUMNAS]
        Devuelve: double min
        Acción: Obtiene el valor mínimo de la matriz

    e) Sumar matrices 
       Entrada:
        Matrices
            double m1[FILAS][COLUMNAS],
            double m2[FILAS][COLUMNAS],
            double r[FILAS][COLUMNAS]
        Salida: Nada
        Acción: Calcula r = m1 + m2 

    f) Restar matrices
       Entrada:
        Matrices
            double m1[FILAS][COLUMNAS],
            double m2[FILAS][COLUMNAS],
            double r[FILAS][COLUMNAS]
        Salida: Nada
        Acción: Calcula r = m1 - m2

    g) Multiplicar matriz por valor escalar
       Entrada:
        Matrices
            double m[FILAS][COLUMNAS],
            double r[FILAS][COLUMNAS]
        Escalar
            double x,
        Salida: Nada
        Acción: Calcula r = x x m

    h) Multiplicar matrices Entrada:
        Matrices
            double m1[FILAS][COLUMNAS],
            double m2[COLUMNAS][FILAS],
            double r[FILAS][FILAS]
        Salida: Nada
        Acción: Calcula r = m1 * m2

    i) Obtener la traspuesta de una matriz Entrada:
        Matrices
            double m[FILAS][COLUMNAS],
            double r[COLUMNAS][FILAS]
        Salida: Nada
        Acción: Calcula r = traspuesta(m) 

 */