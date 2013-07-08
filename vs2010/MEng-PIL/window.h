#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif



namespace MEng{
	class Window{
	public:
		Window();
		~Window();
		void setDimensions(int width, int height);
		void setFullscreen(bool fullscreen);
		bool create();
		void show();
		void showCursor(bool show);
		void pollEvents();
		bool shouldQuit();
		
	private:
		void changeFullscreen(bool full);
		unsigned long m_width;
		unsigned long m_height;
		bool m_fullscreen;
		bool m_quit;
		#ifdef _WIN32
		HWND m_handle;
		HINSTANCE m_hinstance;
		LPCWSTR m_appname;
		#endif
	};
	#ifdef _WIN32
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	#endif
}