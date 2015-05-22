#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>

#include "echoc.h"

int main()
{
  int fd;
  struct sockaddr_in srvaddr;

  if( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket fail");
    return -1;
  }

  memset(&srvaddr, 0, sizeof(SAIN));
  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port = htons(5555);
  inet_pton(AF_INET, "127.0.0.1", &srvaddr.sin_addr);

  if(connect(fd, (SA *)&srvaddr, sizeof(SAIN)) < 0) {
    perror("connect fail");
    return -1;
  }

  tcp_cli(fd);

  return 0;
}

int tcp_cli(int fd)
{
  char buf[1024] = {0};

  while(fgets(buf, 1024, stdin) != NULL) {
    write(fd, buf, strlen(buf));
    read(fd, buf, 1024);
    fputs(buf, stdout);
  }

  return 0;
}
