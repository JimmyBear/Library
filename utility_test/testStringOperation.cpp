
#include "gtest/gtest.h"
#include "StringOperation.h"
 
using namespace utility;

//------------------------------------------------------------------------------------------


TEST(StringOperationTest, StrReverse)
{
	char szInput[] = "12345";

	StrReverse(szInput);
	EXPECT_STREQ(szInput, "54321");

	StrReverse(szInput);
	EXPECT_STREQ(szInput, "12345");
}

TEST(StringOperationTest, StrCopy)
{
	const char szInput[] = "12345";
	char szOutput[6] = "";
	StrCopy(szOutput, szInput);
	EXPECT_STREQ(szOutput, szInput);
}
