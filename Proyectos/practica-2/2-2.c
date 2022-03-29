#include <stdio.h>

float max(float x, float y);

int main(void)
{
    float a, b;
    printf("Introduzca a: ");
    scanf("%f", &a);
    printf("Introduzca b: ");
    scanf("%f", &b);
    printf("Mayor: %f\n", max(a, b));

    return 0;
}

float max(float x, float y)
{
    /* Función max: Devuelve el mayor de los valores x, y
    pasados como parámetro */
    float max;
    if (x >= y)
        max = x;
    else
        max = y;

    return max;
}

/* 
    Escriba una función que reciba dos números reales positivos como parámetros y
    devuelva el máximo de los dos valores.
 */
