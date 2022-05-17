#include <stdio.h>
int verificarEstimacion(double estimacionActual, double estimacionAnterior);

double valorAbsoluto(double numero)
{
    if (numero < 0)
    {
        return numero * -1;
    }
    return numero;
}

double raizCuadrada(int numero)
{
    double margen = 0.000001;
    double estimacion = 1.0;
    double estimacionAnterior = 0.0;
    double estimacionActual = 1.0;

    // while (valorAbsoluto((estimacion * estimacion) - numero) >= margen)
    while (!verificarEstimacion(estimacionActual, estimacionAnterior))
    {
        double cociente = numero / estimacionActual;
        double promedio = (cociente + estimacionActual) / 2.0;
        printf("Estimación: %lf. Cociente: %lf. Promedio: %lf\n", estimacionActual, cociente, promedio);
        estimacionAnterior = estimacionActual;
        estimacionActual = promedio;
    }
    return estimacionActual;
}

int verificarEstimacion(double estimacionActual, double estimacionAnterior)
{
    if (valorAbsoluto(estimacionActual - estimacionAnterior) < 0.01)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int numero;
    printf("Ingresa un número: ");
    scanf("%d", &numero);
    double raiz = raizCuadrada(numero);
    printf("La raíz cuadrada de %d es %lf", numero, raiz);
    return 0;
}
