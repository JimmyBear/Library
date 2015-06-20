#ifndef __NETWORK_SOCKET_H
#define __NETWORK_SOCKET_H

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

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

		// for windows
		static bool Startup();
		static bool Cleanup();

		Socket();
		~Socket();

		bool	Create(Type eType);
		bool	Close();

	private:
		SOCKET m_stSocket;
	};
};

#endif // __NETWORK_IPENDPOINT_H