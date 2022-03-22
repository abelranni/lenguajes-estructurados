
#include <stdio.h>

int main(void)
{
    int i1, i2, i3;
    float r1, r2, r3;

    i1 = 12;
    i2 = 5;
    r1 = 12.0;
    r2 = 5;

    r3 = r1 / r2;
    // División entre operandos reales, su resultado es el real 2.4, que se almacena en la variable real r3
    printf("Valor de r3 = r1 / r2: %f \n", r3);

    r3 = i1 / i2;
    // División entre operandos enteros, su resultado es un la parte entera de la división 2. 
    // Al asignar ese resultado a una variable real, se almacena como el número real 2.0
    printf("Valor de r3 = i1 / i2: %f \n", r3);

    i3 = i1 / r2;
    // División entre un operando real y otro entero. 
    // Para realizar la división se pasa el número entero a real y luego se divide, 
    // por lo que el resultado de la división es 2.4. 
    // Posteriormente ese resultado se asigna a la variable entera i3, para lo que se trunca: 2
    printf("Valor de i3 = i1 / r2: %d \n", i3);

    return 0;
}


/* 
    Dado el siguiente fragmento de código, identifique las declaraciones de variables, las
    instrucciones de asignación, los operadores y las expresiones. 
    ¿Cuál será el resultado de evaluar esas expresiones?

    Nota: El operador división se comporta de diferente forma según el tipo de datos de
    los operandos: 
    Si son números enteros el resultado será también un número entero. 
    Silos operandos son números reales, el resultado será también un número real. 
    Si uno de los dos es entero y otro real, el entero se convierte a real y la operación se hace entre
    reales.

 */