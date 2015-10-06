#include "libunp.h"

/******************************************************************************
*Function: Pthread_create
*Description: pthread_create wrapper
*Input: attr(thread attribute) / func(thread main func) / arg(thread argument)
*Output: tid(thread id)
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_create(pthread_t *tid, const pthread_attr_t *attr,
  void * (*func)(void *), void *arg)
{
	int		n;

	if ( (n = pthread_create(tid, attr, func, arg)) == 0)
		return;
	errno = n;
	err_sys("pthread_create error");
}

/******************************************************************************
*Function: Pthread_join
*Description: pthread_join wrapper
*Input: tid(thread id)
*Output: status(thread status)
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_join(pthread_t tid, void **status)
{
	int		n;

	if ( (n = pthread_join(tid, status)) == 0)
		return;
	errno = n;
	err_sys("pthread_join error");
}

/******************************************************************************
*Function: Pthread_join
*Description: Pthread_detach wrapper
*Input: tid(thread id)
*Output: none
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_detach(pthread_t tid)
{
	int		n;

	if ( (n = pthread_detach(tid)) == 0)
		return;
	errno = n;
	err_sys("pthread_detach error");
}

/******************************************************************************
*Function: Pthread_mutex_init
*Description: pthread_mutex_init wrapper
*Input: attr(mutex attribute)
*Output: mptr(mutex)
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_mutex_init(pthread_mutex_t *mptr, pthread_mutexattr_t *attr)
{
	int		n;

	if ( (n = pthread_mutex_init(mptr, attr)) == 0)
		return;
	errno = n;
	err_sys("pthread_mutex_init error");
}

/******************************************************************************
*Function: Pthread_mutexattr_init
*Description: pthread_mutexattr_init wrapper
*Input: none
*Output: attr(mutex attribute)
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_mutexattr_init(pthread_mutexattr_t *attr)
{
	int		n;

	if ( (n = pthread_mutexattr_init(attr)) == 0)
		return;
	errno = n;
	err_sys("pthread_mutexattr_init error");
}

/******************************************************************************
*Function: Pthread_mutex_lock
*Description: pthread_mutex_lock wrapper
*Input: mptr(mutex)
*Output: none
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_mutex_lock(pthread_mutex_t *mptr)
{
	int		n;

	if ( (n = pthread_mutex_lock(mptr)) == 0)
		return;
	errno = n;
	err_sys("pthread_mutex_lock error");
}

/******************************************************************************
*Function: Pthread_mutex_unlock
*Description: pthread_mutex_unlock wrapper
*Input: mptr(mutex)
*Output: none
*Return: none
*Date: 2015/10/6
******************************************************************************/
void
Pthread_mutex_unlock(pthread_mutex_t *mptr)
{
	int		n;

	if ( (n = pthread_mutex_unlock(mptr)) == 0)
		return;
	errno = n;
	err_sys("pthread_mutex_unlock error");
}
