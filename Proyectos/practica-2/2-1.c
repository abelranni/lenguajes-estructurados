#include <stdio.h>

int potencia(int x, int n);

int main(void)
{
    int b;
    int e;

    /* Elevar a cualquier potencia */
    printf("Introduce base: ");
    scanf("%i", &b);
    printf("Introduce exponente: ");
    scanf("%i", &e);

    printf("%d elevado a %i es %ld \n", b, e, potencia(b, e));

    return 0;
}

int potencia(int x, int n)
{
    /* Funcion potencia:
    * Eleva el valor x al exponente n
    * Argumentos: x Base (int)
     n Exponente (int)
     Valor de retorno: x^n (long)
    */
    int ret = x;
    int i;
    for (i = 1; i < n; i++)
        // ret = ret * x;
        ret *= x;

    return ret;

}

/*
    Escriba una función que devuelva el resultado de elevar un número (declarado
    como entero) a cualquier potencia (valor entero). 
    El resultado de este cálculo debe ser de tipo long. 
*/