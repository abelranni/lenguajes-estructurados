#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMA_LONGITUD_PALABRA_SIN_NULL 15
#define MAXIMA_LONGITUD_PALABRA MAXIMA_LONGITUD_PALABRA_SIN_NULL + 1
#define MAXIMA_LONGITUD_CARACTER 2 //
#define MAXIMA_LONGITUD_EQUIVALENTE_MORSE 20
#define ESPACIO_PERSONALIZADO "#"

char *nombreArchivoOriginal = "original.txt";
char *nombreArchivoCodificado = "codificado.txt";
char *nombreArchivoDecodificado = "decodificado.txt";
char *nombreArchivoDiccionario = "morse.txt";

// Nodo que tiene el carácter y el código morse
struct nodo
{
    char caracter[MAXIMA_LONGITUD_CARACTER];
    char morse[MAXIMA_LONGITUD_EQUIVALENTE_MORSE];
    struct nodo *siguiente;
};
// La parte superior de la pila; es decir, por donde comenzamos
struct nodo *superior = NULL;

// Agrega una nueva traducción
void agregar(char *caracter, char *morse)
{
    // El que se agregará; reservamos memoria
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));

    // Le ponemos el dato
    strcpy(nuevoNodo->morse, morse);
    strcpy(nuevoNodo->caracter, caracter);
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void cargarDiccionarioEnMemoria()
{
    FILE *archivoTraducciones;
    int tamanioBuffer = 255;
    char linea[tamanioBuffer];

    char delimitador[] = " ";

    archivoTraducciones = fopen(nombreArchivoDiccionario, "r");
    if (archivoTraducciones == NULL)
    {
        printf("Imposible leer el archivo %s", nombreArchivoDiccionario);
        exit(EXIT_FAILURE);
    }
    while (fgets(linea, tamanioBuffer, archivoTraducciones))
    {
        size_t longitudLinea = strlen(linea);
        // Checar si la línea no es un salto de línea vacío
        if (longitudLinea > 1)
        {
            // De la línea, removemos el asterisco * y el salto de línea
            strtok(linea, "\n*");
            // Al hacer un split con el espacio, lo primero es el carácter
            char *simbolo = strtok(linea, delimitador);
            // Y lo segundo es el equivalente
            char *equivalente = strtok(NULL, delimitador);
            agregar(simbolo, equivalente);
        }
    }
    fclose(archivoTraducciones);
}

void buscarMorseDeCaracter(char *cadena, char destino[MAXIMA_LONGITUD_EQUIVALENTE_MORSE])
{
    // Salida rápida. Si es espacio, devolvemos vacío
    if (strcmp(cadena, " ") == 0)
    {
        strcpy(destino, "");
        return;
    }
    struct nodo *temporal = superior;
    while (temporal != NULL)
    {
        if (strcmp(cadena, temporal->caracter) == 0)
        {
            strcpy(destino, temporal->morse);
            return;
        }
        temporal = temporal->siguiente;
    }
}

void buscarCaracterDeMorse(char *morse, char destino[MAXIMA_LONGITUD_EQUIVALENTE_MORSE])
{
    struct nodo *temporal = superior;
    if (strcmp(morse, ESPACIO_PERSONALIZADO) == 0)
    {
        strcpy(destino, " ");
        return;
    }
    while (temporal != NULL)
    {
        if (strcmp(morse, temporal->morse) == 0)
        {
            strcpy(destino, temporal->caracter);
            return;
        }
        temporal = temporal->siguiente;
    }
}

void codificarPalabra(const char palabra[MAXIMA_LONGITUD_PALABRA])
{
    int i = 0;
    char equivalencia[MAXIMA_LONGITUD_EQUIVALENTE_MORSE];
    char cadenaTemporal[2] = "\0";
    while (palabra[i] != 0)
    {
        cadenaTemporal[0] = palabra[i];
        char separador[20] = "";
        if (strcmp(cadenaTemporal, " ") == 0)
        {
            strcpy(separador, "  ");
        }
        else
        {
            strcpy(separador, "   ");
        }
        buscarMorseDeCaracter(cadenaTemporal, equivalencia);
        printf("%s%s", equivalencia, separador);
        i++;
    }
}

