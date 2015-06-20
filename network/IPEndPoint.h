#ifndef __NETWORK_IPENDPOINT_H
#define __NETWORK_IPENDPOINT_H

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

namespace network
{
	// for IPv4 only
	class IPEndPoint
	{
	public:
		IPEndPoint();
		IPEndPoint(const char* szSockAddr, unsigned short u16Port);

		void SetAddress(const char* szSockAddr);
		void SetPort(unsigned short u16Port);

		unsigned int	GetBinary();
		unsigned short	GetPort();
	private:
		unsigned int	m_uBinary;
		unsigned short	m_u16Family;
		unsigned short	m_u16Port;
	};
};

#endif // __NETWORK_IPENDPOINT_H