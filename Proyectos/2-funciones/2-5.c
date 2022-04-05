#include <stdio.h>

double calcularRaiz(int n, int decimales);
long calcularFactorial(int n);
int comprobarPrimo(int n);

int main(void)
{
    int n;
    int decimales;
    double raiz;
    long factorial;
    int primo;

    // Solicitamos un número hasta que éste sea positivo
    do
    {
        printf("Introduzca el número del que quiere calcular la raiz\n");
        scanf("%d", &n);

        if (n < 0)
            printf("ERROR: No se puede calcular la raiz de un número negativo\n");

    } while (n < 0);
    // Solicitamos el número de decimales que tendrá la aproximación.Este número debe ser positivo :
    do
    {
        printf("Introduza el número de decimales que tendrá la aproximación\n");
        scanf("%d", &decimales);
    } while (decimales < 0);
    
    raiz = calcularRaiz(n, decimales);
    factorial = calcularFactorial(n);
    primo = comprobarPrimo(n);

    // Mostramos resultados
    printf("La raiz cuadrada de %d es %lf\n", n, raiz);
    printf("Su Factorial es %ld\n", factorial);

    if (primo == 1)
        printf("Ademas, el numero es primo\n");
    else
        printf("Ademas, el numero NO es primo\n");

    return (0);
}

double calcularRaiz(int n, int decimales)
{
    /*PARAMETROS
    int n; //Numero del que queremos calcular la raíz
    int decimales; //Numero de decimales a los que vamos a
    aproximar*/

    // Variables locales
    double raiz; /*Numero con el que probaremos si es la raiz. Valor de Retorno*/
    float incremento;
    int dec; // Numero de decimales a los que vamos a aproximar
    // y número de decimales con los que estamos
    // realizando el cálculo

    // Inicializamos raiz al menor entero posible, es decir, a 0:
    raiz = 0;
    incremento = 1.0;
    /*Inicialmente buscamos el entero más próximo a la raiz;
    Es decir, probaremos con números que difieren entre sí en
    1 unidad. Por tanto, el número de decimales para la
    Primera aproximación es 0 */
    dec = 0;
    while ((n > (raiz * raiz)) && (decimales >= dec))
    {
        while (raiz * raiz < n)
        {
            raiz = raiz + incremento;
        }
        // Al salir del bucle, el valor almacenado en raiz será mayor
        //  o igual que el número buscado.
        // Si es mayor (nos hemos pasado), actualizamos el valor de
        // raiz
        if (raiz * raiz != n)
        {
            raiz = raiz - incremento;
            // Ajustamos a un nuevo decimal
            incremento = incremento / 10.0;
            dec++;
        }
    } // while

    return (raiz);
}
long calcularFactorial(int n)
{
    long factorial;
    factorial = 1;
    int i;

    // Dado que el factorial tanto de 0 como de 1 es 1, el caso
    // genérico se da para n>=2. En este caso:
    // n!=1*2*3*....*n
    for (i = 2; i <= n; i++)
        factorial = factorial * i;

    return (factorial);
}

int comprobarPrimo(int n)
{
    int primo;
    int i;

    int divisor;

    if (n == 1)
        primo = 0;
    else
        primo = 1; // Se admite que el número es primo
    divisor = 2;
    // Se intenta localizar algún divisor del número dado
    while ((primo == 1) && (divisor < n))
    {
        if (n % divisor == 0)
            primo = 0;
        else
            divisor = divisor + 1; // Si el número sigue siendo
        // primo probamos con
        // otro divisor
    }
    return (primo);
}

/* 
    Escribir un programa que solicite al usuario un número natural y el número de decimales 
    que se quiere contemplar al calcular su raíz. Una vez introducidos estos datos, 
    se debe mostrar por pantalla el resultado de: 
    a)	Realizar la raíz cuadrada usando el método de las aproximaciones sucesivas. 
    b)	Calcular el factorial de ese número. 
    c)	Indicar si el número introducido es primo o no. 
        Un número primo es aquel que sólo es divisible por sí mismo y por el número 1. 
        Por convenio, el número 1 no se considera primo 
 */