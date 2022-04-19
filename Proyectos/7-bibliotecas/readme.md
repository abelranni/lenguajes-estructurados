# Bibliotecas Dinámicas y Estáticas en C

## Introducción

Las bibliotecas permiten reutilizar el mismo código en varios programas. 
Con bibliotecas dinámicas  se puede compartir código en tiempo de ejecución.
Simplifica la posibilidad de escalar y administrar el código de una manera simple y eficiente.

### Bibliotecas Estáticas

Primero se compilan los archivos fuentes para generar el código objeto de cada uno de ellos.
  
```bash

gcc -c  encrypt.c -o encrypt.o
gcc -c  checksum.c -o checksum.o

```

Luego se utiliza el comando `ar` (archive command) para guardar todos los objetos en una biblioteca (archive) con extensión .a (el nombre del archivo biblioteca debe comenzar con el prefijo lib)

```bash

ar -rcs libcrypt.a encrypt.o checksum.o

```

Finalmente se puede compilar otro archivo fuente incluyendo la biblioteca generada previamente

```bash

gcc test_code.c -L. -lcrypt -o test_code

```

El flag -L se usa para indicar el path donde se encuentran los archivos de biblioteca
En este caso -L. indica que es en el directorio local
A conticuación del flag -l se escribe el nombre de la biblioteca sin el prefijo lib


### Bibliotecas Dinámicas

La generación de archivos binarios a partir de cada código fuente es la igual que antes.
En algunos sistemas operativos puede ser necesario incorporar el flag -fPIC (Position Independent Code) al comando de compilación, es decir:

```bash

gcc -fPIC -c nombre-archivo-fuente.c -o nombre-archivo-objeto.o

```

Las bibliotecas de enlace dinámico tienen distintas extensiones según el sistema operativo:

* En windows .dll (dinamic link library)
* En linux/unix .so (shared object)
* En Mac .dylib (dynamic library)

En nuestro caso podemos generar la biblioteca con el siguiente comando:

```bash

gcc -shared encrypt.o checksum.o -o crypt.dll

```

Luego se puede comilar el programa principal de la siguiente forma:

```bash

gcc -c test_code.c -o test_code.o
gcc test_code.o -L. -lcrypt -o test_code

```
