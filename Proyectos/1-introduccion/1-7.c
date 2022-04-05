#include <stdio.h>

int main(void)
{
    int num1, num2, resto; // Declaración de las variables.

    // Se solicita el valor de los dos números:
    printf("Deme el primer numero\n");
    scanf("%i", &num1);

    printf("Deme el segundo numero\n");
    scanf("%i", &num2);

    // Se calcula el resto y se muestra por pantalla
    resto = num1 % num2;

    printf("\nEl resto de dividir %i entre %i es :%i\n", num1, num2, resto);
    
    return (0);
}

/* 
    Escriba un programa que calcule el resto de la división de dos números enteros. 
    Para ello utilice el operador módulo (%).
 */