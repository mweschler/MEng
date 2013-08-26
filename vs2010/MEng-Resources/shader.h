#pragma once

#include <string>
#include <GL/glut.h>

namespace MEng{
	class Shader{
		
	public:
		Shader();
		~Shader();
		static enum Type {VERTEX_SHADER,
		FRAGMENT_SHADER} ;
		bool load(std::string filename, Shader::Type);
		bool compile();
		void use();
		void static unbind();
		void release();
		
	private:
		GLuint m_vertexShader;
		GLuint m_fragmentShader;
		GLuint m_program;
		bool m_vertexLoaded;
		bool m_fragmentLoaded;
		bool m_compiled;
	};
}