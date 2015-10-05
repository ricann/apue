#include "libunp.h"

#include <netdb.h>

/******************************************************************************
*Function: tcp_connect
*Description: used in tcp client, connect a server using specified host and serv
*Input: host(host name) / serv(port name)
*Output: none
*Return: socket descriptor
*Date: 2015/9/28
******************************************************************************/
int
tcp_connect(const char *host, const char *serv)
{
  int sockfd, n;
  struct addrinfo hints, *res, *ressave;

  bzero(&hints, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
    err_quit("tcp_connect error for %s, %s: %s",
      host, serv, gai_strerror(n));

  ressave = res;

  do {
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
      continue;

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
      break;

    Close(sockfd);
  } while ( (res = res->ai_next) != NULL);

  if (res == NULL)
    err_sys("tcp_connect error for %s, %s", host, serv);

  freeaddrinfo(ressave);

  return sockfd;
}

/******************************************************************************
*Function: tcp_listen
*Description: used in tcp server, waiting for a client to connect
*Input: host(host name) / serv(port name)
*Output: addrlenp(address length)
*Return: socket descriptor
*Date: 2015/9/29
******************************************************************************/
int
tcp_listen(const char *host, const char *serv, socklen_t *addrlenp)
{
  int listenfd, n;
  const int on = 1;
  struct addrinfo hints, *res, *ressave;

  bzero(&hints, sizeof(struct addrinfo));
  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
    err_quit("tcp_listen error for %s, %s: %s",
      host, serv, gai_strerror(n));

  ressave = res;

  do {
    listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (listenfd < 0)
      continue;

    Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    if (bind(listenfd, res->ai_addr, res->ai_addrlen) == 0)
      break;

    Close(listenfd);
  } while ( (res = res->ai_next) != NULL);

  if (res == NULL)
    err_sys("tcp_listen error for %s, %s", host, serv);

  Listen(listenfd, LISTENQ);

  if (addrlenp)
    *addrlenp = res->ai_addrlen;

  freeaddrinfo(ressave);

  return listenfd;
}

/******************************************************************************
*Function: udp_client
*Description: used in udp client, connect to a specified host
*Input: host(host name) / serv(port name)
*Output: saptr(socket ip address) / addrlenp(address length)
*Return: socket descriptor
*Date: 2015/9/29
******************************************************************************/
int
udp_client(const char *host, const char *serv, SA **saptr, socklen_t *lenp)
{
  int sockfd, n;
  struct addrinfo hints, *res, *ressave;

  bzero(&hints, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
    err_quit("udp_client error for %s, %s: %s",
      host, serv, gai_strerror(n));

  ressave = res;

  do {
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd >= 0)
      break;
  } while ( (res = res->ai_next) != NULL);

  if (res == NULL)
    err_sys("udp_client error for %s, %s", host, serv);

  *saptr = Malloc(res->ai_addrlen);
  memcpy(*saptr, res->ai_addr, res->ai_addrlen);
  *lenp = res->ai_addrlen;

  freeaddrinfo(ressave);

  return sockfd;
}

/******************************************************************************
*Function: udp_connect
*Description: used in udp client, connect to a specified host
*Input: host(host name) / serv(port name)
*Output: none
*Return: socket descriptor
*Date: 2015/10/5
******************************************************************************/
int
udp_connect(const char *host, const char *serv)
{
  int sockfd, n;
  struct addrinfo hints, *res, *ressave;

  bzero(&hints, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
    err_quit("udp_connect error for %s, %s: %s",
      host, serv, gai_strerror(n));

  ressave = res;

  do {
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
      continue;

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
      break;

    Close(sockfd);
  } while ( (res = res->ai_next) != NULL);

  if (res == NULL)
    err_sys("udp_connect error for %s, %s", host, serv);

  freeaddrinfo(ressave);

  return sockfd;
}

/******************************************************************************
*Function: udp_server
*Description: used in udp server, connect to a specified host
*Input: host(host name) / serv(port name)
*Output: addrlenp(address length)
*Return: socket descriptor
*Date: 2015/10/5
******************************************************************************/
int
udp_server(const char *host, const char *serv, socklen_t *addrlenp)
{
  int sockfd, n;
  struct addrinfo hints, *res, *ressave;

  bzero(&hints, sizeof(struct addrinfo));
  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
    err_quit("udp_server error for %s, %s: %s",
      host, serv, gai_strerror(n));

  ressave = res;

  do {
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
      continue;

    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == 0)
      break;

    Close(sockfd);
  } while ( (res = res->ai_next) != NULL);

  if (addrlenp)
    *addrlenp = res->ai_addrlen;

  freeaddrinfo(ressave);

  return sockfd;
}
