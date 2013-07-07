#include "window.h"
#include "assertions.h"

namespace MEng{

	Window::Window()
		:m_width(800)
		,m_height(600)
		,m_fullscreen(false)
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
		return true;
#endif
		
	}
}