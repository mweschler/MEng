#pragma once

#include <ostream>
#include <fstream>
#include "mstring.h"

#define LOG(exp) MEng::logger->log(exp);
#define DEBUG(exp) MEng::logger->debugLog(exp);

namespace MEng{
	class Logger{
	public:
		Logger();
		~Logger();
		bool Startup();
		bool Startup(const char* logfile);
		void Shutdown();
		void log(std::string message);
		void debugLog(std::string message);
		void setLogDebug(bool debug);
		void setClearLog(bool clear);
		void operator<<(const char *);
		void operator<<(std::string);
	private:
		void writeToLog(std::string message);
		std::string m_logFileName;
		std::ofstream m_logfile;
		bool m_initialized;
		bool m_logDebug;
		bool m_clearlog;
	};

	extern Logger *logger;
}