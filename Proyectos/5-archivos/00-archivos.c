#include <stdio.h>

int main()
{

    // Creamos el apuntador y lo igualamos a lo que devuelva fopen
    // el archivo no existe y se creará automaticamente

    FILE *archivo = fopen("c:\\proyectos\\hola.txt", "a");

    // Verificacion (NULL es el macro para la memoria nula)
    if (archivo == NULL)
    {
        printf("Error al intentar crear/acceder al archivo\n");
    }
    else
    {
        //* Definimos un texto y lo escribimos en el archivo
        char Texto[] = "Hola Mundo";
        fprintf(archivo, "Texto Escrito: %s", Texto);
        printf("archivo creado con exito\n");
    }

    // SIEMPRE cerramos el archivo
    fclose(archivo);

    return 0;
}