#include <stdio.h>
#include <string.h>

/*-------------- Definir estructuras ------------- */
struct fichaLibro
{
    char titulo[20]; // Titulo del libro
    char autor[20];  // Autor del libro
    char ISBN[18];   // Debe almacenar 17 caracteres + el caracter nulo
    int prestado;    // 0: No prestado; 1: prestado
};

int main(void)
{
    // Declaracion e inicialización de las variables
    struct fichaLibro libro1 = {"titulo1", "autor1", "000-0-00-000000-0", 0};
    struct fichaLibro libro2 = {"titulo2", "autor2", "000-0-00-000000-2", 1};

    // Para probar el caso en el que las dos variables son ejemplares del mismo libro
    // struct fichaLibro libro2 = {"titulo1", "autor1", "000-0-00-000000-0", 0};

    // Inicialmente son distintos
    int iguales = 0; // 1: Iguales; 0: Distintas.

    /*Para ver si las variables son idénticas es necesario
    comparar todos los campos. En este caso se omite la
    comparación respecto al campo prestado*/

    if (strcmp(libro1.titulo, libro2.titulo) == 0)
        if (strcmp(libro1.autor, libro2.autor) == 0)
            if (strcmp(libro1.ISBN, libro2.ISBN) == 0)
                iguales = 1;

    if (iguales == 1)
        printf("Las dos variables representan al mismo libro\n");
    else
        printf("Los libros son distintos\n");

    return 0;
}

/*
    1.	Para la gestión de los libros de una pequeña biblioteca es preciso conocer su título,
        su autor, el ISBN (cadena de 17 caracteres: 978-3-16-148410-0) y si está prestado o no.
        Escribir un programa en C que:
    a)	Defina una estructura denominada fichaLibro que permita almacenar los datos
        de cualquier libro
    b)	Declarare e inicialice dos variables del tipo fichaLibro
    c)	Compruebe si las variables declaradas representan ejemplares de un mismo
        libro o de libros distintos.
 */