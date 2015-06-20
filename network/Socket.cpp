#include "Socket.h"

namespace network
{
	Socket::Socket() :
		m_stSocket(INVALID_SOCKET)
	{
	}

	Socket::~Socket()
	{
		Close();
	}

	bool Socket::Startup()
	{
		WSADATA  stWSAData;
		if (WSAStartup(MAKEWORD(2, 2), &stWSAData) != 0)
		{
			WSACleanup();
			return false;
		}
		return true;
	}

	bool Socket::Cleanup()
	{
		return WSACleanup() == 0;
	}

	bool Socket::Create(Type eType)
	{
		if (m_stSocket != INVALID_SOCKET)
			return false;

		m_stSocket = socket(AF_INET, eType, 0);
		return m_stSocket != INVALID_SOCKET;
	}

	bool Socket::Close()
	{
		if (m_stSocket == INVALID_SOCKET)
			return false;

		if (closesocket(m_stSocket) != 0)
			return false;

		m_stSocket = INVALID_SOCKET;
		return true;
	}
};