#include "libunp.h"

#include <stdarg.h> //ANSI C head file
#include <syslog.h> //for syslog()

int daemon_proc;    //set nonzero by daemon_init()

static void err_doit(int, int, const char *, va_list);

/******************************************************************************
*Function: err_doit
*Description: print message and return to caller.
* caller specifies "errnoflag" and "level"
*Input: errnoflag(whether print errno info) / level(log level)
* fmt(format string) / ap(variable argument)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
static void
err_doit(int errnoflag, int level, const char *fmt, va_list ap)
{
  int errno_save, n;
  char buf[MAXLINE];

  errno_save = errno;
  vsnprintf(buf, MAXLINE, fmt, ap);
  n = strlen(buf);
  if(errnoflag)
    snprintf(buf+n, MAXLINE-n, ": %s", strerror(errno_save));
  strcat(buf, "\n");

  if(daemon_proc) {
    syslog(level, buf);
  } else {
    fflush(stdout);   //in case stdout and stderr are the same
    fputs(buf, stderr);
    fflush(stderr);
  }

  return;
}

/******************************************************************************
*Function: err_ret
*Description: Nonfatal error related to system call,
* print message and return
*Input: fmt(format string)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
void
err_ret(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, LOG_INFO, fmt, ap);
  va_end(ap);

  return;
}

/******************************************************************************
*Function: err_sys
*Description: Fatal error related to system call,
* print message and terminate
*Input: fmt(format string)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
void
err_sys(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, LOG_ERR, fmt, ap);
  va_end(ap);

  exit(1);
}

/******************************************************************************
*Function: err_dump
*Description: Fatal error related to system call,
* print message, dump core, and terminate
*Input: fmt(format string)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
void
err_dump(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, LOG_ERR, fmt, ap);
  va_end(ap);
  abort();    //dump core and terminate
  exit(1);    //shouldn't get here
}

/******************************************************************************
*Function: err_msg
*Description: Nonfatal error unrelated to system call,
* print message and return
*Input: fmt(format string)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
void
err_msg(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, LOG_INFO, fmt, ap);
  va_end(ap);

  return;
}

/******************************************************************************
*Function: err_quit
*Description: Nonfatal error unrelated to system call,
* print message and terminate
*Input: fmt(format string)
*Output: none
*Return: none
*Date: 2015/6/2
******************************************************************************/
void
err_quit(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, LOG_ERR, fmt, ap);
  va_end(ap);

  exit(1);
}
