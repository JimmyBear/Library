#include "StrConvert.h"
#include "windows.h"

namespace utility
{
	// std::string << std::wstring
	std::string& operator << (std::string& strOut, const std::wstring& wstrIn)
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, wstrIn.c_str(), -1, NULL, 0, NULL, false);
		char* pszBuf = new char[iLen];
		WideCharToMultiByte(CP_ACP, 0, wstrIn.c_str(), -1, pszBuf, iLen, NULL, false);
		strOut += std::string(pszBuf);
		delete pszBuf;
		return strOut;
	}

	// std::wstring >> std::string
	bool operator >> (const std::wstring& wstrIn, std::string& strOut)
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, wstrIn.c_str(), -1, NULL, 0, NULL, false);
		char* pszBuf = new char[iLen];
		WideCharToMultiByte(CP_ACP, 0, wstrIn.c_str(), -1, pszBuf, iLen, NULL, false);
		strOut += std::string(pszBuf);
		delete pszBuf;
		return true;
	}

	// std::wstring << std::string
	std::wstring& operator << (std::wstring& wstrOut, const std::string& strIn)
	{
		int iLen = MultiByteToWideChar(CP_ACP, 0, strIn.c_str(), -1, NULL, 0);
		wchar_t* pwszBuf = new wchar_t[iLen];
		MultiByteToWideChar(CP_ACP, 0, strIn.c_str(), -1, pwszBuf, iLen);
		wstrOut += std::wstring(pwszBuf);
		delete pwszBuf;
		return wstrOut;
	}

	// std::string >> std::wstring
	bool operator >> (const std::string& strIn, std::wstring& wstrOut)
	{
		int iLen = MultiByteToWideChar(CP_ACP, 0, strIn.c_str(), -1, NULL, 0);
		wchar_t* pwszBuf = new wchar_t[iLen];
		MultiByteToWideChar(CP_ACP, 0, strIn.c_str(), -1, pwszBuf, iLen);
		wstrOut += std::wstring(pwszBuf);
		delete pwszBuf;
		return true;
	}
};