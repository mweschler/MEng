#include "timer.h"
#include "assertions.h"

namespace MEng{
	Timer::Timer()
	{
#ifdef _WIN32
		m_startTime.QuadPart = 0;
		ASSERT(QueryPerformanceFrequency(&m_freq));
#endif
	}

	Timer::~Timer(){

	}

	void Timer::startTimer(){
#ifdef _WIN32
		ASSERT(QueryPerformanceCounter(&m_startTime));
#endif
	}

	double Timer::getElapsedTimeSec(){
#ifdef _WIN32
		LARGE_INTEGER current, elapsed;
		ASSERT(QueryPerformanceCounter(&current));
		elapsed.QuadPart = current.QuadPart - m_startTime.QuadPart;
		return ((double) elapsed.QuadPart / (double)m_freq.QuadPart);
#endif
	}

	double Timer::getElapsedTimeMS(){
		return getElapsedTimeSec() * 1000;
	}

}