#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Función de chat entre cliente y servidor
void func(int connfd)
{
    char buff[MAX];
    int n;
    // bucle infinito para chat
    for (;;)
    {
        memset(buff, 0, MAX);

        // leer el mensaje del cliente y copiarlo en el buffer
        recv(connfd, buff, sizeof(buff), 0);

        // buffer de impresión que contiene el contenido del cliente
        printf("From client: %s\t To client : ", buff);
        memset(buff, 0, MAX);

        n = 0;
        // copiar el mensaje del servidor en el buffer
        while ((buff[n++] = getchar()) != '\n')
            ;

        // y enviar ese buffer al cliente
        send(connfd, buff, sizeof(buff),0);

        // si msg contiene "exit" entonces el servidor sale y el chat termina.
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // inicializar la biblioteca Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    memset(&servaddr, 0, sizeof(servaddr));

    // assignar IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Vinculación del socket recién creado a una IP dada y verificación
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Ahora el servidor está listo para escuchar y verificar
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Aceptación del paquete de datos del cliente y verificación
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    // Función de chat entre cliente y servidor
    func(connfd);

    closesocket(sockfd);
    WSACleanup();
}
