#ifndef __ECHOS_H__
#define __ECHOS_H__

#define SERV_PORT       32666
#define MAXLINE         1024

int dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen);

#endif /* __ECHOS_H__ */
