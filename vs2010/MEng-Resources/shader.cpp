#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include "assertions.h"
#include "logger.h"
#include "shader.h"

namespace MEng{
	Shader::Shader()
		:m_vertexLoaded(false)
		,m_fragmentLoaded(false)
		,m_compiled(false)
	{

	}

	Shader::~Shader(){

	}

	bool Shader::load(std::string filename, Shader::Type type){
		ASSERT(filename.length > 0);

		std::ifstream file;
		std::stringstream stream;
		file.open(filename, std::ios::in);
		if(!file.is_open()){
			std::stringstream ss;
			ss<<"Could not open shader file "<<filename;
			LOG(ss.str());
			return false;
		}

		stream << file.rdbuf();

		std::string shadeString(stream.str());
		const char *data = shadeString.c_str();

		GLenum shadeType;
		switch(type){
		case VERTEX_SHADER:
			shadeType = GL_VERTEX_SHADER;
			break;
		case FRAGMENT_SHADER:
			shadeType = GL_FRAGMENT_SHADER;
			break;
		default:
			return false;
		}
		GLuint shader = glCreateShader(shadeType);
		glShaderSource(shader, 1, &data, NULL);

		glCompileShader(shader);

		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		if(status == GL_FALSE){
			GLint logLength;

			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

			GLchar *log = new GLchar[logLength + 1];

			glGetShaderInfoLog(shader, logLength, NULL, log);
			log[logLength] = '\0';

			std::stringstream ss;
			ss<<"Failed to compile shader "<<filename<<std::endl<<log;
			LOG(ss.str());

			delete[] log;
			glDeleteShader(shader);
			return false;
		}

		switch(type){
		case VERTEX_SHADER:
			m_vertexShader = shader;
			m_vertexLoaded = true;
			break;
		case FRAGMENT_SHADER:
			m_fragmentShader = shader;
			m_fragmentLoaded = true;
			break;
		}
		return true;
	}

	bool Shader::compile(){
		if(!(m_vertexLoaded && m_fragmentLoaded) || m_compiled){
			return false;
		}

		GLuint program = glCreateProgram();
		glAttachShader(program, m_vertexShader);
		glAttachShader(program, m_fragmentShader);

		glLinkProgram(program);

		glDetachShader(program, m_vertexShader);
		glDetachShader(program, m_fragmentShader);

		GLint status;

		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if(status == GL_FALSE){
			GLint logLength;

			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

			GLchar *log = new GLchar[logLength + 1];

			glGetProgramInfoLog(program, logLength, NULL, log);
			log[logLength] = '\0';

			std::stringstream ss;
			ss<<"Failed to compile program"<<std::endl<<log;
			LOG(ss.str());

			delete[] log;
			
			glDeleteProgram(program);
			return false;
		}

		glDeleteShader(m_vertexShader);
		glDeleteShader(m_fragmentShader);

		m_vertexShader = 0;
		m_fragmentShader = 0;

		m_vertexLoaded = false;
		m_fragmentLoaded = false;

		m_program = program;
		m_compiled = true;

		return true;
	}

	void Shader::use(){
		ASSERT(compiled);
		glUseProgram(m_program);
	}

	void Shader::unbind(){
		glUseProgram(0);
	}

	void Shader::release(){
		unbind();
		std::stringstream ss;
		ss<<"Shader release -";
		if(m_compiled){
			glDeleteProgram(m_program);
			ss<<" Prog ID: "<<m_program;
			m_program = 0;
		}

		if(m_vertexLoaded){
			glDeleteShader(m_vertexShader);
			ss<<" Vert ID: "<<m_vertexShader;
			m_vertexShader = 0;
		}

		if(m_fragmentLoaded){
			glDeleteShader(m_fragmentShader);
			ss<<" Frag ID: "<<m_fragmentShader;
			m_fragmentShader = 0;
		}
		DEBUG(ss.str());
	}
}