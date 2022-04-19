#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, k, Sum_Cuadrados, op, ady, hip;
    printf("Ternas Pitagoricas\n");
    for (i = 1; i <= 500; i++)
    {
        hip = i * i; // eleva la hipotenusa al cuadrado
        for (j = 1; j <= 500; j++)
        {
            op = j * j; // eleva el cateo opuesto al cuadrado
            for (k = 1; k <= 500; k++)
            {
                ady = k * k;
                Sum_Cuadrados = op + ady;
                if (Sum_Cuadrados == hip) // determina si existe
                // una terna pitagórica
                {
                    printf("\n cateto opuesto= %d,", j);
                    printf(" cateto adyacente= %d,", k);
                    printf(" cateto hipotenusa= %d", i);
                    printf("\n Comprobacion: %d + %d = %d \n", op, ady, hip);
                }
            }
        }
    }
    return 0;
}