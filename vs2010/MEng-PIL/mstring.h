#pragma once
#include <string>

namespace MEng{
#ifdef UNICODE
	typedef std::wstring String;
	typedef std::wstringstream StringStream;
#else
	typedef std::string String;
	typedef std::stringStream StringStream;
#endif
}