#ifndef __TCP_ECHOS_H__
#define __TCP_ECHOS_H__

typedef struct sockaddr     SA;
typedef struct sockaddr_in  SAIN;

int tcp_echo(int connfd);

#endif /* __TCP_ECHOS_H__ */
