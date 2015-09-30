#ifndef __LIBUNP_H__
#define __LIBUNP_H__

//head files
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//macros
#define MAXLINE   4096  //max text line length
#define BUFFSIZE  8192  //buffer size for reads and writes

#define	SA	struct sockaddr

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

//wrapunix.c
//unix functions wrappers
int Open(const char *pathname, int oflag, mode_t mode);
void Close(int filedes);
ssize_t Read(int filedes, void *ptr, size_t nbytes);
void Write(int filedes, const void *ptr, size_t nbytes);
pid_t Fork(void);
pid_t Waitpid(pid_t pid, int *statloc, int options);
void Pipe(int filedes[2]);

//wrapstdio.c
//stdio functions wrappers
char *Fgets(char *buf, int n, FILE *fp);
void *Malloc(size_t size);

//wrapsock.c
//socket related wrappers
int Socket(int family, int type, int protocol);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
  const struct sockaddr *sa, socklen_t salen);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
  struct sockaddr *sa, socklen_t *salenptr);
void Setsockopt(int fd, int level, int optname, const void *optval,
  socklen_t optlen);
void Getsockopt(int fd, int level, int optname, void *optval,
  socklen_t *optlenptr);

//librw.c
//read and write related,
ssize_t Readn(int fd, void *ptr, size_t nbytes);
ssize_t Writen(int fd, const void *ptr, size_t nbytes);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Readline_buf(void **vptrptr);

//liberr.c
//for error information
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

#endif /* __LIBUNP_H__ */
