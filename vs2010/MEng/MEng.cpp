#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include "assertions.h"
#include "core.h"
#include "gui.h"
#include "window.h"
#include "filesystem.h"
#include "mstring.h"
#include "memalloc.h"
#include "logger.h"

#include "MGame.h"

int main (int argc, char *argv[]){
	MEng::MGame game;

	if(game.Initialize())
		return game.Run(argc, argv);

	LOG("Failed to initalize!");
	return -1;
	/*
	MEng::GUI::initialize();
	MEng::Window window = MEng::GUI::createWindow(800, 600, false);
	window.show();
	bool once = true;
	GLuint triangleBuff;
	
	
	MEng::Logger Logger;
	Logger.Startup();
	Logger<<"Message3";
	Logger.Shutdown();
	
	while(!window.shouldQuit()){
		window.pollEvents();

		if(once){
			const float triangle[] ={
				0.75f, 0.75f, 0.0f, 1.0f,
				0.75f, -0.75f, 0.0f, 1.0f,
				-0.75f, -0.75f, 0.0f, 1.0f,
			};

			glGenBuffers(1, &triangleBuff);
			glBindBuffer(GL_ARRAY_BUFFER, triangleBuff);
			glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			once = false;
		}

		//render
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindBuffer(GL_ARRAY_BUFFER, triangleBuff);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		window.swapBuffers();		
	}
	window.close();
	MEng::GUI::shutdown();
	return 0;
	*/
}