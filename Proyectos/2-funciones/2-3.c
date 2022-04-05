#include <stdio.h>

float calcularMax(float x, float y);
float calcularNota(float p1, float p2, float e);

int main(void)
{
    char c;
    do
    {
        float parcial1, parcial2, examen, final;

        /* Leer valores */
        printf("Introduzca nota parcial 1 [0, 10]: ");
        scanf("%f", &parcial1);
        printf("Introduzca nota parcial 2 [0, 10]: ");
        scanf("%f", &parcial2);
        printf("Introduzca nota examen final [0, 10]: ");
        scanf("%f", &examen);

        /* Calcular nota final*/
        final = calcularNota(parcial1, parcial2, examen);

        /* Imprimir resultados */
        printf("Nota final: %f", final);

        /* Continuar? */
        printf("\n\nSalir? (s/n): ");

        /* Para evitar conflictos con el salto de linea (\n) y
        evitar un bucle infinito se recurre al siguiente "truco" */
        do
        {
            scanf("%c", &c);
        } while (c == '\n');

        printf("\n");

    } while (c != 's');

    return 0;
}


float calcularNota(float p1, float p2, float notaExamen)
{
    /* Función calcularNota: Calcula la nota final a partir de:
     - primer parcial 20% (p1)
     - segundo parcial 20% (p2)
     - examen final 60% (notaExamen)
     Si la nota final con la evaluación continua es menor a la del
     examen, la nota final es la del examen
    */
    float notaEC, final;
    notaEC = p1 * 0.2 + p2 * 0.2 + notaExamen * 0.6;
    final = calcularMax(notaEC, notaExamen);

    return final;
}


float calcularMax(float x, float y)
{
    /* Funcion calcularMax: Devuelve el mayor de los valores x, y
    pasados como parámetro */
    float max;
    if (x >= y)
        max = x;
    else
        max = y;

    return max;
}

/* 

    La nota del examen de una asignatura corresponde en un 20% al primer parcial,
    un 20% al segundo parcial y un 60% el examen final. La nota final es la mejor
    entre la nota del examen y la nota obtenida con la evaluación continua (teniendo
    en cuenta los dos parciales).

    Escriba un programa que pida estas tres notas y calcule la nota final de un
    alumno. A continuación, el programa debe preguntar al usuario si quiere
    calcular una nueva nota o finalizar (pulsando la tecla ‘s’). 
    
    Utilice una función para calcular la nota y otra para obtener el máximo 
    (que puede ser la desarrollada en el ejercicio 2).

 */
