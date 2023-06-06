#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib,"ws2_32.lib") //Winsock Library
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define SOCKET_ERROR -1
#endif

#define SERVER "192.168.100.80"
#define BUFLEN 512
#define PORT 12345

struct sockaddr_in socket_in;
int socket_id, slen = sizeof(socket_in);
char udp_buffer[BUFLEN];

#ifdef _WIN32
    WSADATA wsa;
#endif

void die(char *s)
{
    perror(s);
    #ifdef _WIN32
        WSACleanup();
    #endif
    exit(1);
}

int udp_config(void)
{
    #ifdef _WIN32
        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        {
            fprintf(stderr, 
                    "Failed. Error Code : %d", 
                    WSAGetLastError());
            exit(EXIT_FAILURE);
        }
    #endif

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

    #ifdef _WIN32
        socket_in.sin_addr.S_un.S_addr = inet_addr(SERVER);
    #else
        socket_in.sin_addr.s_addr = inet_addr(SERVER);
    #endif

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

void udp_recv(char *buf)
{
    memset(buf, '\0', BUFLEN);
    if (recvfrom(socket_id, buf, BUFLEN, 0, (struct sockaddr *)&socket_in, &slen) == SOCKET_ERROR)
    {
        die("recvfrom()");
    }
}

void udp_close(void)
{
    #ifdef _WIN32
        closesocket(socket_id);
        WSACleanup();
    #else
        close(socket_id);
    #endif
}
