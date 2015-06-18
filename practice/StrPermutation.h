#ifndef __PRACTICE_STRPERMUTATION_H
#define __PRACTICE_STRPERMUTATION_H

#include <string>

namespace practice
{
	namespace recursive
	{
		void StrPermutation(char* szString);
		static void _StrPermutation(std::string strSoFar, std::string strRemain);
	}
};

#endif // __PRACTICE_STRPERMUTATION_H