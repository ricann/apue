#include "libunp.h"


/******************************************************************************
*Function: Fgets
*Description： get a line from input, fgets wrapper
*Input: n(buffer size) / fp(file pointer)
*Output: buf(output buffer)
*Return: buf(buffer pointer)
*Date: 2015/7/7
******************************************************************************/
char *
Fgets(char *buf, int n, FILE *fp)
{
  char *rptr;

  if( (rptr = fgets(buf, n, fp)) == NULL && ferror(fp))
    err_sys("fgets error");

  return rptr;
}
