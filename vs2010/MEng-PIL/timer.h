#pragma once
#ifdef _WIN32
#include <Windows.h>
#endif

namespace MEng {
	class Timer{
	public:
		Timer();
		~Timer();
		void startTimer();
		double getElapsedTimeSec();
		double getElapsedTimeMS();
	private:
#ifdef _WIN32
		LARGE_INTEGER m_freq;
		LARGE_INTEGER m_startTime;
#endif
	};
}