#include <stdio.h>

int main(void)
{
    float capInicial, capitalFinal, interes, porcentaje;

    // Se solicita el capital inicial
    printf("Cual es el capital inicial del que parte?\n");
    scanf("%f", &capInicial);

    // Se solicita el interés anual y se calcula su tanto por ciento
    printf("Cual es el interes anual aplicado?\n");
    scanf("%f", &porcentaje);
    interes = porcentaje / 100;

    /*Se calcula el capital final y el resultado se muestra por pantalla:*/
    capitalFinal = capInicial + (interes * capInicial);
    printf("El capital final despues de un año sera:%f\n", capitalFinal);

    /* ahora lo modificamos para que se muestre correctamente la ñ*/
    printf("El capital final despues de un a%co sera:%f\n", 164, capitalFinal);

    return (0);
}

/* 
    Escriba un programa que calcule el interés que se obtiene por un determinado dinero
    depositado en un banco. 
    Para ello el programa preguntará por el capital inicial y por el
    tipo de interés.
 */