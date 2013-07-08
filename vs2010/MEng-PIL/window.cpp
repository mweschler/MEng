#include "window.h"
#include "assertions.h"

namespace MEng{

	Window::Window()
		:m_width(800)
		,m_height(600)
		,m_fullscreen(false)
		,m_quit(false)
	{
	
	}

	Window::~Window(){

	}

	void Window::setDimensions(int width, int height){
		ASSERT((width > 0) && (height > 0));
		this->m_width = width;
		this->m_height = height;
	}

	void Window::setFullscreen(bool fullscreen){
		this->m_fullscreen = fullscreen;
		if(fullscreen){
#ifdef _WIN32

#endif
		}
		else{
#ifdef _WIN32
#endif
		}
	}

	bool Window::create(){
#ifdef _WIN32
		m_hinstance = GetModuleHandle(NULL);
		m_appname = L"MEng";

		WNDCLASSEX winclass;
		winclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		winclass.lpfnWndProc = WndProc;
		winclass.cbClsExtra = 0;
		winclass.cbWndExtra = 0;
		winclass.hInstance = this->m_hinstance;
		winclass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		winclass.hIconSm = winclass.hIcon;
		winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		winclass.lpszMenuName = NULL;
		winclass.lpszClassName = this->m_appname;
		winclass.cbSize = sizeof(WNDCLASSEX);

		RegisterClassEx(&winclass);

		int posX = 0, posY = 0;
		DWORD style = WS_POPUP;
		if(this->m_fullscreen){
			DEVMODE screenSettings;

			memset(&screenSettings, 0, sizeof(screenSettings));
			screenSettings.dmSize = sizeof(screenSettings);
			screenSettings.dmPelsWidth = m_width;
			screenSettings.dmPelsHeight = m_height;
			screenSettings.dmBitsPerPel = 32;
			screenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN);

		} else{
			posX = (GetSystemMetrics(SM_CXSCREEN) - m_width) / 2;
			posY = (GetSystemMetrics(SM_CYSCREEN) - m_height) / 2;
			style = style | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ;
		}
		
		this->m_handle = CreateWindowEx(WS_EX_APPWINDOW, m_appname, m_appname,
			style, posX, posY, m_width, m_height, NULL, NULL, this->m_hinstance,NULL);

		if(m_handle == NULL)
			return false;

		return true;
#endif
		
	}

	void Window::show(){
#ifdef _WIN32
		ASSERT(m_handle != NULL);
		ShowWindow(m_handle, SW_SHOW);
		SetForegroundWindow(m_handle);
		SetFocus(m_handle);
#endif
	}

	void Window::showCursor(bool show){
#ifdef _WIN32
		ShowCursor(show);
#endif
	}

	void Window::changeFullscreen(bool full){
	
	}
	
	void Window::pollEvents(){
#ifdef _WIN32
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if(msg.message == WM_QUIT){
			this->m_quit = true;
		}
#endif
	}

	bool Window::shouldQuit(){
		return this->m_quit;
	}

#ifdef _WIN32
	LRESULT CALLBACK WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam){
		switch(umsg){
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_KEYDOWN:
		case WM_KEYUP:
		default:
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
#endif
}