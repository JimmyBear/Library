#ifndef __UTILITY_STRCONVERT_H
#define __UTILITY_STRCONVERT_H

#include <string>
#include <sstream>
namespace utility
{
	// std::string << std::wstring
	std::string& operator << (std::string& strOut, const std::wstring& wstrIn);

	// std::wstring >> std::string
	bool operator >> (const std::wstring& wstrIn, std::string& strOut);

	// std::wstring << std::string
	std::wstring& operator << (std::wstring& wstrOut, const std::string& strIn);

	// std::string >> std::wstring
	bool operator >> (const std::string& strIn, std::wstring& wcharOut);
};

#endif // __UTILITY_STRCONVERT_H