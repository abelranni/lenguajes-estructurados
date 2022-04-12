#include <stdio.h>

int main()
{

    FILE *Archivo = fopen("hola.txt", "a");
    if (Archivo == NULL)
    {
        printf("Error al intentar crear/acceder al archivo\n");
    }
    else
    {
        char letra;
        //* Mientras que el usuario no presione Enter
        while ((letra = getchar()) != '\n')
        {
            fputc(letra, Archivo); //! Escribe lo que digite en el archivo
        }
    }
    fclose(Archivo);

    return 0;
}

/* 
    Escribir en un archivo local los caracteres ingresados por teclado
    hasta que se presione Enter
    Utilizar funcions getchar y fputc
 */