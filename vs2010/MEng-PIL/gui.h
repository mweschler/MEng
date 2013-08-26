#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif

#include "mstring.h"

namespace MEng{
	class Window;
	class GUI{
	public:
		GUI();
		~GUI();
		static void showMessageBox(String message, String title);
		static Window *createWindow(int width, int height, bool fullscreen);
		static bool initialize();
		static bool isInitialized();
		static void shutdown();
#ifdef _WIN32
		static LPCWSTR getAppName();
		static HINSTANCE getHInstance();
#endif
	private:
		static bool initialized;
#ifdef _WIN32
		static LPCWSTR m_appname;
		static HINSTANCE m_hinstance;
		
#endif
	};
}