
#ifndef TCP_H
#define TCP_H

int tcp_config_connect();
int tcp_connect();
void tcp_send(char *msg);
int tcp_recv(char *msg);
void tcp_close();

#endif // TCP_H
