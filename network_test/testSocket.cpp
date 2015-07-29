
#include "gtest/gtest.h"
#include "Socket.h"
#include <process.h>

//------------------------------------------------------------------------------------------

using namespace network;

class SocketTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		Socket::Startup();
	}

	virtual void TearDown()
	{
		Socket::Cleanup();
	}
private:
};

// The test case of creating and closing sockets
TEST_F(SocketTest, CreateClose)
{
	Socket cSocket;

	// UDP
	EXPECT_TRUE(cSocket.Create(Socket::ST_UDP));
	EXPECT_FALSE(cSocket.Create(Socket::ST_UDP));
	EXPECT_FALSE(cSocket.Create(Socket::ST_TCP));
	EXPECT_TRUE(cSocket.Close());
	EXPECT_FALSE(cSocket.Close());

	// TCP
	EXPECT_TRUE(cSocket.Create(Socket::ST_TCP));
	EXPECT_FALSE(cSocket.Create(Socket::ST_TCP));
	EXPECT_FALSE(cSocket.Create(Socket::ST_UDP));
	EXPECT_TRUE(cSocket.Close());
	EXPECT_FALSE(cSocket.Close());
}

// The test case of creating and closing non-blocking sockets
TEST_F(SocketTest, CreateClose_NonBlocking)
{
	Socket cSocket;

	// UDP
	EXPECT_TRUE(cSocket.Create(Socket::ST_UDP, Socket::SM_NONBLOCKING));
	EXPECT_FALSE(cSocket.Create(Socket::ST_UDP, Socket::SM_NONBLOCKING));
	EXPECT_FALSE(cSocket.Create(Socket::ST_TCP, Socket::SM_NONBLOCKING));
	EXPECT_TRUE(cSocket.Close());
	EXPECT_FALSE(cSocket.Close());

	// TCP
	EXPECT_TRUE(cSocket.Create(Socket::ST_TCP, Socket::SM_NONBLOCKING));
	EXPECT_FALSE(cSocket.Create(Socket::ST_TCP, Socket::SM_NONBLOCKING));
	EXPECT_FALSE(cSocket.Create(Socket::ST_UDP, Socket::SM_NONBLOCKING));
	EXPECT_TRUE(cSocket.Close());
	EXPECT_FALSE(cSocket.Close());
}

// The test case of binding sockets
TEST_F(SocketTest, Bind)
{
	Socket cSocket;
	IPEndPoint cIPEndPoint("127.0.0.1", 0);

	// UDP
	EXPECT_TRUE(cSocket.Create(Socket::ST_UDP));
	EXPECT_TRUE(cSocket.Bind(cIPEndPoint));
	EXPECT_TRUE(cSocket.Close());

	// TCP
	EXPECT_TRUE(cSocket.Create(Socket::ST_TCP));
	EXPECT_TRUE(cSocket.Bind(cIPEndPoint));
	EXPECT_TRUE(cSocket.Close());
}

// The test case of binding non-blocking sockets
TEST_F(SocketTest, Bind_NonBlocking)
{
	Socket cSocket;
	IPEndPoint cIPEndPoint("127.0.0.1", 0);

	// UDP
	EXPECT_TRUE(cSocket.Create(Socket::ST_UDP, Socket::SM_NONBLOCKING));
	EXPECT_TRUE(cSocket.Bind(cIPEndPoint));
	EXPECT_TRUE(cSocket.Close());

	// TCP
	EXPECT_TRUE(cSocket.Create(Socket::ST_TCP, Socket::SM_NONBLOCKING));
	EXPECT_TRUE(cSocket.Bind(cIPEndPoint));
	EXPECT_TRUE(cSocket.Close());
}

unsigned int __stdcall _ListenAndAcceptThreadMain(void* pArgs)
{
	Socket cClientSocket;
	IPEndPoint cServIPEndPoint("127.0.0.1", 5566);
	IPEndPoint cClientIPEndPoint("127.0.0.1", 5567);

	EXPECT_TRUE(cClientSocket.Create(Socket::ST_TCP));
	EXPECT_TRUE(cClientSocket.Bind(cClientIPEndPoint));
	EXPECT_TRUE(cClientSocket.Connect(cServIPEndPoint));
	EXPECT_TRUE(cClientSocket.Close());

	_endthreadex(0);
	return 0;
}

// The test case of listen and accepting tcp sockets
TEST_F(SocketTest, ListenAndAccept_Blocking)
{
	Socket cServSocket;
	IPEndPoint cServIPEndPoint("127.0.0.1", 5566);

	// Server socket create, bind, and listen
	EXPECT_TRUE(cServSocket.Create(Socket::ST_TCP));
	EXPECT_TRUE(cServSocket.Bind(cServIPEndPoint));
	EXPECT_TRUE(cServSocket.Listen(10));

	// Client socket create, bind, and connect at another thread
	unsigned int nTHreadID = 0;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, &_ListenAndAcceptThreadMain, NULL, 0, &nTHreadID);

	Socket cCleintSocket;
	IPEndPoint cClientIPEndPoint;

	EXPECT_TRUE(cServSocket.Accept(&cCleintSocket, &cClientIPEndPoint));
	EXPECT_EQ(0x7F000001, cClientIPEndPoint.GetBinary());
	EXPECT_EQ(5567, cClientIPEndPoint.GetPort());
	EXPECT_TRUE(cCleintSocket.Close());
	EXPECT_TRUE(cServSocket.Close());

	WaitForSingleObject(hThread, INFINITE);
}

