
#include "libunp.h"

/******************************************************************************
*Function: Open
*Description: open or create a file, open wrapper
*Input: pathname(file's pathname) / oflag(open flag) / mode(set privilege)
*Output: none
*Return: file descriptor
*Date: 2015/7/7
******************************************************************************/
int
Open(const char *pathname, int oflag, mode_t mode)
{
  int fd;

  if( (fd = open(pathname, oflag, mode)) == -1)
    err_sys("open error for %s", pathname);

  return fd;
}

/******************************************************************************
*Function: Close
*Description: close a opened file, close wrapper
*Input: filedes(file descriptor)
*Output: none
*Return: none
*Date: 2015/7/7
******************************************************************************/
void
Close(int filedes)
{
  if(close(filedes) == -1)
    err_sys("close error");
}

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
*Description: write data to opened file, write wrapper
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
*Description: create a new process, fork wrapper
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
*Function: Waitpid
*Description: wait process, Waitpid wrapper
*Input: pid / options
*Output: statloc(save process's teminated status)
*Return: retpid
*Date: 2015/7/7
******************************************************************************/
pid_t
Waitpid(pid_t pid, int *statloc, int options)
{
  pid_t retpid;

  if( (retpid = waitpid(pid, statloc, options)) == -1)
    err_sys("waitpid error");

  return retpid;
}

/******************************************************************************
*Function: Pipe
*Description: create pipe, pipe wrapper
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
