#ifndef __NETWORK_SOCKET_H
#define __NETWORK_SOCKET_H

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include "IPEndPoint.h"

namespace network
{
	// for IPv4 only
	class Socket
	{
	public:
		enum Type
		{
			ST_UDP = SOCK_DGRAM,
			ST_TCP = SOCK_STREAM
		};

		enum Mode
		{
			SM_BLOCKING = 0,
			SM_NONBLOCKING
		};

		// for windows
		static bool Startup();
		static bool Cleanup();

		Socket();
		~Socket();

		bool	Create(Type eType, Mode eMode = SM_BLOCKING);
		bool	Close();

		bool	Bind(IPEndPoint cBindEp);
		bool	Listen(int iBackLog);
		bool	Connect(IPEndPoint cRemoteEp);
		bool	Accept(Socket* pcRemoteSocket, IPEndPoint* pcRemoteEp);

	private:
		SOCKET	m_stSocket;
		Type	m_eSocketType;
		Mode	m_eSocketMode;
	};
};

#endif // __NETWORK_IPENDPOINT_H