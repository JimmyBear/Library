
#include "gtest/gtest.h"
#include "IPEndPoint.h"

//------------------------------------------------------------------------------------------

using namespace network;

// The test case of IPEndPoint 
TEST(IPEndPointTest, IPEndPoint)
{
	IPEndPoint cEp("255.255.255.255", 80);
	EXPECT_EQ(0xFFFFFFFF, cEp.GetBinary());
	EXPECT_EQ(80, cEp.GetPort());

	cEp.SetAddress("0.0.0.0");
	EXPECT_EQ(0, cEp.GetBinary());

	cEp.SetPort(443);
	EXPECT_EQ(443, cEp.GetPort());
}