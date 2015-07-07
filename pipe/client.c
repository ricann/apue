#include <libunp.h>

void
client(int rfd, int wfd)
{
  size_t len;
  ssize_t n;
  char buf[MAXLINE];

  fgets(buf, MAXLINE, stdin);
  len = strlen(buf);

  if(buf[len-1] == '\n')
    len--;

  write(wfd, buf, len);

  while( (n = read(rfd, buf, MAXLINE)) > 0)
    write(STDOUT_FILENO, buf, n);
}
