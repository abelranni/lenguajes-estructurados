#include <stdio.h>

int main(void)
{

    int i=11;
    int var_uno=100, var_dos=200; 
    int suma;
    suma = var_dos + var_dos;

    i=i+1;
    printf("valor de i: %d \n", i);
    // a) Es una expresión correcta, incrementa en uno el valor de la variable i


    printf("%d\n", 4+20);
    // b) También es correcta: Muestra por pantalla el valor 24

    printf("suma=var_uno + var_dos = %i + %i \n", var_uno, var_dos, suma);
    /* 
    c) Es una expresión correcta, sin embargo al faltar el especificador de formato
    correspondiente (%i) no se muestra el valor de la variable suma.
    */

    return (0);

}

/* 
    Indique cuáles de estas instrucciones son correctas y cuáles incorrectas, 
    e indique cuál es el resultado de su ejecución.
    i=i+1;
    printf("%d", 4+20);
    printf("suma=var_uno + var_dos = %i + %i", var_uno, var_dos, suma);
 */
