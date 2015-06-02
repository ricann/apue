#include "libunp.h"
#include "echos.h"

int main()
{
  int listenfd, connfd;
  struct sockaddr_in srvaddr, accaddr;
  socklen_t len;
  pid_t pid;

  if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket fail");
    return -1;
  }

  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port = htons(PORT_DFT);
  srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listenfd, (SA *)&srvaddr, sizeof(SAIN)) < 0) {
    perror("bind fail");
    return -1;
  }

  if(listen(listenfd, LISTEN_LIST_LEN) < 0) {
    perror("listen fail");
    return -1;
  }

  while(1)
  {
    len = sizeof(SAIN);
    if( (connfd = accept(listenfd, (SA *)&accaddr, &len)) < 0) {
      perror("accept fail");
      return -1;
    }

    pid = fork();
    if(pid == 0) { //child process
      close(listenfd);
      tcp_echo(connfd);
      exit(0);
    } else if(pid < 0) {
      perror("fork fail");
      return -1;
    }

    close(connfd);
  }

  return 0;
}

int tcp_echo(int connfd)
{
  int n;
  char buf[MAXLINE] = {0};

again:
  while( (n = read(connfd, buf, sizeof(buf))) > 0)
    Writen(connfd, buf, n);

  if(n<0 && errno==EINTR)
    goto again;
  else if(n < 0)
    printf("read error!\n");

  return 0;
}
