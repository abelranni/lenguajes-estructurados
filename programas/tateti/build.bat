@echo off

echo Eliminando archivos objeto y ejecutable antiguos...
del /Q ./obj/init.o ./obj/main.o ./bin/tateti.exe

echo Compilando init.c...
gcc -c init.c -o ./obj/init.o

echo Compilando main.c...
gcc -c main.c -o ./obj/main.o

echo Linkeando...
gcc ./obj/init.o ./obj/main.o -o ./bin/tateti.exe  -lSDL2 -lSDL2_ttf -lSDL2_image

echo Ejecutando el programa...
cd bin
tateti.exe
cd ..

