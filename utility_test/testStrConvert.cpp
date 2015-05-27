
#include "gtest/gtest.h"
#include "StrConvert.h"
 
using namespace utility;


//------------------------------------------------------------------------------------------

// The test case of converting wide string to string
TEST(StrConvertTest, StrToWStr)
{
	std::string str1;
	str1 << L"WStr1";
	EXPECT_STREQ(str1.c_str(), "WStr1");

	std::string str2;
	L"WStr2" >> str2;
	EXPECT_STREQ(str2.c_str(), "WStr2");
}

// The test case of converting string to wide string
TEST(StrConvertTest, WStrToStr)
{
	std::wstring wstr1;
	wstr1 << "Str1";
	EXPECT_STREQ(wstr1.c_str(), L"Str1");

	std::wstring wstr2;
	"Str2" >> wstr2;
	EXPECT_STREQ(wstr2.c_str(), L"Str2");
}