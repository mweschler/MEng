#ifdef _WIN32
#include <Windows.h>
#endif

#include "gui.h"
#include "window.h"

namespace MEng{
	GUI::GUI(){

	}

	GUI::~GUI(){

	}

	void GUI::showMessageBox(const char *message, const char *title){
		#ifdef _WIN32
		MessageBox(NULL, message, title, MB_OK);
		#endif
	}

	Window GUI::createWindow(int width, int height){
		Window window;
		return window;
	}
}