#include <stdio.h>

#define NUM_MONEDAS 8

// Prototipos de las funciones

void escribirCambio(int aCam[NUM_MONEDAS], char aNom[NUM_MONEDAS][20]);

int calcularCambioLimite(float cam_t, 
                         int aCam[NUM_MONEDAS], 
                         int aVal[NUM_MONEDAS], 
                         int aMonDisponibles[NUM_MONEDAS]);

int main(void)
{
    /* NOTA: Este programa es exactamente igual que el anterior,
     solo cambia la función CalcularCambio, que se sustituye por
     CalcularCambio_Limite. Estas dos funciones se diferencian en
     que la segunda tiene un argumento más, el número de
     monedas disponibles de cada tipo, que se tiene en cuenta
     para calcular la vuelta */

    float precio, pagado, cambio;

    /* vector en el que se guardará cuantas monedas de cada valor hay que devolver*/
    int aCambio[NUM_MONEDAS];

    // Valor de cada moneda en céntimos.
    int aValores[NUM_MONEDAS] = {200, 100, 50, 20, 10, 5, 2, 1};

    // Nombre de cada moneda
    char aNombres[NUM_MONEDAS][20] = {"2 euros",
                                      "1 euro",
                                      "50 centimos",
                                      "20 centimos",
                                      "10 centimos",
                                      "5 centimos",
                                      "2 centimos",
                                      "1 centimo"};

    // Monedas disponibles de cada tipo
    int aMonDisponibles[NUM_MONEDAS] = {10, 2, 2, 2, 2, 2, 2, 2};

    int posible; // Controla si es o no posible devolver el cambio

    // Monedas disponibles para dar cambio
    // Puede leerse por pantalla o escribirse en el código

    // Leemos precio y dinero pagado
    // hasta que lo pagado sea mayor que el precio
    printf("escriba el precio del producto\n");
    scanf("%f", &precio);

    printf("escriba el dinero pagado\n");
    scanf("%f", &pagado);

    // si lo pagado es menor que el precio, volvemos a leer
    while (pagado < precio)
    {
        printf("dinero insuficiente, escriba una cantidad mayor o igual que el precio\n");
        scanf("%f", &pagado);
    }

    // calculamos y mostramos el cambio en euros
    cambio = pagado - precio;
    printf("se van a devolver %f euros \n", cambio);

    // Llamamos a la función que calcula el cambio
    posible = calcularCambioLimite(cambio, aCambio, aValores, aMonDisponibles);

    // Llamamos a la función que muestra los resultados
    if (posible == 0)
    {
        escribirCambio(aCambio, aNombres);
    }
    else
    {
        printf("No hay suficiente dinero para la vuelta\n");
    }

    return 0;
}


int calcularCambioLimite(float cambio, int aCam[NUM_MONEDAS], int aVal[NUM_MONEDAS], int aDisp[NUM_MONEDAS])
{
    /* función que calcula el cambio de cambio euros en monedas
     devuelve los resultados en el array de monedas mon
     necesita conocer los valores en centimos de las monedas,
     que se pasan como parametro en el vector de valores val
     tiene en cuenta cuantas monedas de cada tipo hay,
     que se pasa como parametro en el vector aDisp
     si no hay suficientes monedas para devolver todo,
     devuelve un -1. Si todo es correcto devuelve 0*/

    // variables locales
    int i, camCent, temp;

    /* vamos dividiendo entre los valores de las monedas, de
     mayor a menor el dividendo de la división entera será el
     numero de monedas el resto de la división entera será el
     cambio que queda por devolver como tengo que trabajar con
     división entera, paso a céntimos */
    camCent = cambio * 100;

    printf("la cantidad a devolver en centimos es %d\n", camCent);

    for (i = 0; i < NUM_MONEDAS; i++)
    {
        temp = camCent / aVal[i]; // division entera
        // debería devolver temp unidades de esa moneda
        // pero tengo que ver si hay suficientes
        if (aDisp[i] >= temp)
        {
            // si hay suficientes, devuelvo las necesarias y calculo
            //  el nuevo disponible
            aCam[i] = temp;
            aDisp[i] = aDisp[i] - temp;
        }
        else
        {
            // si no hay suficiente disponible, devuelvo todas las
            // que haya de ese valor
            aCam[i] = aDisp[i];
            aDisp[i] = 0;
        }
        // en los dos casos, la nueva cantidad a devolver es lo
        // que había menos lo que devuelvo de esa moneda
        camCent = camCent - (aCam[i] * aVal[i]);
    }

    // puede suceder que no haya suficientes monedas
    if (camCent != 0)
        camCent = -1;

    return (camCent);
}


void escribirCambio(int aCam[NUM_MONEDAS], char aNom[NUM_MONEDAS][20])
{
    // función que recibe como parámetro el cambio a devolver aCam
    // y los nombres de cada moneda
    // y muestra el resultado por pantalla

    int i;
    // escribimos el resultado
    printf("el cambio a devolver esta compuesto por:\n");
    for (i = 0; i < NUM_MONEDAS; i++)
    {
        if (aCam[i] != 0)
        {
            printf("%d monedas de %s\n", aCam[i], aNom[i]);
        }
    }

    return;
}


/*
    Modifique el ejercicio anterior para que la vuelta se calcule suponiendo que hay disponibles para
    devolver sólo un número limitado de monedas de cada tipo (el número de monedas disponible
    puede leerse por teclado o escribirse en el código)
 */