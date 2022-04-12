#include <stdio.h>

int main()
{
    FILE *fd;

    char direccion[] = "hola.txt";

    fd = fopen(direccion, "r"); // "r" = read -> leer

    if (fd == NULL)
    {
        printf("El archivo no existe\n");
    }
    else
    {
        printf("Se encontro el Archivo\n");
        
        // Imprime la ubicacion donde esta el archivo
        printf("Su ubicacion es: %s\n", direccion);
    }

    return 0;
}

/*
    Utilizar Funcion fopen(), para determinar si existe un archivo de texto (.txt) o no
    fopen(nombre archivo, modo);
        nombre archivo = cadena ... Contiene el identificador externo del archivo
        modo = cadena           ... Contiene el modo en que va a ser tratado el archivo
*/