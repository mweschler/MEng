#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#endif

namespace MEng{
	class Window{
	public:
		Window();
		~Window();
		void setDimensions(int width, int height);
		void setFullscreen(bool fullscreen);
		bool create();
	private:
		int m_width;
		int m_height;
		bool m_fullscreen;
		#ifdef _WIN32
		HWND m_handle;
		HINSTANCE m_hinstance;
		LPCWSTR m_appname;
		#endif
	};

}