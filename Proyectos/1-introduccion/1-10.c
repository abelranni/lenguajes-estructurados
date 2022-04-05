#include <stdio.h>

int main(void)
{
    int a, b, aux;
    printf("Deme un numero entero: (a) \n");
    scanf("%i", &a);

    printf("Deme otro numero entero: (b) \n");
    scanf("%i", &b);

    printf("\na vale:%i\nb vale:%i\n", a, b);

    // Almacenamos en aux el valor de a. Por tanto, a queda "libre".
    aux = a;

    // Almacenamos en a el valor de b. Por tanto, b queda "libre".
    a = b;

    /* Almacenamos en b el valor de aux. Esta variable almacenaba el valor de a */
    b = aux;

    printf("\nDespues del intercambio\na vale:%i\nb vale:%i\n", a, b);

    return (0);
}

/* 
    Escriba un programa en el que se declaren dos variables, a y b, se pida un valor para
    cada una de ellas, y se intercambien dichos valores.
 */
