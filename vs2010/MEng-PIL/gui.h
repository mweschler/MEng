#pragma once

namespace MEng{
	class Window;
	class GUI{
	public:
		GUI();
		~GUI();
		static void showMessageBox(const char *message, const char *title);
		Window createWindow(int width, int height);
	private:
	};
}