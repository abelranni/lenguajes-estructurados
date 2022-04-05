#include <stdio.h>
int main(void)
{
    // Declaración de las variables
    int tiempoInicial, tiempoFinalMin, tiempoFinalSeg;
    
    // Se solicita un tiempo en segundos
    printf("Deme el tiempo en segundos\n");
    scanf("%i", &tiempoInicial);

    // Se obtienen los minutos (/60) y los segundos (%60)
    tiempoFinalMin = tiempoInicial / 60;
    tiempoFinalSeg = tiempoInicial % 60;

    printf("\nEl tiempo corresponde a %i minutos y a %i segundos\n", tiempoFinalMin, tiempoFinalSeg);

    return (0);
}

/* 
    Escriba un programa que pida un tiempo en segundos y lo muestre convertido a
    minutos y segundos.
 */
