#include "libunp.h"

/******************************************************************************
*Function: readn
*Description： read n bytes from specified file descriptor
*Input: fd(file descriptor) / n(number)
*Output: ptr(output buffer)
*Return: read bytes
*Date: 2015/5/28
******************************************************************************/
ssize_t
readn(int fd, void *ptr, size_t n)
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

/******************************************************************************
*Function: Readn
*Description： read n bytes from specified file descriptor
*Input: fd(file descriptor) / nbytes(number)
*Output: ptr(output buffer)
*Return: read bytes
*Date: 2015/6/2
******************************************************************************/
ssize_t
Readn(int fd, void *ptr, size_t nbytes)
{
  ssize_t n;

  if( (n = readn(fd, ptr, nbytes)) < 0)
    err_sys("readn error");

  return n;
}

/******************************************************************************
*Function: writen
*Description： write n bytes to specified file descriptor
*Input: fd(file descriptor) / ptr(input buffer) / n(number)
*Output: none
*Return: written bytes
*Date: 2015/5/28
******************************************************************************/
ssize_t
writen(int fd, const void *ptr, size_t n)
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

/******************************************************************************
*Function: writen
*Description： write n bytes to specified file descriptor
*Input: fd(file descriptor) / ptr(input buffer) / nbytes(number)
*Output: none
*Return: written bytes
*Date: 2015/5/28
******************************************************************************/
ssize_t
Writen(int fd, const void *ptr, size_t nbytes)
{
  ssize_t n;

  if( (n = writen(fd, ptr, nbytes)) < 0)
    err_sys("writen error");

  return n;
}

/******************************************************************************
*Function: readline
*Description： read a line from a file descriptor
*Input: fd(file descriptor) / n(number)
*Output: vptr(output buffer)
*Return: read bytes
*Date: 2015/6/5
******************************************************************************/
ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
  ssize_t n, rc;
  char c, *ptr;

  ptr = vptr;
  for(n=1; n<maxlen; n++) {
  again:
    if( (rc = read(fd, &c, 1)) == 1) {
      *ptr++ = c;
      if(c == '\n')
        break;          //new line is stored, like fgets()
    } else if(rc == 0) {
      *ptr = '\0';
      return (n - 1);   //EOF, n-1 bytes were read
    } else {
      if(errno == EINTR)
        goto again;
      return -1;        //error, errno set by read()
    }
  }

  *ptr = '\0';          //null terminate like fgets()
  return n;
}

/******************************************************************************
*Function: Readline
*Description： read a line from a file descriptor
*Input: fd(file descriptor) / n(number)
*Output: vptr(output buffer)
*Return: read bytes
*Date: 2015/6/5
******************************************************************************/
ssize_t
Readline(int fd, void *vptr, size_t maxlen)
{
  ssize_t n;

  if( (n = readline(fd, vptr, maxlen)) < 0)
    err_sys("readline error");

  return n;
}
