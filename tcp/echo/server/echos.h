#ifndef __TCP_ECHOS_H__
#define __TCP_ECHOS_H__

#define MAXLINE           1024
#define IP_DFT            "127.0.0.1"
#define PORT_DFT          5555
#define LISTEN_LIST_LEN   10

typedef struct sockaddr     SA;
typedef struct sockaddr_in  SAIN;

int tcp_echo(int connfd);

#endif /* __TCP_ECHOS_H__ */
