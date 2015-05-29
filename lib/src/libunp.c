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

/*********************************************************************************
*Function: readn
*Description： read n bytes from specified file descriptor
*Input: fd(file descriptor) / n(number)
*Output: ptr(output buffer)
*Return: read bytes
*Date: 2015/5/28
**********************************************************************************/
ssize_t readn(int fd, void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nread;

  if(!ptr)
    return -1;

  nleft = n;
  while(nleft > 0) {
    if( (nread = read(fd, ptr, nleft)) < 0) {
      if (errno == EINTR)
        nread = 0;    //and call read again
      else
        return -1; //error
    } else if(nread == 0) {
      break; //EOF
    }

    nleft -= nread;
    ptr += nread;
  }

  return (n - nleft); //return >= 0
}

/*********************************************************************************
*Function: writen
*Description： write n bytes to specified file descriptor
*Input: fd(file descriptor) / ptr(input buffer) / n(number)
*Output: none
*Return: written bytes
*Date: 2015/5/28
**********************************************************************************/
ssize_t writen(int fd, const void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nwritten;

  if(!ptr)
    return -1;

  nleft = n;
  while(nleft > 0) {
    if( (nwritten = write(fd, ptr, nleft)) < 0) {
      if (nwritten < 0 && errno == EINTR)
        nwritten = 0;   //and call write again
      else
        return -1; //error
    } else if(nwritten == 0) {
      break;
    }

    nleft -= nwritten;
    ptr += nwritten;
  }

  return (n - nleft); //return >= 0
}
