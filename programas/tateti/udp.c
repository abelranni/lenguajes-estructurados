// Client side implementation of UDP client-server model
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "udp.h"

#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 12345

struct sockaddr_in si_other;
int s, slen=sizeof(si_other);
char buf[BUFLEN];
char message[BUFLEN];
WSADATA wsa;

void die(char *s) {
    perror(s);
    WSACleanup();
    exit(1);
}

int udp_config(void) {

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        fprintf(stderr, "Failed. Error Code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
        die("socket");
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);

    if (inet_addr(SERVER) == INADDR_NONE) {
        die("inet_addr");
    }
    si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

    // while(1) {
    //     printf("Enter message: ");
    //     gets(message);

    //     //send the message
    //     if (sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR) {
    //         die("sendto()");
    //     }

    //     //receive a reply and print it
    //     memset(buf,'\0', BUFLEN);
    //     if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR) {
    //         die("recvfrom()");
    //     }

    //     puts(buf);
    // }

    // closesocket(s);
    // WSACleanup();

    return 0;
}

void udp_send(char *message) {
    if (sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR) {
        die("sendto()");
    }
}

void udp_recv (char *buf) {
    if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR) {
        die("recvfrom()");
    }
}

void udp_close(void) {
    closesocket(s);
    WSACleanup();
}

