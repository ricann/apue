
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "echoc.h"

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr;

  if(argc != 2)
  {
    printf("please input ip address!\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd == -1)
  {
    perror("socket failed");
    exit(1);
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  dg_cli(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  return 0;
}

int dg_cli(int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)
{
  int n;
  char sendline[MAXLINE], recvline[MAXLINE];

  while(fgets(sendline, MAXLINE, stdin) != NULL)
  {
    n = sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
    if(n == -1)
    {
      perror("sendto failed!");
      exit(1);
    }

    n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
    if(n == -1)
    {
      perror("recvfrom failed!");
      exit(1);
    }
    recvline[n] = '\0';
    fputs(recvline, stdout);
  }

  return 0;
}
