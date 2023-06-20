#!/bin/bash

echo "Eliminando archivos objeto y ejecutable antiguos..."
rm ./obj/*.o ./bin/tateti

echo "Compilando init.c..."
gcc -I/usr/include/SDL2 -c init.c -o ./obj/init.o

echo "Compilando render.c..."
gcc -I/usr/include/SDL2 -c render.c -o ./obj/render.o

echo "Compilando logic.c..."
gcc -I/usr/include/SDL2 -c logic.c -o ./obj/logic.o

echo "Compilando minimax.c..."
gcc -I/usr/include/SDL2 -c minimax.c -o ./obj/minimax.o

echo "Compilando event.c..."
gcc -I/usr/include/SDL2 -c event.c -o ./obj/event.o

echo "Compilando score.c..."
gcc -I/usr/include/SDL2 -c score.c -o ./obj/score.o

echo "Compilando state.c..."
gcc -I/usr/include/SDL2 -c state.c -o ./obj/state.o

echo "Compilando udp.c..."
gcc -I/usr/include/SDL2 -c udp.c -o ./obj/udp.o

echo "Compilando config.c..."
gcc -I/usr/include/SDL2 -c config.c -o ./obj/config.o

echo "Compilando main.c..."
gcc -I/usr/include/SDL2 -c main.c -o ./obj/main.o

echo Copiando archivo de configuracion...
cp config.cfg bin/config.cfg

echo "Linkeando..."
gcc ./obj/init.o ./obj/render.o ./obj/logic.o ./obj/minimax.o ./obj/event.o ./obj/score.o  ./obj/state.o ./obj/udp.o ./obj/config.o ./obj/main.o -o ./bin/tateti -lSDL2 -lSDL2_ttf -lSDL2_image -lm

echo "Ejecutando el programa..."
cd bin
./tateti
cd ..
