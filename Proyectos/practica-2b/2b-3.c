#include <stdio.h>

#define TAM1 2
#define TAM2 3

void leerVector(int v[], int t);
void crearVector(int v1[], int t1, int v2[], int t2, int v3[]);
void mostrarVector(int v[], int t);

int main(void)
{
    int v1[TAM1], v2[TAM2], v3[TAM1 + TAM2];

    leerVector(v1, TAM1);
    leerVector(v2, TAM2);

    crearVector(v1, TAM1, v2, TAM2, v3);

    printf("El vector resultante es:\n");
    mostrarVector(v3, TAM1 + TAM2);
    return 0;
}


void leerVector(int v[], int t)
{
    /*Almacena en un vector los datos introducidos por teclado
    Parámetros: v[] Vector que queremos inicializar
    t Tamaño del vector
    Valor Retorno: Ninguno*/
    int i;

    printf("\n Introduzca los %i elementos del vector\n", t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &v[i]);
    }
    return;
}


void crearVector(int v1[], int t1, int v2[], int t2, int v3[])
{
    /*Almacena en un vector los datos almacenados en otros 2
   vectores
    Parámetros: v1[], t1 Vector y tamaño del primer vector
    v2[], t2 Vector y tamaño del segundo vector
   v3[] Vector resultado
    Valor Retorno: Ninguno*/
    int i;
    for (i = 0; i < (t1 + t2); i++)
    {
        if (i < t1)
            v3[i] = v1[i];
        else
            v3[i] = v2[i - t1];
    }
    return;
}


void mostrarVector(int v[], int t)
{
    /*Muestra por pantalla las componentes de un vector
    Parámetros: v[] Vector que queremos inicializar
    t Tamaño del vector
    Valor Retorno: Ninguno*/
    int i;
    for (i = 0; i < t; i++)
        printf("%i\t", v[i]);
    printf("\n");
    return;
}

/* 
    Escriba un programa que lea los valores de todos los elementos de dos vectores de enteros
    introducidos por el usuario, copie esos dos vectores en un tercero (uno a continuación del otro)
    y muestre sus valores por pantalla. Los tamaños de los dos vectores deben declararse como
    constantes. 
 */