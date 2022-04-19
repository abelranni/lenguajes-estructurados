## Pila o stack dinámica en el lenguaje C

Una pila es una estructura de datos simple. Los datos se van apilando uno tras otro. Podemos abstraer cada elemento como un nodo que puede apuntar a otro nodo.

Su modo de acceso es **LIFO**: el **último en entrar es el primero en salir**. Las operaciones que tiene son 2: **push** y **pop**; la primera le pone un elemento y la segunda quita el último.


```
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
```



Pila dinámica en C

Veremos las operaciones básicas de una pila o stack en C son:

-   **Tamaño:** devolver el tamaño de la pila
-   **Apilar, también conocido como push:** agregar un elemento
-   **Desapilar, o la operación pop:** quitar el último elemento; es decir, el elemento superior
-   **Leer último:** leer el elemento superior de la pila
-   **Vacía**: indica si la pila está vacía
-   **Imprimir:** recorrer la pila e imprimir sus valores

Esta pila será **dinámica**: podremos poner elementos infinitos siempre y cuando nuestra memoria RAM alcance


## 1.- El nodo


```
// Un nodo tiene un dato, el cual es el número. Y otro nodo al que apunta
struct nodo {
    int numero;
    struct nodo *siguiente;
};
```

Esto es de lo que estará compuesta nuestra pila, para ello usaremos una **lista enlazada** en donde un nodo apunta a otro y este otro a otro (opcionalmente), así infinitamente.

Claro que el elemento siguiente de un nodo es opcional; porque **el elemento de hasta abajo no apunta a nadie**.

También tiene un número, **que es el dato en sí** que guardaremos en la pila. Si quisiéramos que nuestra pila fuera de strings entonces comenzaríamos cambiando el tipo de dato de **int** a **char\[\]**.

## 2.- El elemento superior

```
// Todo comienza con el nodo superior
struct nodo *superior = NULL;
```

En el inicio, debe haber un elemento superior aunque no tenga valor y no apunte a nada. Es decir, aunque la pila esté vacía debemos tener un elemento que será el inicio de todo:

## 3.- Agregar elementos a la pila: push

Veamos la **operación push**, que agrega un elemento a la pila.

```
// Operación push
void agregar(int numero) {
    printf("Agregando %d\n", numero);
    // El que se agregará; reservamos memoria
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
    // Le ponemos el dato
    nuevoNodo->numero = numero;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}
```


El nodo superior es una variable global, por eso no necesitamos recibirla en la función.

Lo que hacemos es **alojar espacio en memoria** para almacenar nuestro nuevo elemento usado memory allocate o **malloc**.

A ese nuevo nodo **le ponemos el dato que llevará** (el entero), y como es el que estará hasta arriba entonces hacemos que apunte hacia el que era el superior; y este nuevo ahora tomará su lugar.

Explicado en otras palabras, **este nuevo nodo será el superior y apuntará al que antes era el superior**; se está poniendo encima de él.

La próxima vez que apilemos, se creará otro nuevo y este dejará de ser el superior para pasar a ser el siguiente del nuevo; y así sucesivamente.

## 4.- Eliminar el último elemento (operación pop)

Como vamos a desapilar el elemento, necesitamos hacer que el elemento superior ahora sea al que apuntaba; es decir, su siguiente.

Pero eso no es todo, debemos liberar la memoria que se estaba usando y para ello respaldamos lo que ocupaba el que vamos a eliminar dentro de **temporal** y llamamos a **free**.


```
// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void) {
    printf("Eliminando el último\n");
    if (superior != NULL) {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo *temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;
 
        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
}
```

Esto sólo ocurre en caso de que **superior** no sea nulo.

## 5.- Imprimir pila

Imprimir la pila no es una operación necesaria, pero como este es un ejercicio sí lo haremos. Únicamente recorremos toda la pila mientras haya un apuntador a siguiente:

```
void imprimir(void) {
    printf("Imprimiendo...\n");
    struct nodo *temporal = superior;
    while (temporal != NULL) {
        printf("%d\n", temporal->numero);
        temporal = temporal->siguiente;
    }
}
```

Para esto necesitamos un nodo temporal y comenzamos recorriendo desde **superior**. Asignamos a **temporal** lo que esté apuntando a **siguiente**; si ya no apunta a nada entonces temporal **será nulo y se terminará el ciclo**.

## 6.- Tamaño de pila o stack en C

Esto es muy parecido al de imprimir; pero en lugar de imprimir vamos aumentando un contador dentro del ciclo:

```
int tamanio(void){
    int contador = 0;
    if(superior == NULL) return contador;
    struct nodo *temporal = superior;
    while (temporal != NULL) {
		contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}
```

Comprobamos **si superior es nulo** y en caso de que sí ya no hacemos el ciclo, pues la pila está vacía.

## 7.- Método para saber si la pila está vacía

```
bool vacia(void){
    return superior == NULL;
}
```

Podríamos decir que, si ya tenemos el método `tamanio`, podríamos regresar un booleano resultante de la comparación de `tamanio == 0` pero eso sería un **desperdicio de recursos**

Ya que si la pila tiene 0 elementos todo va bien, pero, ¿qué tal si la pila tiene 100000 elementos? tendríamos que recorrer todos dentro de **tamanio** para determinar al final que la pila no está vacía.

Es por eso que mejor usamos otra lógica… si el elemento superior no apunta a nada, entonces no hay más elementos y por lo tanto la pila está vacía.

## 8.- Operación top o peek de la pila: último elemento

Esto es fácil, se lee el último elemento de la pila y en este caso es un entero.


```
int ultimo(){
    if(superior == NULL) return -1;
    return superior->numero;
}
```

Si superior es nulo, **devolvemos -1**.

En caso de que no, entonces devolvemos lo que tenga el elemento superior.
