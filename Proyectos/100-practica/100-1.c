#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divideTwo(int dividendo, int divisor) {

    int resultado = 0;
    int signo = 1;
    if (dividendo < 0) {
        signo = -signo;
        dividendo = -dividendo;
    }
    if (divisor < 0) {
        signo = -signo;
        divisor = -divisor;
    }
    if (divisor == 0) {
        return INT_MAX;
    }
    while (dividendo >= divisor) {
        dividendo -= divisor;
        resultado++;
    }
    return resultado * signo;
}

int main(void)
{
    int dividend = 35;
    int divisor = 1;
    printf("Cociente de la division entre %d y %d : %d", dividend, divisor, divideTwo(dividend, divisor));
    return 0;
}