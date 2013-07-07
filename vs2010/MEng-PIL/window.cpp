#include "window.h"
#include "assertions.h"

namespace MEng{

	Window::Window()
		:m_width(800)
		,m_height(600)
	{
	
	}

	Window::~Window(){

	}

	void Window::setDimensions(int width, int height){
		ASSERT((width > 0) && (height > 0));
		this->m_width = width;
		this->m_height = height;
	}
}