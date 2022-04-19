#include <stdio.h>
#include <conio.h>

int main()
{
    int Numero1 = 0, Numero2 = 0; // Variables

    printf("Introduzca el primer numero: ");
    scanf(" %i", &Numero1); 

    printf("Introduzca el segundo numero: ");
    scanf(" %i", &Numero2);

    if (Numero1 > Numero2)
    {
        if (Numero1 % Numero2 == 0)
        {
            printf("Es divisor % i de % i", Numero1, Numero2);
        }
        else
            printf("% i no es divisor de % i ", Numero2, Numero1);
    }
    else
        printf("No es divisor porque es mayor % i", Numero2);
        
    return 0;
}


/* 

C maneja buffers, tanto de entrada como de salida. 
Lo que hace la función scanf es ir al buffer de entrada stdin y tratar de retirar el formato 
que le indicaste (en este caso, un char). 

En el primer caso, como el buffer está vacío, el programa se va a quedar esperando que ingreses 
algo por teclado, en tu caso ingresaste una a y presionaste la tecla enter la cual fue interpretada 
como un \n. En este momento el buffer de entrada tendrá lo siguiente a\n. 
La función scanf retirará el caracter a y retornará al programa.

El segundo scanf hará lo mismo que el primero, pero esta vez va a encontrar algo en el buffer 
de entrada, el \n. C interpreta el \n como un caracter y lo imprime en pantalla 
(no se ve porque la consola lo interpreta como un salto de línea).

Solución: Para hacer scanf con caracteres individuales, añadir un espacio en blanco antes del %c 
para saltear cualquier espacio en blanco y los saltos de línea.

scanf(" %c", &variable);

Para los formatos %d y %s esto se hace automáticamente y no es necesario el espacio en blanco.

 */