#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "udp.h"

#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 12345

struct sockaddr_in socket_in;
int socket_id, slen = sizeof(socket_in);
char udp_buffer[BUFLEN];
WSADATA wsa;

void die(char *s)
{
    perror(s);
    WSACleanup();
    exit(1);
}

int udp_config(void)
{

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        fprintf(stderr, 
                "Failed. Error Code : %d", 
                WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket_id == SOCKET_ERROR)
    {
        die("socket");
    }

    memset((char *)&socket_in, 0, sizeof(socket_in));

    socket_in.sin_family = AF_INET;
    socket_in.sin_port = htons(PORT);

    if (inet_addr(SERVER) == INADDR_NONE)
    {
        die("inet_addr");
    }
    socket_in.sin_addr.S_un.S_addr = inet_addr(SERVER);
    return 0;
}

void udp_send(char *message)
{
    int send_code;

    send_code = sendto( socket_id, 
                        message, 
                        strlen(message), 
                        0, 
                        (struct sockaddr *)&socket_in, 
                        slen );

    if ( send_code == SOCKET_ERROR )
    {
        die("udp_send()");
    }
}

// void udp_recv(char *buf)
// {
//     memset(buf, '\0', BUFLEN);
//     if (recvfrom(socket_id, buf, BUFLEN, 0, (struct sockaddr *)&socket_in, &slen) == SOCKET_ERROR)
//     {
//         die("recvfrom()");
//     }
// }

// void udp_close(void)
// {
//     closesocket(socket_id);
//     WSACleanup();
// }
