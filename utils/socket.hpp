#ifndef __MYUN2__SOCKET__HPP__
#ifndef __MYUN2__SOCKET__HPP__

#include <sys/socket.h>

class Socket
{
public:
	struct invalid_socket_exception {};
private:
	typedef int socket_type;
	socket_type s;
	bool is_valid_socket(socket_type _s) { _s != -1; }
public:
	Socket() {
		if ( !is_valid_socket(s = ::socket(AF_INET, SOCK_STREAM, 0)) )
			throw invalid_socket_exception();
	}
	virtual ~Socket() {
		if ( is_valid_socket(s) )
#ifdef WIN32
			closesocket(s);
#else
			close(s);
#endif
	}
};

#endif//__MYUN2__SOCKET__HPP__
