#ifdef _WIN32
#include <Windows.h>
#endif
#include <sstream>

#include "datetime.h"


namespace MEng{
	DateTime GetDateTime(){
#ifdef _WIN32
		DateTime datetime;
		SYSTEMTIME systime;

		GetLocalTime(&systime);

		datetime.day = systime.wDay;
		datetime.month = systime.wMonth;
		datetime.year = systime.wYear;
		datetime.hour = systime.wHour;
		datetime.minute = systime.wMinute;
		datetime.second = systime.wSecond;

		return datetime;
#endif
	}

	std::string GetDateString(){
		DateTime datetime = GetDateTime();
		std::stringstream ss;
		ss<<datetime.month<<"/"<<datetime.day<<"/"<<datetime.year;
		return ss.str();
	}
	std::string GetTimeString(){
		DateTime datetime = GetDateTime();
		std::stringstream ss;

		if(datetime.hour < 10)
			ss<<"0";

		ss<<datetime.hour<<":";

		if(datetime.minute < 10)
			ss<<"0";

		ss<<datetime.minute<<":";
		
		if(datetime.second < 10)
			ss<<"0";

		ss<<datetime.second;

		return ss.str();
	}

	std::string GetDateTimeString(){
		std::stringstream ss;
		ss<<GetDateString()<<" "<<GetTimeString();

		return ss.str();
	}
}