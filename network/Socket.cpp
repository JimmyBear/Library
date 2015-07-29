#include "Socket.h"
#include <stdio.h>

namespace network
{
	Socket::Socket() :
		m_stSocket(INVALID_SOCKET),
		m_eSocketType(ST_UDP),
		m_eSocketMode(SM_BLOCKING)
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

	bool Socket::Create(Type eType, Mode eMode)
	{
		if (m_stSocket != INVALID_SOCKET)
			return false;

		m_stSocket = socket(AF_INET, eType, 0);

		if (m_stSocket == INVALID_SOCKET)
			return false;

		linger stLinger;
		stLinger.l_onoff = 1;
		stLinger.l_linger = 0;
		int iOptLen = sizeof(stLinger);
		int iCode = setsockopt(m_stSocket, SOL_SOCKET, SO_LINGER, reinterpret_cast<char *>(&stLinger), iOptLen);

		if (m_eSocketMode == SM_NONBLOCKING)
		{
			unsigned long nNonBlocking = 1;
			if (ioctlsocket(m_stSocket, FIONBIO, &nNonBlocking) == SOCKET_ERROR ||
				nNonBlocking == 0)
			{
				closesocket(m_stSocket);
				m_stSocket = INVALID_SOCKET;
				return false;
			}
		}

		m_eSocketType = eType;
		m_eSocketMode = eMode;

		return true;
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

	bool Socket::Bind(IPEndPoint cBindEp)
	{
		if (m_stSocket == INVALID_SOCKET)
			return false;

		sockaddr_in stSockAddrIn;
		stSockAddrIn.sin_addr.s_addr	=	htonl(cBindEp.GetBinary());
		stSockAddrIn.sin_family			=	cBindEp.GetFamily();
		stSockAddrIn.sin_port			=	htons(cBindEp.GetPort());

		if (bind(m_stSocket, reinterpret_cast<sockaddr*>(&stSockAddrIn), sizeof(stSockAddrIn)) == SOCKET_ERROR)
		{
			printf("%d\n", WSAGetLastError());
			return false;
		}

		return true;
	}

	bool Socket::Listen(int iBackLog)
	{
		if (m_stSocket == INVALID_SOCKET)
			return false;

		return listen(m_stSocket, iBackLog) != SOCKET_ERROR;
	}

	bool Socket::Connect(IPEndPoint cRemoteEp)
	{
		if (m_stSocket == INVALID_SOCKET)
			return false;

		sockaddr_in stSockAddrIn;
		stSockAddrIn.sin_addr.s_addr	=	htonl(cRemoteEp.GetBinary());
		stSockAddrIn.sin_family			=	cRemoteEp.GetFamily();
		stSockAddrIn.sin_port			=	htons(cRemoteEp.GetPort());

		if (connect(m_stSocket, reinterpret_cast<sockaddr*>(&stSockAddrIn), sizeof(stSockAddrIn)) == SOCKET_ERROR)
		{
			printf("%d\n", WSAGetLastError());
			return false;
		}

		return true;
	}

	bool Socket::Accept(Socket* pcRemoteSocket, IPEndPoint* pcRemoteEp)
	{
		if (m_stSocket == INVALID_SOCKET)
			return false;

		sockaddr_in stSockAddrFrom;
		int iLen = sizeof(stSockAddrFrom);
		pcRemoteSocket->m_stSocket = accept(m_stSocket, reinterpret_cast<sockaddr*>(&stSockAddrFrom), &iLen);

		if (pcRemoteSocket->m_stSocket == INVALID_SOCKET)
		{
			printf("%d\n", WSAGetLastError());
			return false;
		}

		if (stSockAddrFrom.sin_family != AF_INET)
			return false;

		pcRemoteEp->SetBinary(ntohl(stSockAddrFrom.sin_addr.s_addr));
		pcRemoteEp->SetPort(ntohs(stSockAddrFrom.sin_port));
		pcRemoteSocket->m_eSocketType = m_eSocketType;
		pcRemoteSocket->m_eSocketMode = m_eSocketMode;

		return true;
	}
};