
#include "gtest/gtest.h"
#include "StrConvert.h"
 
using namespace utility;


//------------------------------------------------------------------------------------------

// The test case of converting wide string to string
TEST(StrConvertTest, StrToWStr)
{
	std::string str1;
	str1 << L"WStr";
	EXPECT_STREQ(str1.c_str(), "WStr");
}

// The test case of converting string to wide string
TEST(StrConvertTest, WStrToStr)
{
	std::wstring wstr1;
	wstr1 << "Str";
	EXPECT_STREQ(wstr1.c_str(), L"Str");
}

// The test case of converting int to string
TEST(StrConvertTest, IntToStr)
{
	std::string str1;
	str1 << -100;
	EXPECT_STREQ(str1.c_str(), "-100");
}
