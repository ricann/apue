#include <libunp.h>

void
client(int rfd, int wfd)
{
  size_t len;
  ssize_t n;
  char buf[MAXLINE];

  Fgets(buf, MAXLINE, stdin);
  len = strlen(buf);

  if(buf[len-1] == '\n')
    len--;

  Write(wfd, buf, len);

  while( (n = Read(rfd, buf, MAXLINE)) > 0)
    Write(STDOUT_FILENO, buf, n);
}
