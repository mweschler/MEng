#pragma once

namespace MEng{
	class Window;
	class Timer;

	class MApp{
	public:
		MApp();
		~MApp();
		virtual bool Initialize();
		int Run(int argc, char* argv[]);
		virtual void Update(double time);
		virtual void Render(double time);
		void Quit();
		virtual void Shutdown();
	private:
		Window *m_window;
		Timer *m_timer;
		double m_lastTime;
		bool m_initialized;
		bool m_shouldQuit;
	};

	extern MApp *app;
}