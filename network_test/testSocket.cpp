
#include "gtest/gtest.h"
#include "Socket.h"

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

// The test case of creating and closing socket 
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