#include <libunp.h>


void client(int, int);
void server(int, int);

int
main(int argc, char **argv)
{
  int pipe1[2], pipe2[2];
  pid_t cpid;

  pipe(pipe1);
  pipe(pipe2);

  if( (cpid = fork()) == 0) { //child
    close(pipe1[1]);
    close(pipe2[0]);

    server(pipe1[0], pipe2[1]);
    exit(0);
  }

  close(pipe1[0]);
  close(pipe2[1]);

  client(pipe2[0], pipe1[1]);

  waitpid(cpid, NULL, 0);
  exit(0);
}
