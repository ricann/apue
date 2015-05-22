#ifndef __TCP_ECHOC_H__
#define __TCP_ECHOC_H__

#define MAXLINE     1024
#define IP_DFT      "127.0.0.1"
#define PORT_DFT    5555

typedef struct sockaddr     SA;
typedef struct sockaddr_in  SAIN;

int tcp_cli(int fd);

#endif /* __TCP_ECHOC_H__ */
