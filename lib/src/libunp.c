#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>

#include "libunp.h"

ssize_t readn(int fd, void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nread;

  if(!ptr)
    return -1;

  nleft = n;
  while(nleft > 0) {
    if( (nread = read(fd, ptr, nleft)) < 0) {
      if(nleft == n)
        return -1; //error, return -1
      else
        break; //error, return amount read so far
    } else if(nread == 0) {
      break; //EOF
    }

    nleft -= nread;
    ptr += nread;
  }

  return (n - nleft); //return >= 0
}

ssize_t writen(int fd, const void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nwritten;

  if(!ptr)
    return -1;

  nleft = n;
  while(nleft > 0) {
    if( (nwritten = write(fd, ptr, nleft)) < 0) {
      if(nleft == n)
        return -1; //error, return -1
      else
        break; //error, return amount written so far
    } else if(nwritten == 0) {
      break;
    }

    nleft -= nwritten;
    ptr += nwritten;
  }

  return (n - nleft); //return >= 0
}
