@echo off

echo Eliminando archivos objeto y ejecutable antiguos...
del .\obj\*.o .\bin\tateti.exe

echo Compilando init.c...
gcc -c init.c -o ./obj/init.o

echo Compilando render.c...
gcc -c render.c -o ./obj/render.o

echo Compilando logic.c...
gcc -c logic.c -o ./obj/logic.o

echo Compilando minimax.c...
gcc -c minimax.c -o ./obj/minimax.o

echo Compilando event.c...
gcc -c event.c -o ./obj/event.o

echo Compilando state.c...
gcc -c state.c -o ./obj/state.o

echo Compilando udp.c...
gcc -c udp.c -o ./obj/udp.o

echo Compilando main.c...
gcc -c main.c -o ./obj/main.o

echo Linkeando...
gcc ^
./obj/init.o ^
./obj/render.o ^
./obj/logic.o ^
./obj/minimax.o ^
./obj/event.o ^
./obj/state.o ^
./obj/udp.o ^
./obj/main.o ^
-o ./bin/tateti.exe -lSDL2 -lSDL2_ttf -lSDL2_image -lws2_32

echo Ejecutando el programa...
cd bin
tateti.exe
cd ..

