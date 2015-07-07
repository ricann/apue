
#include "libunp.h"

/******************************************************************************
*Function: Read
*Description： read data from opened file, read wrapper
*Input: filedes(file descriptor) / nbytes(max read bytes one time)
*Output: ptr(output buffer)
*Return: read bytes
*Date: 2015/7/7
******************************************************************************/
ssize_t
Read(int filedes, void *ptr, size_t nbytes)
{
  ssize_t n;

  if( (n = read(filedes, ptr, nbytes)) == -1)
    err_sys("read error");

  return n;
}


/******************************************************************************
*Function: Write
*Description： write data to opened file, write wrapper
*Input: filedes(file descriptor) / ptr(buf of data to be written)
        / nbytes(bytes to be written)
*Output: none
*Return: none
*Date: 2015/7/7
******************************************************************************/
void
Write(int filedes, const void *ptr, size_t nbytes)
{
  if(write(filedes, ptr, nbytes) != nbytes)
    err_sys("write error");
}

/******************************************************************************
*Function: Fork
*Description： create a new process, fork wrapper
*Input: none
*Output: none
*Return: pid
*Date: 2015/7/7
******************************************************************************/
pid_t
Fork(void)
{
  pid_t pid;

  if( (pid = fork()) == -1)
    err_sys("fork error");

  return pid;
}

/******************************************************************************
*Function: Pipe
*Description： create pipe, pipe wrapper
*Input: none
*Output: none
*Return: pid
*Date: 2015/7/7
******************************************************************************/
void
Pipe(int filedes[2])
{
  if(pipe(filedes) == -1)
    err_sys("pipe error");
}
