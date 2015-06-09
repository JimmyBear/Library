#include "StringOperation.h"
#include <string>

namespace utility
{
	void StrReverse(char* pszString)
	{
		char* pszStringEnd = pszString + strlen(pszString) - 1;

		char chTemp;
		while(pszString < pszStringEnd)
		{
			chTemp = *pszString;
			*pszString = *pszStringEnd;
			*pszStringEnd = chTemp;

			++pszString;
			--pszStringEnd;
		}
	}

	char* StrCopy(char* pszDst, const char* pszSrc)
	{
		char* pszResult = pszDst;
		while (*pszDst++ = *pszSrc++);
		return pszResult;
	}
};