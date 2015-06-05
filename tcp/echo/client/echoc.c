#include "libunp.h"
#include "echoc.h"

int main(int argc, char *argv[])
{
  int fd;
  struct sockaddr_in srvaddr;

  if( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket fail");
    return -1;
  }

  memset(&srvaddr, 0, sizeof(SAIN));
  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port = htons(PORT_DFT);
  inet_pton(AF_INET, IP_DFT, &srvaddr.sin_addr);

  if(connect(fd, (SA *)&srvaddr, sizeof(SAIN)) < 0) {
    perror("connect fail");
    return -1;
  }

  tcp_cli(fd);

  return 0;
}

int tcp_cli(int fd)
{
  char sendline[MAXLINE];
  char recvline[MAXLINE];

  while(fgets(sendline, MAXLINE, stdin) != NULL) {
    Writen(fd, sendline, strlen(sendline));
    if(Readline(fd, recvline, MAXLINE) == 0)
      err_quit("tcp_cli: server terminated prematurely");
    fputs(recvline, stdout);
  }

  return 0;
}
