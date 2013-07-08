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
		wchar_t msg_w[64], title_w[64];
		mbstowcs(msg_w, message, strlen(message) + 1);
		mbstowcs(title_w, title, strlen(title) + 1);

		MessageBox(NULL, msg_w, title_w, MB_OK);
		
		#endif
	}

	Window GUI::createWindow(int width, int height, bool fullscreen){
		Window window;
		window.setDimensions(width, height);
		window.setFullscreen(fullscreen);
		window.create();
		return window;
	}
}