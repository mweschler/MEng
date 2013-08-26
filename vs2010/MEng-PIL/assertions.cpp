#include <string>
#include <sstream>
#include "assertions.h"
#include "gui.h"
#include "mstring.h"

void reportAssertion(const char *expression, const char *file, const long line){
	
	MEng::StringStream msgstream;
	msgstream <<"ASSERTION FAILURE!"<<std::endl<< "'"<<expression
		<<"' evaluated false."<<std::endl<<"File: "<<file<<" Line: "<<line;
	MEng::String message = msgstream.str();
	MEng::GUI::showMessageBox(message, TEXT("Assertion Failure"));
}