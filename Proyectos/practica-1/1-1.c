#include <stdio.h>

int main(void)
{
    int fecha; // Variable que almacena el año de nacimiento.
    int edad;  // Variable que almacena la edad

    printf("Hola\n");
    printf("Por favor, introduzca el anio en que nacio\n");

    scanf("%d", &fecha); // Se lee el año de nacimiento
    edad = 2013 - fecha; // Se calcula la edad

    printf("Si usted nacio en %d, este anio cumple %d anios \n",
           fecha, edad);

    return (0);

}

/* 
    Escriba un programa que muestre en la pantalla un mensaje de saludo, por ejemplo
    "Hola",y luego muestre el mensaje "Por favor introduzca el año en que nació". 

    El programa debe leer ese valor y almacenarlo en una variable de tipo entero llamada
    fecha. 

    Por último haga que el programa escriba la frase:
    " Si usted nació en <valor de la fecha leída> este año cumple <edad calculada> años.

    Es recomendable que vaya escribiendo el programa por pasos (mostrar saludo, pedir
    fecha, leer fecha,…) y compilándolo después de cada paso para comprobar que
    funciona.

 */
