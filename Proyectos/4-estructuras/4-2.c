#include <stdio.h>

struct fraccion
{
    int num;
    int den;
};

int Mostrar_Menu(void);
struct fraccion suma(struct fraccion f1, struct fraccion f2);
struct fraccion multiplicar(struct fraccion f1, struct fraccion f2);
struct fraccion dividir(struct fraccion f1, struct fraccion f2);
struct fraccion opuesto(struct fraccion f);
struct fraccion inverso(struct fraccion f);

int main()
{
    struct fraccion f1, f2, resultado;
    int op;
    do
    {
        op = Mostrar_Menu();
        switch (op)
        {

        case 1:
        {
            printf("Introduzca num y denominador de f1\n");
            scanf("%d", &f1.num);
            scanf("%d", &f1.den);
            printf("Introduzca num y denominador de f2\n");
            scanf("%d", &f2.num);
            scanf("%d", &f2.den);
            resultado = suma(f1, f2);
            printf("El resultado de la suma es %d/%d\n", resultado.num, resultado.den);
            break;
        };

        case 2:
        {
            printf("Introduzca num y denominador de f1\n");
            scanf("%d", &f1.num);
            scanf("%d", &f1.den);
            printf("Introduzca num y denominador de f2\n");
            scanf("%d", &f2.num);
            scanf("%d", &f2.den);
            resultado = multiplicar(f1, f2);
            printf("El resultado de la multiplicacion es %d/%d\n", resultado.num, resultado.den);
            break;
        };

        case 3:
        {
            printf("Introduzca num y denominador de f1\n");
            scanf("%d", &f1.num);
            scanf("%d", &f1.den);
            printf("Introduzca num y denominador de f2\n");
            scanf("%d", &f2.num);
            scanf("%d", &f2.den);
            resultado = dividir(f1, f2);
            printf("El resultado de la division es %d/%d\n", resultado.num, resultado.den);
            break;
        };

        case 4:
        {
            printf("Introduzca num y denominador de f\n");
            scanf("%d", &f1.num);
            scanf("%d", &f1.den);
            resultado = opuesto(f1);
            printf("El opuesto de f1 es %d/%d\n", resultado.num,
                   resultado.den);
            break;
        };

        case 5:
        {
            printf("Introduzca num y denominador de f\n");
            scanf("%d", &f1.num);
            scanf("%d", &f1.den);
            resultado = inverso(f1);
            printf("El inverso de f1 es %d/%d\n", resultado.num,
                   resultado.den);
            break;
        };

        case 6:
            break;

        default:
            printf("La operación seleccionada no es válida\n");

        }

    } while (op != 6);

    return (0);
}

int Mostrar_Menu(void)
{
    int op;
    printf("Seleccione la operación a realizar\n");
    printf("1. Suma\n");
    printf("2. Multiplicacion\n");
    printf("3. Division\n");
    printf("4. Opuesto\n");
    printf("5. Inverso\n");
    printf("6. Salir\n");
    scanf("%d", &op);
    return (op);
}

struct fraccion suma(struct fraccion f1, struct fraccion f2)
{
    struct fraccion r;
    r.num = f1.num * f2.den + f2.num * f1.den;
    r.den = f1.den * f2.den;

    return (r);
}

struct fraccion multiplicar(struct fraccion f1, struct fraccion f2)
{
    struct fraccion r;
    r.num = f1.num * f2.num;
    r.den = f1.den * f2.den;

    return (r);
}

struct fraccion dividir(struct fraccion f1, struct fraccion f2)
{
    struct fraccion r;
    r.num = f1.num * f2.den;
    r.den = f1.den * f2.num;
    return (r);
}

struct fraccion opuesto(struct fraccion f)
{
    struct fraccion r;
    r.num = -f.den;
    r.den = f.num;
    return (r);
}

struct fraccion inverso(struct fraccion f)
{
    // Intercambia los términos de la fraccion
    struct fraccion r;
    r.num = f.den;
    r.den = f.num;
    return (r);
}

/* 
    Escriba un programa que, tratando una fracción como una estructura de 2 componentes, 
    permita realizar las operaciones suma, multiplicación, división, opuesto e inverso. 
    El programa deberá preguntar la operación a realizar y después los datos para ejecutarla, 
    y repetir estos pasos hasta que se seleccione entre las operaciones la opción terminar. 
    Cada una de las operaciones se implementará como una función.  
 */