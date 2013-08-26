#pragma once

#include <string>

namespace MEng{
	typedef struct _DateTime{
		int year;
		int day;
		int month;
		int hour;
		int minute;
		int second;
	} DateTime;

	DateTime GetDateTime();
	std::string GetDateString();
	std::string GetTimeString();
	std::string GetDateTimeString();
}