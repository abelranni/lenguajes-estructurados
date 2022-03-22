#include <stdio.h>
int main(void)
{
    int edad, adulto;

    printf("\nQue edad tiene?\n");
    scanf("%i", &edad);

    /* Almacenamos en adulto el resultado de evaluar edad>=21. Si
    la relación es cierta, adulto tomará valor 1. En caso contrario
    tomará valor 0. */

    adulto = (edad >= 21);

    /* Se muestra por pantalla el valor almacenado en adulto*/
    printf("%d \n", adulto);

    return (0);
}

/* 
    Escriba un programa que pregunte al usuario su edad, y luego compruebe si es mayor
    de 21 años. 
    Si es mayor deberá escribir un 1 y si es menor un 0. 
    El ejercicio se debe resolver usando operadores relacionales.

    Recuerde que el resultado de evaluar una expresión verdadera en C (por ejemplo 7>5)
    es 1, y el de evaluar una falsa (7<5) es 0.
 */
