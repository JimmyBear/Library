
#include "gtest/gtest.h"
#include "StrConvert.h"
 
using namespace utility;


//------------------------------------------------------------------------------------------

TEST(StrConvertTest, StrToWStr)
{
	std::string str1;
	str1 << L"WStr1";
	ASSERT_STREQ(str1.c_str(), "WStr1");

	std::string str2;
	L"WStr2" >> str2;
	ASSERT_STREQ(str2.c_str(), "WStr2");
}

TEST(StrConvertTest, WStrToStr)
{
	std::string	str3;
	std::wstring wstr1;
	wstr1 << "Str1";
	str3 << wstr1;
	ASSERT_STREQ(str3.c_str(), "Str1");

	std::string	str4;
	std::wstring wstr2;
	"Str2" >> wstr2;
	wstr2 >> str4;
	ASSERT_STREQ(str4.c_str(), "Str2");
}