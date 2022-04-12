#include <stdio.h>
#include <string.h>

#define N_AUTORES 20 // Consideramos un máximo de 20 autores
#define NC 10        // Consideramos un máximo de 10 canciones por autor

// Estructura para almacenar los datos de autor: Nombre, fecha de nacimiento y origen
struct datosAutor
{
    char nombre[20];
    int fechaNacimiento;
    char origen[20];
};

// Estructura para almacenar la información de una canción: Nombre, CD y año de edición)
struct datosCancion
{
    char titulo[20];
    char CD[20];
    int edicion;
};

// Estructura para almacenar los datos de una colección de discos:
//  Datos del autor, datos de las canciones y numero de canciones de ese autor.
// Se considera que un autor puede tener como mucho NC canciones
struct Discos
{
    struct datosAutor autor;
    struct datosCancion song[NC];
    int cancionesAutor;
};

int mostrarMenu(void);
void introducirDatos(struct Discos Discografia[N_AUTORES], int n);
void mostrarCancionesAnio(struct Discos Discografia[N_AUTORES], int n);

int main()
{
    // Se define la variable Discografia. Esta variable debe almacenar
    // los datos relativos a todas nuestras canciones.
    struct Discos Discografia[N_AUTORES];
    int n = 0; // Numero de autores que hay en mi discografía (Inferior a N_AUTORES)
    int i;
    int continuar;
    int op;

    // Inicialización de variables. Inicialmente no se tienen datos almacenados.
    for (i = 0; i < N_AUTORES; i++)
        Discografia[i].cancionesAutor = 0;

    // Se muestra el menu por pantalla
    do
    {
        op = mostrarMenu();
        switch (op)
        {
        case 1:
        {
            do
            {
                if (n < N_AUTORES)
                {
                    introducirDatos(Discografia, n);
                    n++;
                    printf("Desea introducir canciones de otros autores?(Si=1/No=0)");
                    scanf("%i", &continuar);
                }
                else
                    printf("Su discografia está completa\n");
            } while ((continuar == 1) && (n < N_AUTORES));
            break;
        }
        case 2:
        {
            mostrarCancionesAnio(Discografia, n);
            break;
        }
        case 0:
            break;
        default:
            printf("La opcion introducida no es correcta\n");
        } // switch

    } while (op != 0);

    return (0);
}

int mostrarMenu(void)
{
    int op;
    printf("Seleccione una de las siguientes opciones\n");
    printf("1: Introducir datos\n");
    printf("2: Mostrar canciones\n");
    printf("0: Salir\n");
    scanf("%d", &op);
    return op;
}

void introducirDatos(struct Discos Discografia[N_AUTORES], int n)
{
    int continuar = 1;

    printf("Datos del Autor\n");
    printf("Nombre\t\t");
    scanf(" %[^\n]", &Discografia[n].autor.nombre);

    printf("Anio_Nac.\t");
    scanf("%i", &Discografia[n].autor.fechaNacimiento);

    printf("Origen\t\t");
    scanf(" %[^\n]", &Discografia[n].autor.origen);

    do
    {
        printf("Datos de la Cancion\n");
        printf("Titulo\t");
        scanf("%[^\n]", &Discografia[n].song[Discografia[n].cancionesAutor].titulo);
        printf("CD\t");
        scanf("%[^\n]", &Discografia[n].song[Discografia[n].cancionesAutor].CD);
        printf("Edicion\t");

        scanf("%i", &Discografia[n].song[Discografia[n].cancionesAutor].edicion);
        Discografia[n].cancionesAutor++; // Se actualiza elcontador de canciones/autor

        printf("Desea introducir más canciones del mismoautor?(Si=1/No=0)");
        scanf("%i", &continuar);
    } while ((continuar == 1) && (Discografia[n].cancionesAutor < NC));

    return;
}

void mostrarCancionesAnio(struct Discos Discografia[N_AUTORES], int n)
{
    int i, j;
    int year;
    printf("Introduzca el year\n");
    scanf("%i", &year);
    printf("En el año %i se editaron las siguientescanciones:\n", year);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < Discografia[i].cancionesAutor; j++)
        {
            if (Discografia[i].song[j].edicion == year)
            {
                printf("Cancion: %s\t Autor: %s \n",
                       Discografia[i].song[j].titulo, Discografia[i].autor.nombre);
            }
        }
    }

    return;
}

