#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "debug.h"
#include "tcp.h"

#define PORT 12345

int status, valread, client_fd;
struct sockaddr_in serv_addr;
char *hello = "Hello from client";
char buffer[1024] = {0};
int n;

int tcp_config_connect()
{

    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir direcciones IPv4 e IPv6 de texto a formato binario
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
                          sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    // send(client_fd, hello, strlen(hello), 0);
    // printf("Hello message sent\n");

    // valread = recv(client_fd, buffer, 1024, 0);
    // printf("%s\n", buffer);

    // // bucle infinito para chat
    // for (;;)
    // {
    //     valread = recv(client_fd, buffer, 1024, 0);
    //     printf("%s\n", buffer);

    //     n = 0;
    //     // copiar el mensaje del servidor en el buffer
    //     while ((buffer[n++] = getchar()) != '\n')
    //         ;

    //     // y enviar ese buffer al cliente
    //     send(client_fd, buffer, sizeof(buffer),0);

    // }
    // closesocket(client_fd);
    // WSACleanup();

    return 0;
}

int tcp_connect()
{
    if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
                          sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }    
    return 0;
}

void tcp_send(char *msg)
{
    valread = send(client_fd, msg, strlen(msg), 0);
    if (valread < 0)
    {
        printf("Error al enviar mensaje\n");
    }
    else
    {
        DEBUG2("Mensaje enviado: %s \n", msg);
    }

}

int tcp_recv(char *msg)
{
    valread = recv(client_fd, msg, 1024, 0);
    return valread;
}

void tcp_close()
{
    closesocket(client_fd);
    WSACleanup();
}
