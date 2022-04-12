#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *fsOne, *fsTwo, *fTarget;
    char fName1[20], fName2[20], fName3[30], ch;

    printf("Ingrese el nombre del primer archivo: ");
    gets(fName1);
    printf("Ingrese el nombre del segundo archivo: ");
    gets(fName2);
    printf("\nIngrese el nombre del archivo destino: ");
    gets(fName3);

    fsOne = fopen(fName1, "r");
    fsTwo = fopen(fName2, "r");
    if (fsOne == NULL || fsTwo == NULL)
    {
        printf("\nError al intentar abrir archivo!");
    }
    else
    {
        fTarget = fopen(fName3, "w");
        if (fTarget == NULL)
        {
            printf("\nError al intentar escribir en archivo destino!");
        }
        else
        {
            ch = fgetc(fsOne);
            while (ch != EOF)
            {
                fputc(ch, fTarget);
                ch = fgetc(fsOne);
            }
            ch = fgetc(fsTwo);
            while (ch != EOF)
            {
                fputc(ch, fTarget);
                ch = fgetc(fsTwo);
            }
            printf("\n%s y %s se unieron en %s correctamente!", fName1, fName2, fName3);
        }
    }
    fclose(fsOne);
    fclose(fsTwo);
    fclose(fTarget);
    getch();
    return 0;
}

/*
    Escribir un programa que una en un archivo el contenido de otros dos dados.
 */