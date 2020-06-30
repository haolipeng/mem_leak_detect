#ifndef WAFLY_TOOLS_COMM_HELPER_H
#define WAFLY_TOOLS_COMM_HELPER_H
#include <stdio.h>

namespace WaflyTools
{
	/*static void OutputDebugStringExW(const wchar_t *strOutputString, ...)
	{
		va_list vlArgs = NULL;
		va_start(vlArgs, strOutputString);
		size_t nLen = _vscwprintf(strOutputString, vlArgs) + 1;
		wchar_t *strBuffer = new wchar_t[nLen];
		_vsnwprintf_s(strBuffer, nLen, nLen, strOutputString, vlArgs);
		va_end(vlArgs);
		OutputDebugStringW(strBuffer);
		delete[] strBuffer;
	}

	static void OutputDebugStringExA(const char *strOutputString, ...)
	{
		va_list vlArgs = NULL;
		va_start(vlArgs, strOutputString);
		size_t nLen = _vscprintf(strOutputString, vlArgs) + 1;
		char *strBuffer = new char[nLen];
		_vsnprintf_s(strBuffer, nLen, nLen, strOutputString, vlArgs);
		va_end(vlArgs);
		OutputDebugStringA(strBuffer);
		delete[] strBuffer;
	}*/

	class StringToken
	{
	public:
		StringToken(const char* str, const char* tok)
		{
			m_dupCount = 0;
			m_dupString = strdup(str);
			char* split = strtok(m_dupString, tok);
			while(split)
			{
				if(split[0] != '\0')
				{
					m_splitString[m_dupCount++] = split;
				}
				split = strtok(NULL, tok);
			}
		}

		~StringToken()
		{
			free(m_dupString);
		}

		const char* operator[](int i)
		{
			return (i < m_dupCount) ? m_splitString[i] : "";
		}

	private:
		int		m_dupCount;
		char*	m_dupString;
		char*	m_splitString[64];
	};
}

/*
#ifndef TRACE
#	ifndef UNICODE
#		define TRACE(...) OutputDebugStringExW(__VA_ARGS__)
#	else
#		define TRACE(...) OutputDebugStringExA(__VA_ARGS__)
#	endif
#endif

#define RvaAdjust(pDosHeader, raddr)\
	((raddr != NULL) ? ((PBYTE)pDosHeader) + raddr : NULL)
*/
#endif//WAFLY_TOOLS_COMM_HELPER_H