void codificarArchivo()
{
    FILE *archivoOriginal, *archivoCodificado;
    int tamanioBuffer = 255;
    char linea[tamanioBuffer];
    archivoOriginal = fopen(nombreArchivoOriginal, "r");
    if (archivoOriginal == NULL)
    {
        printf("El archivo %s no existe", nombreArchivoOriginal);
        return;
    }

    archivoCodificado = fopen(nombreArchivoCodificado, "w");
    if (archivoCodificado == NULL)
    {
        printf("Imposible abrir el archivo %s", nombreArchivoCodificado);
        return;
    }

    while (fgets(linea, tamanioBuffer, archivoOriginal))
    {
        // De la línea, removemos el salto de línea
        strtok(linea, "\n");
        // La recorremos
        int i = 0;
        char equivalencia[MAXIMA_LONGITUD_EQUIVALENTE_MORSE];
        char cadenaTemporal[2] = "\0";
        while (linea[i] != 0)
        {
            cadenaTemporal[0] = linea[i];
            char separador[20] = "";
            if (strcmp(cadenaTemporal, " ") == 0)
            {
                strcpy(separador, "  ");
            }
            else
            {
                strcpy(separador, "   ");
            }
            buscarMorseDeCaracter(cadenaTemporal, equivalencia);
            // Tenemos la equivalencia, la escribimos
            fprintf(archivoCodificado, "%s%s", equivalencia, separador);
            i++;
        }
        fprintf(archivoCodificado, "\n");
    }
    fclose(archivoOriginal);
    fclose(archivoCodificado);
    printf("Archivo codificado\n");
}

void decodificarArchivo()
{
    FILE *archivoCodificado, *archivoDecodificado;
    int tamanioBuffer = 900;
    char linea[tamanioBuffer];
    archivoCodificado = fopen(nombreArchivoCodificado, "r");
    if (archivoCodificado == NULL)
    {
        printf("Imposible abrir el archivo %s", nombreArchivoCodificado);
        return;
    }
    archivoDecodificado = fopen(nombreArchivoDecodificado, "w");
    if (archivoDecodificado == NULL)
    {
        printf("Imposible abrir el archivo %s", nombreArchivoCodificado);
        return;
    }

    while (fgets(linea, tamanioBuffer, archivoCodificado))
    {

        // Remover salto de línea
        strtok(linea, "\n");
        int indice = 0;
        int cantidadDeEspacios = 0;
        char palabra[5000] = "";
        while (linea[indice] != 0)
        {
            char actual = linea[indice];
            if (actual == '-' || actual == '.')
            {
                // Cadena para convertir char a string
                char temporal[2] = "\0";
                temporal[0] = actual;
                if (cantidadDeEspacios == 0)
                {
                    strcat(palabra, temporal);
                }
                else if (cantidadDeEspacios == 3)
                {
                    strcat(palabra, " ");
                    strcat(palabra, temporal);
                    cantidadDeEspacios = 0;
                }
                else if (cantidadDeEspacios == 5)
                {
                    strcat(palabra, " ");
                    strcat(palabra, ESPACIO_PERSONALIZADO);
                    strcat(palabra, " ");
                    strcat(palabra, temporal);
                    cantidadDeEspacios = 0;
                }
            }
            else
            {
                cantidadDeEspacios++;
            }

            indice++;
        }
        // Llegados a este punto ya tenemos una línea codificada, pero sin espacios que estorban
        char *token = strtok(palabra, " ");
        if (token != NULL)
        {
            while (token != NULL)
            {
                char equivalencia[MAXIMA_LONGITUD_EQUIVALENTE_MORSE];
                buscarCaracterDeMorse(token, equivalencia);
                fprintf(archivoDecodificado, "%s", equivalencia);
                token = strtok(NULL, " ");
            }
        }
        fprintf(archivoDecodificado, "\n");
    }
    printf("\n");
    fclose(archivoCodificado);
    fclose(archivoDecodificado);
    printf("Archivo descodificado\n");
}

int main(void)
{
    cargarDiccionarioEnMemoria();
    int opcion = -1;
    char palabra[5000] = "";
    while (1)
    {
        printf("\n1 - Codificar palabra\n");
        printf("2 - Codificar archivo\n");
        printf("3 - Descodificar archivo\n");
        printf("0 - Salir\n");
        printf("Elige:\n");
        char escanearInt[20];
        fgets(escanearInt, 20, stdin);
        opcion = strtol(escanearInt, NULL, 0);
        if (opcion == 0)
        {
            break;
        }
        else if (opcion == 1)
        {
            printf("\nEscribe la palabra. Max 15 caracteres:\n");
            fgets(palabra, 5000, stdin);
            strtok(palabra, "\n"); // Remover salto de línea
            if (strlen(palabra) > MAXIMA_LONGITUD_PALABRA_SIN_NULL)
            {
                printf("Longitud fuera de rango.\n");
                continue;
            }
            printf("Resultado:\n");
            codificarPalabra(palabra);
        }
        else if (opcion == 2)
        {
            codificarArchivo();
        }
        else if (opcion == 3)
        {
            decodificarArchivo();
        }
    }
    return EXIT_SUCCESS;
}