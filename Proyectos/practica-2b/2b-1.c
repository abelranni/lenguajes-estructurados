#include <stdio.h>

#define DIM 20

int main(void)
{
    int v[DIM], num, i, j;
    /*Se solicita el valor que toman las componentes del
    vector y se almacenan a partir de la última posición (DIM-1)*/
    i = 0;
    do
    {
        printf("\nDeme un numero entero\n");
        scanf("%i", &num);
        // Si el núm. leido no es cero se introduce en el vector
        if (num != 0)
        {
            i++;
            v[DIM - i] = num;
        }
    } while ((num != 0) && (i < DIM));
    // Se Muestran los elmentos del vector.
    if (i > 0)
    {
        printf("Los valores introducidos, mostrados en orden inverso, son:\n");
        for (j = DIM - i; j < DIM; j++)
            printf("%i\t", v[j]);
    }
    else
        printf("No ha introducido ningún valor");

    printf("\n");

    return 0;
}

/* 
    Escriba un programa que realice la lectura consecutiva, por teclado, de números
    enteros hasta que se introduzca el valor 0 (cero) o se hayan introducido 20
    números, y los almacene en un vector, en orden inverso al de su introducción
 */