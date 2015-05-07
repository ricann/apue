#ifndef __ECHOC_H__
#define __ECHOC_H__

#define SERV_PORT       32666
#define MAXLINE         1024

int dg_cli(int sockfd, const struct sockaddr *pservaddr, socklen_t servlen);

#endif /* __ECHOC_H__ */
