#include <stdio.h>

int main(void)
{
    // Se declaran las variables. Todas de tipo float.
    float base, altura, area;

    // Se solicita el valor de la altura y la base.
    printf("Deme la altura del triangulo\n");
    scanf("%f", &altura);
    
    printf("\nDeme la base del triangulo\n");
    scanf("%f", &base);

    // Se calcula el área del triángulo:
    area = (base * altura) / 2;

    // Se muestra por pantalla el mensaje indicado:
    printf("\n Un triangulo rectangulo de altura %f y base %f, tiene un area de: %f\n", 
            altura, base, area);

    return (0);
}

/* 
    Escriba un programa que calcule el área de un triángulo rectángulo, pidiendo al
    usuario la altura y la base. 

    La salida por pantalla debe ser:
    "Un triangulo rectángulo de altura ____ y base ____, tiene un área de ____" 
    (sustituyendo los espacios en blanco por los valores)

    NOTA area = (base * altura)/2
 */