#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{ // snode es el nombre de la estructura
    int value;
    struct sNode *next; // El puntero next para recorrer la lista enlazada
} tNode;               // tnodo es el tipo de dato para declarar la estructura

typedef tNode *tNodePointer; // Puntero al tipo de dato tnodo para no utilizar punteros de punteros

void insertarEnLista(tNodePointer *head, int e);
void imprimirLista(tNodePointer head);
void borrarLista(tNodePointer *head);

int main()
{
    int e;
    tNodePointer head;  // Indica head de la lista enlazada, si la perdemos no podremos acceder a la lista
    head = NULL;        // Se inicializa head como NULL ya que no hay ningun nodo cargado en la lista

    printf("Ingrese elementos, -1 para terminar: ");
    scanf("%d", &e);

    while (e != -1)
    {
        insertarEnLista(&head, e);
        printf("Ingresado correctamente");
        printf("\n");
        printf("Ingrese elementos, -1 para terminar: ");
        scanf("%d", &e);
    }

    printf("\nSe imprime la lista cargada: ");
    imprimirLista(head);

    printf("\nSe borra la lista cargada\n");
    borrarLista(&head);

    printf("\n");
    system("PAUSE");

    return 0;
}

void insertarEnLista(tNodePointer *head, int e)
{
    tNodePointer newNode;             // Creamos un nuevo nodo
    newNode = malloc(sizeof(tNode));  // Utilizamos malloc para reservar memoria para ese nodo
    newNode->value = e;               // Le asignamos el value ingresado por pantalla a ese nodo
    newNode->next = *head;            // Le asignamos al siguiente el value de head
    *head = newNode;                  // head pasa a ser el ultimo nodo agregado
}

void imprimirLista(tNodePointer head)
{
    while (head != NULL)
    {                                   // Mientras head no sea NULL
        printf("%4d", head->value);     // Imprimimos el value del nodo
        head = head->next;              // Pasamos al siguiente nodo
    }
}

void borrarLista(tNodePointer *head)
{
    tNodePointer actual;            // Puntero auxiliar para eliminar correctamente la lista

    while (*head != NULL)
    {                               // Mientras head no sea NULL
        actual = *head;             // Actual toma el value de head
        *head = (*head)->next;      // head avanza 1 posicion en la lista
        free(actual);               // Se libera la memoria de la posicion de Actual (el primer nodo), y head queda apuntando al que ahora es el primero
    }
}