#include <string>
#include <sstream>
#include "assertions.h"
#include "gui.h"

void reportAssertion(const char *expression, const char *file, const long line){
	std::stringstream msgstream;
	msgstream <<"ASSERTION FAILURE!"<<std::endl<< "'"<<expression
		<<"' evaluated false."<<std::endl<<"File: "<<file<<" Line: "<<line;
	std::string message = msgstream.str();
	MEng::GUI::showMessageBox(message.c_str(), "Assertion Failure");
}