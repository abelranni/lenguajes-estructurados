#include <stdio.h>

#define NUM_MONEDAS 8

// Prototipos de las funciones
void calcularCambio(float cam_t, int aCam[NUM_MONEDAS], int aVal[NUM_MONEDAS]);
void escribirCambio(int aCam[NUM_MONEDAS], char aNom[NUM_MONEDAS][20]);

int main(void)
{
    float precio, pagado, cambio;

    /* vector en el que se guardarácuántas monedas de cada valor hay que devolver*/
    int aCambio[NUM_MONEDAS]; 

    // Valor de cada moneda
    int aValores[NUM_MONEDAS] = {200, 100, 50, 20, 10, 5, 2, 1};

    // Nombre de cada moneda
    char aNombres[NUM_MONEDAS][20] = {  "2 euros", 
                                        "1 euro", 
                                        "50 centimos", 
                                        "20 centimos", 
                                        "10 centimos", 
                                        "5 centimos", 
                                        "2 centimos", 
                                        "1 centimo"};

    // Leemos precio y dinero pagado
    // hasta que lo pagado sea mayor que el precio
    printf("Escriba el precio del producto\n");
    scanf("%f", &precio);
    printf("Escriba el dinero pagado\n");
    scanf("%f", &pagado);

    // si lo pagado es menor que el precio, volvemos a leer
    while (pagado < precio)
    {
        printf("Dinero insuficiente, escriba una cantidad mayor o igual que el precio\n");
        scanf("%f", &pagado);
    }

    // calculamos y mostramos el cambio en euros
    cambio = pagado - precio;
    printf("Se van a devolver %.2f euros \n", cambio);

    // Llamamos a la función que calcula el cambio
    calcularCambio(cambio, aCambio, aValores);

    // Llamamos a la función que muestra los resultados
    escribirCambio(aCambio, aNombres);

    return 0;
}

void escribirCambio(int aCam[NUM_MONEDAS], char aNom[NUM_MONEDAS][20])
{
    // funcion que recibe como parametro el cambio a devolver aCam
    // y los nombres de cada moneda
    // y muestra el resultado por pantalla

    int i;

    // escribimos el resultado
    printf("El cambio a devolver esta compuesto por:\n");
    for (i = 0; i < NUM_MONEDAS; i++)
    {
        if (aCam[i] != 0)
        {
            printf("%d monedas de %s\n", aCam[i], aNom[i]);
        }
    }

    return;
}


void calcularCambio(float cam_t, int aCam[NUM_MONEDAS], int aVal[NUM_MONEDAS])
{
    // función que calcula el cambio de cam_t euros en monedas
    // devuelve los resultados en el array de monedas mon
    // necesita conocer los valores en céntimos de las monedas, que se
    // pasan como parámetro en el array de valores val
    // variables locales
    int i, cam_cent;

    /* vamos dividiendo entre los valores de las monedas, de
     mayor a menor el dividendo de la división entera será el
     numero de monedas el resto de la división entera será el
     cambio que queda por devolver.
     como hay que trabajar con división entera, se pasa a
     céntimos*/
    cam_cent = cam_t * 100;

    for (i = 0; i < NUM_MONEDAS; i++)
    {
        aCam[i] = cam_cent / aVal[i];  // division entera
        cam_cent = cam_cent % aVal[i]; // resto
    }

    return;
}


/*
    Escribir un programa que permita gestionar una máquina expendedora. El programa deberá pedir
    al usuario el precio del producto que va a comprar y el dinero que ha pagado y calcular la vuelta
    correspondiente. El programa debe mostrar cuántas monedas de cada tipo deben ser devueltas.
    Los tipos de monedas a considerar deben ser 1, 2, 5, 10, 20 y 50 céntimos, y 1 y 2 euros, y se
    asume que hay suficientes monedas de todos los tipos para devolver el cambio. Utilizar funciones
    para facilitar la legibilidad del programa principal
 */