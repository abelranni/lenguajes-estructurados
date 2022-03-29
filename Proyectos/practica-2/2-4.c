#include <stdio.h>

int anioBisiesto(int year);
int validarFecha(int d, int m, int a);
int calcularDias(int d, int m, int a);
void leerFecha(int *d, int *m, int *a);

int main(void)
{
    int dia, mes, anio;
    int totalDias;
    int resto;
    printf("Por favor, introduzca una fecha posterior al 1 de Enero de 1978\n");
    leerFecha(&dia, &mes, &anio);
    totalDias = calcularDias(dia, mes, anio);
    resto = totalDias % 7;
    printf("El dia %d/%d/%d será ", dia, mes, anio);
    switch (resto)
    {
    case 0:
        printf("domingo\n");
        break;
    case 1:
        printf("lunes\n");
        break;
    case 2:
        printf("martes\n");
        break;
    case 3:
        printf("miercoles\n");
        break;
    case 4:
        printf("jueves\n");
        break;
    case 5:
        printf("viernes\n");
        break;
    case 6:
        printf("sabado\n");
    }

    // system("PAUSE");
    return (0);
}
int anioBisiesto(int year)
{
    /* Dado un año determina si éste es bisiesto o no
    Para ello hay que saber que los años bisiestos son aquellos
    que son divisibles por 4 pero no por 100 o
    divisibles por 4 y por 400 */
    int bisiesto = 0;
    if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)))
    {
        bisiesto = 1; // Si el año no es divisible por 4 no es bisiesto
    }
    return bisiesto;
}
int validarFecha(int d, int m, int a)
{
    /* Comprueba que los datos introducidos corresponden a una
    fecha válida:
    año > 1978
    1>=mes<=12
    1>=dia<=dias mes
    Para el último cálculo es necesario conocer los días que
    tiene el mes introducido (31, 30, 29 ó 28)*/
    int diasMes;
    int bisiesto;
    int correcta;

    correcta = 1;
    /*Se comprueba la validez del año*/
    if (a < 1978)
    {
        printf("La fecha introducida debe ser posterior al 1 de Enero de 1978\n");
        correcta = 0;
    }
    /*Si el año es válido se comprueba la validez del mes*/
    else if ((m < 1) || (m > 12))
    {
        printf("El mes introducido no es válido\n");
        correcta = 0;
    }
    /*Si el mes es válido se determina el núm. de días del mes*/
    else
    {
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            diasMes = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMes = 30;
            break;
        case 2:
            /*Para determinar si febrero tiene 28 o 29 días se
            analiza si el año es bisiesto*/
            bisiesto = anioBisiesto(a);
            if (bisiesto == 1)
                diasMes = 29;
            else
                diasMes = 28;
        } // switch

        if ((d < 0) || (d > diasMes))
        {
            correcta = 0;
            printf("El día introducido no es valido\n");
        } // if ((d<0) || (d>diasMes)
    }     // else
    return (correcta);
}

void leerFecha(int *d, int *m, int *a)
{
    /*Lee una fecha y devuelve los valores leidos
        *d: dia
        *m: mes
        *a: año
        al programa principal
        Para conseguir este objetivo los parámetros se pasan por
        referencia*/

    int valida;
    do
    {
        printf("Dia: ");
        scanf("%d", d);
        /*Puesto que en este caso d, m y a son punteros se omite
        El operador dirección (&) en la llamada a scanf*/
        printf("Mes: ");
        scanf("%d", m);
        printf("Year: ");
        scanf("%d", a);
        valida = validarFecha(*d, *m, *a);
    } while (valida == 0);
}
int calcularDias(int d, int m, int a)
{
    /*Determina el número de dias transcurridos entre la fecha
    introduciday el 1 de enero de 1978*/
    int i;
    int bisiesto;
    int dias = 0;

    /*Por cada año transcurrido hasta llegar al de la fecha
    introducida se suman 365 ó 366 días según corresponda*/
    for (i = 1978; i < a; i++)
    {
        bisiesto = anioBisiesto(i);
        if (bisiesto == 1)
            dias = dias + 366;
        else
            dias = dias + 365;
    }
    /*Por cada mes transcurrido hasta llegar al de la fecha
    introducido se suman 31, 30, 29 ó 28 días según corresponda*/
    for (i = 1; i < m; i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias = dias + 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dias = dias + 30;
            break;
        case 2:
        {
            bisiesto = anioBisiesto(a);
            if (bisiesto == 1)
                dias = dias + 29;
            else
                dias = dias + 28;
        }
        } // switch;*/
    };    // for
    /*Se añaden los días no contabilizados*/
    dias = dias + d - 1; // El día en curso no se contabiliza
    return (dias);
}


/* 

    Realizar un programa que pida al usuario información de un día/mes/año
    posterior al 1978 y a continuación le muestre al usuario el día de la semana con
    que se corresponde esa fecha. Para realizar este cálculo la única información
    disponible es que el 1 de Enero de 1978 fue domingo.
    Para realizar el ejercicio conviene tener en cuenta que el día de la semana se puede
    obtener a partir del número de días transcurridos entre la fecha introducida por el
    usuario y la fecha de referencia (1 de enero de 1978). Una vez conocido este valor,
    el día de la semana vendrá dado por:
    dia_semana=n_dias_transcurridos % 7
    En la resolución de este ejercicio se deben usar las siguientes funciones:

    a) void leerFecha(int *dia, int *mes, int *year);
    Objetivo: Solicita los datos relatives a una fecha hasta
    que éstos se correspondan con una fecha válida.
    b) int validarFecha (int dia, int mes, int year);
    Valor de retorno: 1 si la fecha introducida es válida
    (posterior al 01/01/1978; 0<mes<13; 0<d<=días_mes) y 0 en
    caso contrario.
    c) int calcularDias(int dia, int mes, int year);
    Valor de retorno: Número de días que hay entre una
    determinada fecha y el 1 de Enero de 1978.
    Para realizar correctamente este cálculo se requiere
    identificar los años bisiestos
    d) int anioBisiesto(int year);
    Valor de retorno: 1 si el año es bisiesto y 0 en caso
    contrario.
    Nota: Un año es bisiesto si es múltiplo de 4 excepto aquellos divisibles por 100 a no
    ser que lo sean por 400. Así, por ejemplo, los años 1500, 1700, 1800, 1900 y 2100
    son años no bisiestos mientras que los años 1600, 1200 ó 2400 sí son años bisiestos.

 */