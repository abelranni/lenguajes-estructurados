echo Compilando servidor
gcc tcp_server.c -o tcp_server.exe -lws2_32

echo Compilando cliente
gcc tcp_client.c -o tcp_client.exe -lws2_32

