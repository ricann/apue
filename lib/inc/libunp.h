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


//read and write related
ssize_t Readn(int fd, void *ptr, size_t nbytes);
ssize_t Writen(int fd, const void *ptr, size_t nbytes);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Readline_buf(void **vptrptr);

//for error information
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

#endif /* __LIBUNP_H__ */
