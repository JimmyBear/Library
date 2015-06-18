#include "StrPermutation.h"

namespace practice
{
	namespace recursive
	{
		void StrPermutation(char* pszString)
		{
			_StrPermutation("", pszString);
		}

		static void _StrPermutation(std::string strSoFar, std::string strRemain)
		{
			if (strRemain == "")
				printf("%s\n", strSoFar.c_str());
			else
			{
				for (unsigned int i = 0; i < strRemain.length(); i++)
					_StrPermutation(
										strSoFar + strRemain[i],
										strRemain.substr(0, i) + strRemain.substr(i+1)
									);
			}
		}
	}
};