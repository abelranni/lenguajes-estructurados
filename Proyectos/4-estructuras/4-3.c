#include <stdio.h>

#define MAX_CLIENTES 100

/*
Definicion de la estructura datos_personales.
Esta estructura almacena los datos personales de cada cliente:
*/

struct datosPersonales
{
    char nombre[10];
    char apellido1[10];
    char apellido2[10];
    int telefono;
    char e_mail[20];
};

struct datosPersonales leerDatosCliente(void);
int comprobarTelefono(struct datosPersonales clientes[], int tam, int telf);
void mostrarClientes(struct datosPersonales clientes[], int tam);

int main()
{
    // Se define la variable clientes. Esta variable debe almacenar los datos de 100 clientes.
    // Se declara como un vector de 100 elementos en el que cada
    // elemento es del tipo datosPersonales
    struct datosPersonales clientes[MAX_CLIENTES];
    struct datosPersonales nuevoCliente;

    int repetido;
    int nClientes = 0;
    int salir; // variable para controlar cuando no se quieren grabar más clientes
    printf("Introduzca los datos de los clientes\n");
    printf("Use 0 para terminar\n");
    printf("maximo 100 clientes\n");

    /*Se solicitan los datos del primer cliente y se introduce  en el vector*/
    clientes[0] = leerDatosCliente();
    nClientes++;

    printf("Introduzca 0 para terminar, cualquier otro valor para seguir leyendo datos\t");
    scanf("%i", &salir);
    while ((nClientes < MAX_CLIENTES) && (salir != 0))
    {
        // leer los datos del cliente i
        nuevoCliente = leerDatosCliente();
        repetido = comprobarTelefono(clientes, nClientes, nuevoCliente.telefono);
        if (!repetido)
        {
            clientes[nClientes] = nuevoCliente;
            nClientes++;
        }
        printf("Introduzca 0 para terminar, cualquier otro valor para seguir leyendo datos\t");
        scanf("%i", &salir);
    } // while ((nClientes<MAX_CLIENTES)&&(salir!=0));

    mostrarClientes(clientes, nClientes);
    return 0;
}

struct datosPersonales leerDatosCliente(void)
{
    /*Lee los datos relativos a un cliente:
    Parámetros: Niguno
    Retorno: Estructura con los datos leidos*/

    struct datosPersonales cliente;
    printf("Introduzca el nombre y los dos apellidos del cliente\n");
    scanf("%s", cliente.nombre);
    scanf("%s", cliente.apellido1);
    scanf("%s", cliente.apellido2);
    printf("Introduzca el telefono y e-mail del cliente\n");
    scanf("%i", &cliente.telefono);
    scanf("%s", cliente.e_mail);
    return cliente;
}

int comprobarTelefono(struct datosPersonales clientes[], int tam,
                      int telf)
{
    /*Comprueba si un telf coincide con alguno de los telefonos
    de los clientes cuyos datos están almacenados en el vector
    Parámetros: clientes -> Vector con los clientes actuales
    tam -> Núm de elmentos del vector
    telf-> Telefono a comprobar
    Retorno: int 0 si no hay coincidencia; 1 en c.c.*/

    int j = 0;
    int repetido = 0;
    while ((j < tam) && (repetido == 0))
    {
        if (clientes[j].telefono == telf)
        {
            repetido = 1;
            printf("Imposible grabar los datos\n");
            printf("El telefono %d ya esta asignado al cliente\n",
                   clientes[j].telefono);
            printf("%s %s\n", clientes[j].nombre,
                   clientes[j].apellido1);
            printf("almacenado en la posición %d\n", j);
        }
        j++;
    }
    return repetido;
}

void mostrarClientes(struct datosPersonales clientes[], int tam)
{
    /*Muestra por pantalla los datos de los clientes almacenados
    Parámetros: clientes-> Vector con los clientes actuales
    tam-> Núm de elementos del vector
    Retorno: nada*/
    int j;
    printf("La empresa tiene %i clientes\n", tam);
    for (j = 0; j < tam; j++)
    {
        printf("Cliente %i : %s %s %s \n", j, clientes[j].nombre,
               clientes[j].apellido1, clientes[j].apellido2);
        printf("\t telefono: %i\n", clientes[j].telefono);
        printf("\t e_mail: %s\n", clientes[j].e_mail);
    };
    return;
}


/* 
    Escriba un programa en C que permita almacenar mediante el uso de estructuras 
    los datos de 100 clientes de una empresa de automóviles. 
    El programa permitirá ir almacenando los datos de los clientes, asignándole a 
    cada uno un número según el orden en el que se van grabando. Los datos que se 
    guardarán de cada cliente son el nombre, los apellidos, el teléfono y e-mail. 
    Tras leer un cliente se dará la opción de terminar tecleando un 0. 
    Posteriormente modifique el programa para que evite que un cliente sea 
    guardado dos veces. Para ello se comparará el teléfono con los ya guardados 
    y en caso de que estuviera repetido se mostrará el nombre del cliente, 
    el teléfono repetido y la posición en la que está grabado. 

 */