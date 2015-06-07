
#include "gtest/gtest.h"
#include "GCD.h"

//------------------------------------------------------------------------------------------
// GCD: GCD(54, 24) = GCD(24, 6), GCD is 6

// The test case of recursive GCD 
TEST(GCDTest, Recursive)
{
	using namespace utility::recursive;
	EXPECT_EQ(GCD(54, 0), 0);
	EXPECT_EQ(GCD(54, 24), 6);
	EXPECT_EQ(GCD(54, 54), 54);
}

// The test case of iterative GCD
TEST(GCDTest, Iterative)
{
	using namespace utility::iterative;
	EXPECT_EQ(GCD(54, 0), 0);
	EXPECT_EQ(GCD(54, 24), 6);
	EXPECT_EQ(GCD(54, 54), 54);
}