#pragma once

namespace MEng{
	class Window{
	public:
		Window();
		~Window();
		void setDimensions(int width, int height);
	private:
		int m_width;
		int m_height;
	};

}