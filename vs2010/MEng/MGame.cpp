#include <iostream>
#include <GL/glew.h>
#include "mstring.h"
#include "MGame.h"
#include "filesystem.h"
#include "logger.h"
#include "shader.h"
#include "material.h"

namespace MEng{
	GLuint triangleBuff;
	Shader shader;
	Material material;

	MGame::MGame() : MApp(){
	}

	bool MGame::Initialize(){
		if(! MApp::Initialize())
			return false;

		logger->setLogDebug(true);

		std::wstring dir = MEng::Filesystem::getExecutableDir();
		std::wcout<<"Executable Dir: "<<dir<<std::endl;
		MEng::String currentDir = MEng::Filesystem::getCurrentDir();
		std::wcout<<"Working Dir: "<<currentDir<<std::endl;

		const float triangle[] ={
			0.75f, 0.75f, 0.0f, 1.0f,
			0.75f, -0.75f, 0.0f, 1.0f,
			-0.75f, -0.75f, 0.0f, 1.0f,
		};

		glGenBuffers(1, &triangleBuff);
		glBindBuffer(GL_ARRAY_BUFFER, triangleBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		if(triangleBuff == 0)
			std::cout<<"tb not init\n";

		if(!shader.load("basic.vert", Shader::VERTEX_SHADER)){
			LOG("Failed to load basic vert shader");
			return false;
		}

		if(!shader.load("basic.frag", Shader::FRAGMENT_SHADER)){
			LOG("Failde to load basic frag shader");
			return false;
		}
		if(!shader.compile()){
			LOG("Failed to comile program");
			return false;
		}

		material.setShader(&shader);

		return true;
	}

	void MGame::Update(double time){

		MApp::Update(time);
	}

	void MGame::Render(double time){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		material.use();
		glBindBuffer(GL_ARRAY_BUFFER, triangleBuff);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		material.unbind();
		MApp::Render(time);
	}

	void MGame::Shutdown(){
		shader.release();
		MApp::Shutdown();
	}
}