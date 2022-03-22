#include <stdio.h>

int main(void)
{
    int a, b, c, suma; // Se declaran las variables a, b, c y suma.

    printf("Introduzca tres valores para calcular su suma\n");

    // Se asigna valor a las tres variables.
    scanf("%i %i %i", &a, &b, &c);
    
    // Se calcula el valor de su suma
    suma = a + b + c;

    /*Se muestra por pantalla el valor asignado a las variables a,
    b y c y el valor almacenado en la variable suma*/
    printf("\nLa suma de los numeros %i+%i+%i es:%i\n", a, b, c, suma);

    return (0);
}

/* 
    Escriba un programa en el que se declaren tres variables, a, b y c y se asigne a esas
    variables los valores 5, 7 y 9 respectivamente. 

    El programa deberá entonces calcular su suma y mostrar el resultado. 

    Modifíquelo para que los valores de las variables sean introducidos por el usuario.
 */