#include <sstream>
#include <iostream>
#include "logger.h"
#include "assertions.h"
#include "datetime.h"

namespace MEng{
	Logger *logger = new Logger();

	Logger::Logger()
		:m_initialized(false)
		,m_logDebug(false)
		,m_clearlog(false)
	{

	}

	Logger::~Logger(){

	}

	bool Logger::Startup(){
		return Startup("log.txt");
	}

	bool Logger::Startup(const char *filename){
		m_logFileName = std::string(filename);

		if(m_clearlog)
			m_logfile.open(filename, std::ios::out);
		else
			m_logfile.open(filename, std::ios::out | std::ios::app);

		if(!m_logfile.is_open())
			return false;

		m_logfile << "--LOG START @ " <<"["<<GetDateTimeString()<<"]--"<<std::endl;
		m_logfile.close();
		m_initialized = true;
		return true;
	}

	void Logger::Shutdown(){
		m_logfile.open(m_logFileName, std::ios::out | std::ios::app);
		m_logfile << "--LOG END @ " <<"["<<GetDateTimeString()<<"]--"<<std::endl;
		
		m_logfile.close();

		m_initialized = false;
	}

	void Logger::log(std::string message){
		std::cout<<"[LOG "<<GetTimeString()<<"] "<<message<<std::endl;
		writeToLog(message);
	}

	void Logger::debugLog(std::string message){
		std::stringstream ss;
		ss<<"[DEBUG] "<<message;
		std::cout<<ss.str()<<std::endl;
		if(m_logDebug)
			writeToLog(ss.str());
	}

	void Logger::writeToLog(std::string message){
		ASSERT(m_initialized);
		m_logfile.open(m_logFileName, std::ios::out | std::ios::app);
		ASSERT(m_logfile.is_open());
		std::string datetime = GetDateTimeString();
		std::stringstream ss;
		ss<<"["<<datetime<<"] "<<message;
		m_logfile<< ss.str() <<std::endl;
		m_logfile.close();
	}

	void Logger::setLogDebug(bool debug){
		m_logDebug = debug;
	}

	void Logger::setClearLog(bool clear){
		m_clearlog = clear;
	}

	void Logger::operator<<(const char *msg){
		log(msg);
	}

	void Logger::operator<<(std::string msg){
		log(msg);
	}
}