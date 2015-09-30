#include "libunp.h"

/******************************************************************************
*Function: Socket
*Description: socket wrapper
*Input: family(socket family) / type(socket type) / protocol(socket protocol)
*Output: none
*Return: socket descriptor
*Date: 2015/9/29
******************************************************************************/
int
Socket(int family, int type, int protocol)
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0)
		err_sys("socket error");

	return n;
}

/******************************************************************************
*Function: Socket
*Description: socket wrapper
*Input: fd(socket fd) / sa(socket address) / salen(socket addr length)
*Output: none
*Return: none
*Date: 2015/9/29
******************************************************************************/
void
Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

/******************************************************************************
*Function: Listen
*Description: listen wrapper
*Input: fd(socket fd) / backlog(socket number allowed to queue)
*Output: none
*Return: none
*Date: 2015/9/30
******************************************************************************/
void
Listen(int fd, int backlog)
{
	char	*ptr;

	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		err_sys("listen error");
}

/******************************************************************************
*Function: Connect
*Description: connect wrapper
*Input: fd(socket fd) / sa(socket address) / salen(socket addr length)
*Output: none
*Return: none
*Date: 2015/9/30
******************************************************************************/
void
Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		err_sys("connect error");
}

/******************************************************************************
*Function: Sendto
*Description: sendto wrapper
*Input: fd(socket fd) / ptr(send buffer) / nbytes(bytes to send) /
* flags(sendto flags) / sa(dest address) / salen(addr length)
*Output: none
*Return: none
*Date: 2015/9/30
******************************************************************************/
void
Sendto(int fd, const void *ptr, size_t nbytes, int flags,
    const struct sockaddr *sa, socklen_t salen)
{
	if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
		err_sys("sendto error");
}

/******************************************************************************
*Function: Recvfrom
*Description: recvfrom wrapper
*Input: fd(socket fd) / nbytes(buffer size) / flags(sendto flags)
*Output: ptr(receive buffer) / sa(dest address) / salen(addr length)
*Return: receive bytes
*Date: 2015/9/30
******************************************************************************/
ssize_t
Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
    struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t		n;

	if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0)
		err_sys("recvfrom error");
	return n;
}

/******************************************************************************
*Function: Setsockopt
*Description: setsockopt wrapper
*Input: fd(socket fd) / level(option code type) / optname(option name)
* optval(point to a variable to be set) / optlen(variable length)
*Output: none
*Return: none
*Date: 2015/9/30
******************************************************************************/
void
Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	if (setsockopt(fd, level, optname, optval, optlen) < 0)
		err_sys("setsockopt error");
}

/******************************************************************************
*Function: Getsockopt
*Description: getsockopt wrapper
*Input: fd(socket fd) / level(option code type) / optname(option name)
*Output: optval(point to a variable to get) / optlen(variable length)
*Return: none
*Date: 2015/9/30
******************************************************************************/
void
Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr)
{
	if (getsockopt(fd, level, optname, optval, optlenptr) < 0)
		err_sys("getsockopt error");
}
