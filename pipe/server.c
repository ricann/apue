#include <libunp.h>

void
server(int rfd, int wfd)
{
  int fd;
  ssize_t n;
  char buf[MAXLINE];

  if( (n = read(rfd, buf, MAXLINE)) == 0)
    err_quit("end-of-file while reading pathname");

  buf[n] = '\0';

  if( (fd = open(buf, O_RDONLY)) < 0) {
    //error, must tell client
    snprintf(buf+n, sizeof(buf)-n, "can't open, %s\n",
      strerror(errno));
    n = strlen(buf);
    write(wfd, buf, n);
  } else {
    while ( (n = read(fd, buf, MAXLINE)) > 0)
      write(wfd, buf, n);

    close(fd);
  }
}
