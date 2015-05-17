
#include "StrConvert.h"
 
using namespace utility;

int main()
{
	std::string strT1 = "Hi";
	std::wstring wstrT2 = L"Hi2";
	strT1 << wstrT2;
	printf("%s", strT1.c_str());
	system("pause");
}