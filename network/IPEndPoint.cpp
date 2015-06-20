#include "IPEndPoint.h"

namespace network
{
	IPEndPoint::IPEndPoint() :
		m_uBinary(0),
		m_u16Family(0),
		m_u16Port(0)
	{
	}

	IPEndPoint::IPEndPoint(const char* szSockAddr, unsigned short u16Port) :
		m_u16Family(AF_INET)
	{
		SetAddress(szSockAddr);
		SetPort(u16Port);
	}

	void IPEndPoint::SetAddress(const char* szSockAddr)
	{
		m_uBinary = inet_addr(szSockAddr);
	}
	void IPEndPoint::SetPort(unsigned short u16Port)
	{
		m_u16Port = u16Port;
	}

	unsigned int IPEndPoint::GetBinary()
	{
		return m_uBinary;
	}

	unsigned short IPEndPoint::GetPort()
	{
		return m_u16Port;
	}
};