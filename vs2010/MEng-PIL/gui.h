#pragma once

namespace MEng{
	class Window;
	class GUI{
	public:
		GUI();
		~GUI();
		static void showMessageBox(const char *message, const char *title);
		static Window createWindow(int width, int height, bool fullscreen);
	private:
	};
}