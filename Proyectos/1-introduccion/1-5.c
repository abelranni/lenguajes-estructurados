#include <stdio.h>

// Definimos PI como una constante usando la directiva define:
#define PI 3.1416

int main(void)
{
    float radio, perimetro; // Definimos las variables de tipo float

    // Se solicita y se lee el valor del radio.
    printf("introduzca el radio: ");
    scanf("%f", &radio);

    // Se calcula el perímetro de la circunferencia:
    perimetro = 2 * PI * radio;

    // Se muestra el resultado por pantalla:
    printf("El perimetro de una circunferencia de radio %.2f es %.2f\n", radio, perimetro);

    return (0);
}

/* 
    Escriba un programa que calcule el perímetro de una circunferencia.
    NOTA perimetro = 2 * PI * r. 
    Se recomienda definir PI como una constante usando la directiva define.
 */