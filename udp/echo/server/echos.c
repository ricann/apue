
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "echos.h"

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;

  if( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket failed!");
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERV_PORT);
  if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind failed!");
    exit(1);
  }

  dg_echo(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));

  return 0;
}

int dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
  int n;
  socklen_t len;
  char mesg[MAXLINE];

  for( ; ;) {
    len = clilen;
    if( (n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len)) == -1) {
      perror("recvfrom failed!");
      exit(1);
    }

    if( (n = sendto(sockfd, mesg, n, 0, pcliaddr, len)) == -1) {
      perror("sendto failed!");
      exit(1);
    }
  }

  return 0;
}
