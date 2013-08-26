#pragma once
#include "mstring.h"

#if ASSERTIONS_ENABLED
	void reportAssertion(const char *expression, const char *file, const long line);
	#ifdef _WIN32
	#define debugBreak() __asm { int 3}
	#else
	#define debugBreak()
	#endif
	#define ASSERT(expr) \
	if(expr) { } \
	else \
	{ \
	reportAssertion(#expr, __FILE__, __LINE__); \
		debugBreak(); \
	}
#else
#define ASSERT(expr)
#endif