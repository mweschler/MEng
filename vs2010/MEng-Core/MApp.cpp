#include <stdlib.h>
#include <iostream>
#include "MApp.h"
#include "window.h"
#include "gui.h"
#include "logger.h"
#include "timer.h"

namespace MEng{
	MApp *app = NULL;

	MApp::MApp()
		:m_initialized(false)
		,m_shouldQuit(false)
		,m_lastTime(0)
	{
		app = this;
		m_timer = new Timer();
	}

	MApp::~MApp(){
		delete m_timer;
		delete m_window;
	}

	bool MApp::Initialize(){
		logger->Startup();
		LOG("Application Initilization Started");
		if(!GUI::initialize()){
			return false;
		}
		LOG("GUI System initialized");

		m_window = GUI::createWindow(800, 600, false);
		LOG("Window created");
		m_initialized = true;
		LOG("Application Initilization Finished");
		return true;
	}

	int MApp::Run(int argc, char *argv[]){
		if(!m_initialized){
			return -1;
		}
		DEBUG("Showing window");
		m_window->show();
		m_timer->startTimer();
		m_lastTime = m_timer->getElapsedTimeMS();
		DEBUG("Starting game loop");
		while(!m_shouldQuit){
			m_window->pollEvents();

			if(m_window->shouldQuit())
				Quit();
			double time = m_timer->getElapsedTimeMS();
			double elapsed = time - m_lastTime;
			Update(elapsed);
			m_window->makeContextCurrent();
			Render(elapsed);
			m_lastTime = time;
		}
		DEBUG("closing window");
		
		Shutdown();

		return 0;
	}

	void MApp::Update(double time){

	}

	void MApp::Render(double time){
		m_window->swapBuffers();
	}

	void MApp::Quit(){
		LOG("Application Quit recieved");
		m_shouldQuit = true;
	}

	void MApp::Shutdown(){
		LOG("Shutdown started");
		m_window->close();
		GUI::shutdown();
		LOG("Shutdown finished");
	}
}